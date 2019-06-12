#include "selector.h"
#include <iostream>
#include <string>



tree::SelectorNode::SelectorNode(std::string key, unsigned int num)
{
    //SelectorNode* temp = new SelectorNode; 
    this->key = key; 
    set_type(SELECTOR);
    set_num_children(num);
}


tree::ReturnStatus tree::SelectorNode::Tick()
{
    std::cout<<"Selector Node ticked"<<std::endl;
    for (unsigned int i = 0; i < get_num_children(); i++)
    {
        if (child[i]->get_type() == tree::ACTION || child[i]->get_type() == tree::CONDITION)
        {
                child_i_status_ = child[i]->Tick();
        }
        else
        {
            child_i_status_ = child[i]->Tick();
        }

        //now checking the returned status of the children nodes    
        if (child_i_status_ == tree::FAILURE)
        {
             set_status(child_i_status_);
            if (i == (get_num_children() - 1))
            {
                return tree::FAILURE;
            }
            else
            {
                std::cout<<"One child returned failure. Going for other one"<<std::endl;
            }
        }
        else
        {
            return child_i_status_;
        }
    }
    return child_i_status_; 
}