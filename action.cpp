#include "action.h"
#include <iostream>
#include <string>



tree::ActionNode::ActionNode(std::string key)
{
    //SelectorNode* temp = new SelectorNode; 
    this->key = key; 
    set_type(ACTION);
    set_status(IDLE);
}


tree::ReturnStatus tree::ActionNode::Tick()
{
    // set_status(tree::RUNNING);

    std::cout<<"Action Node"<<std::endl;

    if (this->key == "GC")
    {
        std::cout<<"Performing action GC"<<std::endl;
        return tree::SUCCESS; 

    }
    else if (this->key == "DC")
    {
        std::cout<<"Performing action DC"<<std::endl;
        return tree::SUCCESS; 
    }
    else if (this->key == "GA")
    {
        std::cout<<"Performing action GA"<<std::endl;
        return tree::FAILURE; 
    }
    else 
    {
        std::cout<<"Performing action GB"<<std::endl;
        return tree::SUCCESS; 
    }

    //return tree::SUCCESS; 
}