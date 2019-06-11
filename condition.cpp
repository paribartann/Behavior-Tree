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
    return tree::SUCCESS; 
}