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

             //because action needs have some other criteria this is different for now
            //until we figure out
            child_i_status_ = child[i]->get_status();
            std::cout<<child_i_status_<<std::endl;
            if(child_i_status_ == tree::IDLE)
            {
                std::cout<<"Ticking Action"<<std::endl;
                child_i_status_ = child[i]->Tick();
                //perform certain action - have to fix or map each name to its correspondent action
            }
        }
        else
        {
            child_i_status_ = child[i]->Tick();


        }
            
    
        if (child_i_status_ != tree::FAILURE)
        {
            if(child_i_status_ == tree::SUCCESS)
            {
                child[i]->set_status(tree::IDLE); //after success, set it to normal or not used
                // If the  child status is not failure, halt the next children and return the status to your parent.
                //I think we need to add this logic
            }
            
            
        }
        else
        {
            //if the child returned failure
            if (i == (get_num_children() - 1))
            {
                // If the  child status is failure, and it is the last child to be ticked,
                // then the sequence has failed.
                set_status(tree::FAILURE);
                
            }
        }        
    }
    //this takes care of runnning also
    return child_i_status_; 
}