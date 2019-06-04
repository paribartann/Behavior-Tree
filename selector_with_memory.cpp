#include <Selector_node_with_memory.h>
#include <string>

BT::SelectorNodeWithMemory::SelectorNodeWithMemory(std::string name) : ControlNode::ControlNode(name)
{
    reset_policy_ = BT::ON_SUCCESS_OR_FAILURE;
    current_child_idx_ = 0;  // initialize the current running child
}


BT::SelectorNodeWithMemory::SelectorNodeWithMemory(std::string name, int reset_policy) : ControlNode::ControlNode(name)
{
    reset_policy_ = reset_policy;
    current_child_idx_ = 0;  // initialize the current running child
}


BT::SelectorNodeWithMemory::~SelectorNodeWithMemory() {}


BT::ReturnStatus BT::SelectorNodeWithMemory::Tick()
{
    DEBUG_STDOUT(get_name() << " ticked, memory counter: "<< current_child_idx_);

    // To get the number of children 
    N_of_children_ = children_nodes_.size();

    // Selector node's with memory logic:
    while (current_child_idx_ < N_of_children_)
    {
        if (children_nodes_[current_child_idx_]->get_type() == BT::ACTION_NODE)
        {
            // If the child i is an action, read its state.
            // Action nodes runs in another thread, hence you cannot retrieve the status just by executing it.

            child_i_status_ = children_nodes_[current_child_idx_]->get_status();
            DEBUG_STDOUT(get_name() << " It is an action " << children_nodes_[current_child_idx_]->get_name()
                         << " with status: " << child_i_status_);

            if (child_i_status_ == BT::IDLE )
            {
                // If the action status is not running, the sequence node sends a tick to it.
                DEBUG_STDOUT(get_name() << "NEEDS TO TICK " << children_nodes_[current_child_idx_]->get_name());
                children_nodes_[current_child_idx_]->tick_engine.Tick();

                // waits for the tick to arrive to the child
                do
                {
                    child_i_status_ = children_nodes_[current_child_idx_]->get_status();
                    std::this_thread::sleep_for(std::chrono::milliseconds(10));
                }
                while (child_i_status_ != BT::RUNNING && child_i_status_ != BT::SUCCESS
                      && child_i_status_ != BT::FAILURE);
            }
        }
        else
        {
            // if it's not an action:
            // Send the tick and wait for the response;
            child_i_status_ = children_nodes_[current_child_idx_]->Tick();
        }


        if (child_i_status_ == BT::SUCCESS ||child_i_status_ == BT::FAILURE )
        {
             // the child goes in idle if it has returned success or failure.
            children_nodes_[current_child_idx_]->set_status(BT::IDLE);
        }

        if (child_i_status_ != BT::FAILURE)
        {
            // If the  child status is not success, return the status
            DEBUG_STDOUT("the status of: " << get_name() << " becomes " << child_i_status_);
            if (child_i_status_ == BT::SUCCESS && (reset_policy_ == BT::ON_SUCCESS
                                                  || reset_policy_ == BT::ON_SUCCESS_OR_FAILURE))
            {
                current_child_idx_ = 0;
            }
            set_status(child_i_status_);
            return child_i_status_;
        }
        else if (current_child_idx_ != N_of_children_ - 1)
        {
            // If the  child status is failure, continue to the next child
            // (if any, hence if(current_child_ != N_of_children_ - 1) ) in the for loop (if any).
            current_child_idx_++;
        }
        else
        {
            // If it the last child.
            if (child_i_status_ == BT::FAILURE)
            {
                // if it the last child and it has returned failure, reset the memory
                current_child_idx_ = 0;
            }
            set_status(child_i_status_);
            return child_i_status_;
        }
    }
    return BT::EXIT;
}

