#include "sequence.h"
#include <iostream>
#include <string>



tree::SequenceNode::SequenceNode(std::string key, unsigned int num)
{
    //SelectorNode* temp = new SelectorNode; 
    this->key = key; 
    set_type(SEQUENCE);
    set_num_children(num);
}

tree::ReturnStatus tree::SequenceNode::Tick()
{

    std::cout<<"Sequence Node ticked"<<std::endl;
    for (unsigned int i = 0; i < get_num_children(); i++)
    {
        if (child[i]->get_type() == tree::ACTION || child[i]->get_type() == tree::CONDITION)
        {
            child_i_status_ = child[i]->Tick();
        }
        else
        {
            //this will take care of control nodes
            child_i_status_ = child[i]->Tick();
        }
            
        //now checking the returned status of the children nodes
        if (child_i_status_ == tree::SUCCESS)// || child_i_status_ == tree::RUNNING)
        {
             set_status(child_i_status_);
            if (i == (get_num_children() - 1))
            {
                return tree::SUCCESS;
            }
            else
            {
                std::cout<<"One child returned success. Going for other one"<<std::endl;
            }
        }
        else
        {
            return child_i_status_;
        }      
    }
    return child_i_status_;
}