#include "sequencestar.h"
#include <iostream>
#include <string>


tree::SequenceStarNode::SequenceStarNode()
{
    current_child_index_ = 0;
}


tree::ReturnStatus tree::SequenceStarNode::Tick()
{
    
    //std::cout<<root->child.size()<<std::endl;
    N_of_children_ = children_node.size();

    while (current_child_index_ < N_of_children_)
    {
        if (children_node[current_child_index_]->get_type() == tree::ACTION)
        {
             //because action needs have some other criteria this is different for now
            //until we figure out
            child_i_status_ = children_node[current_child_index_]->get_status();
            if(child_i_status_ == tree::IDLE)
            {
                child_i_status_ = children_node[current_child_index_]->Tick();
                //perform certain action - have to fix or map each name to its correspondent action
            }
        }
        // else if (children_node[current_child_index_]->get_type() == tree::CONDITION)
        // {
        //     child_i_status_ = children_node[current_child_index_]->Tick();
        //     //check certain condition - have to fix or map each name to its correspondent condition
        // }
        else
        {
            //this will take care of condition nodes and control nodes
            
            child_i_status_ = children_node[current_child_index_]->Tick();

            //this can be any other control nodes such as ANDM, ORM, OR, AND
            //need to make Tick() a pure virtual function in order to achieve this technique
        }
            
        

        if (child_i_status_ == tree::FAILURE ||  child_i_status_ == tree::SUCCESS)
        {
            // the child goes in idle if it has returned success or failure.
            children_node[current_child_index_]->set_status(tree::IDLE);
        }

        if (child_i_status_ != tree::SUCCESS)
        {
            if(child_i_status_ == tree::FAILURE)
            {
                current_child_index_ = 0;
            }

            set_status(child_i_status_);

            //this takes care of runnning also
            return child_i_status_;
        }
        else if (current_child_index_ != N_of_children_ - 1)
        {
            current_child_index_++;
        }
            //if the child returned success
        else
        {
            //if it is the last child
            if (child_i_status_ == tree::SUCCESS)
            {
                // if it the last child and it has returned success, reset the memory
                current_child_index_ = 0;
            }
            set_status(child_i_status_);
            return child_i_status_;
        }    
    }
        
}




