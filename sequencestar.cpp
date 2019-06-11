#include "sequencestar.h"
#include <iostream>
#include <string>


tree::SequenceStarNode::SequenceStarNode(std::string key, unsigned int num)
{
    current_child_index_ = 0;
    this->key = key; 
    set_type(SEQUENCESTAR);
    set_status(IDLE);
    set_num_children(num);

}

tree::ReturnStatus tree::SequenceStarNode::Tick()
{
    
    //std::cout<<root->child.size()<<std::endl;
    std::cout<<"SequenceStar Node ticked"<<std::endl;

    while (current_child_index_ < get_num_children())
    {
        if (child[current_child_index_]->get_type() == tree::ACTION)
        {
            
                std::cout<<"Ticking Action"<<std::endl;
                child_i_status_ = child[current_child_index_]->Tick();

        }
       
        else
        {
            //this will take care of condition nodes and control nodes
            
            child_i_status_ = child[current_child_index_]->Tick();

        }

        if (child_i_status_ == tree::SUCCESS)
        {
             set_status(child_i_status_);
            if (current_child_index_ != (get_num_children() - 1))
            {
                current_child_index_++;
            }
            else
            {
                return tree::SUCCESS;
            }
        }
        else
        {
            return child_i_status_;
        }
        
    }
    return child_i_status_;    
}




