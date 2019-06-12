#include "condition.h"
#include "pseudoDomain.h"
#include <iostream>
#include <string>



tree::ConditionNode::ConditionNode(std::string key)
{
    //SelectorNode* temp = new SelectorNode; 
    this->key = key; 
    set_type(CONDITION);
}


tree::ReturnStatus tree::ConditionNode::Tick()
{
    std::cout<<"Condition Node Ticked"<<std::endl;
    
    tree::pseudoDomain pd;

    return pd.call_condition(this->key);
}