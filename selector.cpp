#include <Selector_node.h>
#include <string>

BT::SelectorNode::SelectorNode(std::string name) : ControlNode::ControlNode(name) {}

BT::SelectorNode::~SelectorNode() {}

BT::ReturnStatus BT::SelectorNode::Tick()
{
    {
        // To get the number of children
        N_of_children_ = children_nodes_.size();

        // Routing the ticks basedon Selector node's logic:

        for (unsigned int i = 0; i < N_of_children_; i++)
        {
           
            if (children_nodes_[i]->get_type() == BT::ACTION_NODE)
            {
                // If the child i is an action, read its state.
                child_i_status_ = children_nodes_[i]->get_status();

                if (child_i_status_ == BT::IDLE )
                {
                    // 1.1) If the action status is not running, the sequence node sends a tick to it.
                    DEBUG_STDOUT(get_name() << "NEEDS TO TICK " << children_nodes_[i]->get_name());
                    children_nodes_[i]->tick_engine.Tick();

                    // waits for the tick to arrive to the child
                    do
                    {
                        child_i_status_ = children_nodes_[i]->get_status();
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
                child_i_status_ = children_nodes_[i]->Tick();
            }
            // Ponderate on which status to send to the parent
            if (child_i_status_ != BT::FAILURE)
            {
                if (child_i_status_ == BT::SUCCESS)
                {
                    children_nodes_[i]->set_status(BT::IDLE);  // the child goes in idle if it has returned success.
                }
            }
            else
            {
                // If the child return failure..
                children_nodes_[i]->set_status(BT::IDLE);
                if (i == N_of_children_ - 1)
                {
                    // If the  child status is failure, and it is the last child to be ticked,
                    // then the sequence has failed.
                    set_status(BT::FAILURE);
                    return BT::FAILURE;
                }
            }
        }
    }
    return BT::EXIT;
}
