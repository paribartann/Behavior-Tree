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
            
    
        if (child_i_status_ != tree::SUCCESS)
        {
            if(child_i_status_ == tree::FAILURE)
            {
                child[i]->set_status(tree::IDLE); //after failure, set it to normal or not used
            }
            
            set_status(child_i_status_);
            break;
        }
        else
        {
            //if the child returned success
            if (i == (get_num_children() - 1))
            {
                // If the  child status is failure, and it is the last child to be ticked,
                // then the sequence has failed.
                set_status(tree::SUCCESS);
            }
        }        
    }
    //this takes care of runnning also
    return child_i_status_; 

}