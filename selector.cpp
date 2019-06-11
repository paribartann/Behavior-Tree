#include "selector.h"
#include <iostream>
#include <string>



tree::SelectorNode::SelectorNode(std::string key, unsigned int num)
{
    //SelectorNode* temp = new SelectorNode; 
    this->key = key; 
    set_type(SELECTOR);
    set_status(IDLE);
    set_num_children(num);
}


tree::ReturnStatus tree::SelectorNode::Tick()
{
    
    std::cout<<"Selector Node ticked"<<std::endl;

    for (unsigned int i = 0; i < get_num_children(); i++)
    {
        
        if (child[i]->get_type() == tree::ACTION)
        {

                std::cout<<"Ticking Action"<<std::endl;
                child_i_status_ = child[i]->Tick();
            
        }
        else
        {
            child_i_status_ = child[i]->Tick();
        }
            
    
        if (child_i_status_ == tree::FAILURE)
        {
             set_status(child_i_status_);
            if (i != (get_num_children() - 1))
            {
                std::cout<<"do nothing"<<std::endl;
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