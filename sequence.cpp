
#include <sequence.h>
#include <string>


BTree::SequenceNode::SequenceNode(std::string name) : BTree::BTreeNode(name) {}

BTree::SequenceNode::~SequenceNode() {}

BTree::ReturnStatus BTree::SequenceNode::Tick()
{
    // gets the number of children. The number could change if, at runtime, one edits the tree.
    N_of_children_ = children_nodes_.size();

    // Routing the ticks according to the sequence node's logic:

    for (unsigned int i = 0; i < N_of_children_; i++)
    {
        /*      Ticking an action is different from ticking a condition. An action executed some portion of code in another thread.
                We want this thread detached so we can cancel its execution (when the action no longer receive ticks).
                Hence we cannot just call the method Tick() from the action as doing so will block the execution of the tree.
                For this reason if a child of this node is an action, then we send the tick using the tick engine. Otherwise we call the method Tick() and wait for the response.
        */
        if (children_nodes_[i]->get_type() == BTree::ACTION_NODE)
        {
            // 1) If the child i is an action, read its state.
            child_i_status_ = children_nodes_[i]->get_status();

            //if (child_i_status_ == BTree::IDLE || child_i_status_ == BTree::HALTED)
            //{   ********** what is this *********** ???
                // 1.1) If the action status is not running, the sequence node sends a tick to it.
                children_nodes_[i]->Tick();

                // waits for the tick to arrive to the child
                do
                {
                    child_i_status_ = children_nodes_[i]->get_status();
                    //std::this_thread::sleep_for(std::chrono::milliseconds(10));
                }
                while (child_i_status_ != BTree::RUNNING && child_i_status_ != BTree::SUCCESS
                       && child_i_status_ != BTree::FAILURE);
            //}
        }
        else
        {
            // 2) if it's not an action:
            // Send the tick and wait for the response;
            child_i_status_ = children_nodes_[i]->Tick();
        }
        // Ponderate on which status to send to the parent
        if (child_i_status_ != BTree::SUCCESS)
        {
            // If the  child status is not success, halt the next children and return the status to your parent.
            if (child_i_status_ == BTree::FAILURE)
            {
                children_nodes_[i]->set_status(BTree::IDLE);  // the child goes in idle if it has returned failure.
            }

            // DEBUG_STDOUT(get_name() << " is HALTING children from " << (i+1));
            // HaltChildren(i+1);
            set_status(child_i_status_);
            return child_i_status_;
        }
        else
        {
            // the child returned success.
            children_nodes_[i]->set_status(BTree::IDLE);

            if (i == N_of_children_ - 1)
            {
                // If the  child status is success, and it is the last child to be ticked,
                // then the sequence has succeeded.
                set_status(BTree::SUCCESS);
                return BTree::SUCCESS;
            }
        }
    }
    return BTree::EXIT;
}