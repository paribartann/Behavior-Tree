#include "selectorstar.h"
#include <iostream>
#include <string>



tree::SelectorStarNode::SelectorStarNode(std::string key, unsigned int num)
{
    //SelectorNode* temp = new SelectorNode; 
    this->key = key; 
    current_child_index_ = 0;
    set_type(SELECTORSTAR);
    set_status(IDLE);
    set_num_children(num);
}


tree::ReturnStatus tree::SelectorStarNode::Tick()
{
    std::cout<<"SelectorStar Node ticked"<<std::endl;

    while (current_child_index_ < get_num_children())
    {
        if (child[current_child_index_]->get_type() == tree::ACTION)
        {
             
                child_i_status_ = child[current_child_index_]->Tick();

                std::cout<<"Selector's child status is"<<child_i_status_<<std::endl;
                //perform certain action - have to fix or map each name to its correspondent action
            //}
        }
       
        else
        {
            //this will take care of condition nodes and control nodes

            child_i_status_ = child[current_child_index_]->Tick();

             std::cout<<"Selector's child status is"<<child_i_status_<<std::endl;
        }

        if (child_i_status_ == tree::FAILURE)
        {
             set_status(child_i_status_);
            if (current_child_index_ != (get_num_children() - 1))
            {
                current_child_index_++;
            }
            else
            {
                return tree::FAILURE;
            }
        }
        else
        {
            return child_i_status_;
        }
            
        
        
    }
    //this takes care of runnning also
    return child_i_status_;
}




