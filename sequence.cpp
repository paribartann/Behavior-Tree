#include "sequence.h"
#include <iostream>
#include <string>



tree::SequenceNode::SequenceNode(std::string key, unsigned int num)
{
    //SelectorNode* temp = new SelectorNode; 
    this->key = key; 
    set_type(SEQUENCE);
    set_status(IDLE);
    set_num_children(num);
}

tree::ReturnStatus tree::SequenceNode::Tick()
{

    std::cout<<"Sequence Node ticked"<<std::endl;
    for (unsigned int i = 0; i < get_num_children(); i++)
    {
        if (child[i]->get_type() == tree::ACTION)
        {
            child_i_status_ = child[i]->Tick();
        }
        else
        {
            //this will take care of condition nodes and control nodes
            child_i_status_ = child[i]->Tick();

        }
            
    
        if (child_i_status_ == tree::SUCCESS)
        {
             set_status(child_i_status_);
            if (i != (get_num_children() - 1))
            {
                std::cout<<"do nothing"<<std::endl;
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
    //this takes care of runnning also
    return child_i_status_; 

}