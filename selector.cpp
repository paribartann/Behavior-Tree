#include "selector.h"
#include <iostream>
#include <string>

tree::ReturnStatus tree::SelectorNode::Tick()
{
    
    //std::cout<<root->child.size()<<std::endl;
    N_of_children_ = children_node.size();

    for (unsigned int i = 0; i < N_of_children_; i++)
    {
        if (children_node[i]->get_type() == tree::ACTION)
        {
            child_i_status_ = children_node[i]->get_status();
            if(child_i_status_ == tree::IDLE)
            {
                child_i_status_ = children_node[i]->Tick();
                //perform certain action - have to fix or map each name to its correspondent action
            }
            else if (children_node[i]->get_type() == tree::CONDITION)
            {
                child_i_status_ = children_node[i]->Tick();
                //check certain condition - have to fix or map each name to its correspondent condition
            }
            else
            {
                child_i_status_ = children_node[i]->Tick();

                //this can be any other control nodes such as ANDM, ORM, OR, AND
                //need to make Tick() a pure virtual function in order to achieve this technique
            }
            
        }

        if (child_i_status_ != tree::FAILURE)
        {
            if(child_i_status_ == tree::SUCCESS)
            {
                children_node[i]->set_status(tree::IDLE); //after success, set it to normal or not used
                // If the  child status is not failure, halt the next children and return the status to your parent.
                //I think we need to add this logic
            }
            //this takes care of runnning also
            return child_i_status_; 
        }
        else
        {
            //if the child returned failure
            if (i == N_of_children_ - 1)
            {
                // If the  child status is failure, and it is the last child to be ticked,
                // then the sequence has failed.
                //set_status(BT::FAILURE);
                return tree::FAILURE;
            }
        }        
    }


}