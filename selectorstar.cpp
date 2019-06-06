#include "selectorstar.h"
#include <iostream>
#include <string>




tree::SelectorStarNode::SelectorStarNode()
{
    current_child_index_ = 0;
}


tree::ReturnStatus tree::SelectorStarNode::Tick()
{
    
    //std::cout<<root->child.size()<<std::endl;
    N_of_children_ = children_node.size();

    while (current_child_index_ < N_of_children_)
    {
        if (children_node[current_child_index_]->get_type() == tree::ACTION)
        {
            child_i_status_ = children_node[current_child_index_]->get_status();
            if(child_i_status_ == tree::IDLE)
            {
                child_i_status_ = children_node[current_child_index_]->Tick();
                //perform certain action - have to fix or map each name to its correspondent action
            }
            else if (children_node[current_child_index_]->get_type() == tree::CONDITION)
            {
                child_i_status_ = children_node[current_child_index_]->Tick();
                //check certain condition - have to fix or map each name to its correspondent condition
            }
            else
            {
                child_i_status_ = children_node[current_child_index_]->Tick();

                //this can be any other control nodes such as ANDM, ORM, OR, AND
                //need to make Tick() a pure virtual function in order to achieve this technique
            }
            
        }

        if (child_i_status_ != tree::FAILURE)
        {
            if(child_i_status_ == tree::SUCCESS)
            {
                current_child_index_ = 0;
            }

            set_status(child_i_status_);
            return child_i_status_;
        }
        else if (current_child_index_ != N_of_children_ - 1)
        {
            current_child_index_++;
        }
            //if the child returned failure
        else
        {
            //if it is the last child
            if (child_i_status_ == tree::FAILURE)
            {
                // if it the last child and it has returned failure, reset the memory
                current_child_index_ = 0;
            }
            set_status(child_i_status_);
            return child_i_status_;
        }    
    }
        
}




