#include "condition.h"
#include <iostream>
#include <string>



tree::ConditionNode::ConditionNode(std::string key)
{
    //SelectorNode* temp = new SelectorNode; 
    this->key = key; 
    set_type(CONDITION);
    
    set_status(IDLE);
}


tree::ReturnStatus tree::ConditionNode::Tick()
{
    std::cout<<"Condition Node"<<std::endl;
     if (this->key == "t")
    {
        std::cout<<"Checking condition t()"<<std::endl;
        return tree::FAILURE; 
    }
    else
    {
        std::cout<<"Checking condition tp()"<<std::endl;
         return tree::SUCCESS; 
    }
    
}