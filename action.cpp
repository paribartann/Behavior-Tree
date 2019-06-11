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
        std::cout<<"GC"<<std::endl;
    }
    else if (this->key == "DC")
    {
        std::cout<<"DC"<<std::endl;
    }
    else if (this->key == "GA")
    {
        std::cout<<"GA"<<std::endl;
    }
    else 
    {
        std::cout<<"GB"<<std::endl;
    }

    return tree::SUCCESS; 
}