#include <sequence_with_memory.h>
#include <string>


BTree::SequenceNodeWithMemory::SequenceNodeWithMemory(std::string name) : BTreeNode::BTreeNode(name)
{
    //reset_policy_ = BTree::ON_SUCCESS_OR_FAILURE;
    current_child_idx_ = 0;  // initialize the current running child
}


BTree::SequenceNodeWithMemory::SequenceNodeWithMemory(std::string name, int reset_policy) : BTreeNode::BTreeNode(name)
{
    reset_policy_ = reset_policy;
    current_child_idx_ = 0;  // initialize the current running child
}


BTree::SequenceNodeWithMemory::~SequenceNodeWithMemory() {}


BTree::ReturnStatus BTree::SequenceNodeWithMemory::Tick()
{
    //DEBUG_STDOUT(get_name() << " ticked, memory counter: "<< current_child_idx_);

    // Vector size initialization. N_of_children_ could change at runtime if you edit the tree
    N_of_children_ = children_nodes_.size();

    // Routing the ticks according to the sequence node's (with memory) logic:
    while (current_child_idx_ < N_of_children_)
    {
        /*      Ticking an action is different from ticking a condition. An action executed some portion of code in another thread.
                We want this thread detached so we can cancel its execution (when the action no longer receive ticks).
                Hence we cannot just call the method Tick() from the action as doing so will block the execution of the tree.
                For this reason if a child of this node is an action, then we send the tick using the tick engine. Otherwise we call the method Tick() and wait for the response.
        */

        if (children_nodes_[current_child_idx_]->get_type() == BTree::ACTION_NODE)
        {
            // 1) If the child i is an action, read its state.
            // Action nodes runs in another thread, hence you cannot retrieve the status just by executing it.

            child_i_status_ = children_nodes_[current_child_idx_]->get_status();
            // DEBUG_STDOUT(get_name() << " It is an action " << children_nodes_[current_child_idx_]->get_name()
            //              << " with status: " << child_i_status_);

            if (child_i_status_ == BTree::IDLE || child_i_status_ == BTree::HALTED)
            {
                // 1.1) If the action status is not running, the sequence node sends a tick to it.
                //DEBUG_STDOUT(get_name() << "NEEDS TO TICK " << children_nodes_[current_child_idx_]->get_name());
                children_nodes_[current_child_idx_]->Tick();

                // waits for the tick to arrive to the child
                do
                {
                    child_i_status_ = children_nodes_[current_child_idx_]->get_status();
                    //std::this_thread::sleep_for(std::chrono::milliseconds(10));
                }
                while (child_i_status_ != BTree::RUNNING && child_i_status_ != BTree::SUCCESS
                       && child_i_status_ != BTree::FAILURE);
            }
        }
        else
        {
            // 2) if it's not an action:
            // Send the tick and wait for the response;
            child_i_status_ = children_nodes_[current_child_idx_]->Tick();
        }

        if (child_i_status_ == BTree::SUCCESS ||child_i_status_ == BTree::FAILURE )
        {
             // the child goes in idle if it has returned success or failure.
            children_nodes_[current_child_idx_]->set_status(BTree::IDLE);
        }

        if (child_i_status_ != BTree::SUCCESS)
        {
            // If the  child status is not success, return the status
           // DEBUG_STDOUT("the status of: " << get_name() << " becomes " << child_i_status_);
            if (child_i_status_ == BTree::FAILURE && (reset_policy_ == BTree::ON_FAILURE
                                                   || reset_policy_ == BTree::ON_SUCCESS_OR_FAILURE))
            {
                current_child_idx_ = 0;
            }
            set_status(child_i_status_);
            return child_i_status_;
        }
        else if (current_child_idx_ != N_of_children_ - 1)
        {
            // If the  child status is success, continue to the next child
            // (if any, hence if(current_child_ != N_of_children_ - 1) ) in the for loop (if any).
            current_child_idx_++;
        }
        else
        {
            // if it the last child.
            if (child_i_status_ == BTree::SUCCESS)
            {
                // if it the last child and it has returned SUCCESS, reset the memory
                current_child_idx_ = 0;
            }
            set_status(child_i_status_);
            return child_i_status_;
        }
    }
    return BTree::EXIT;
}


