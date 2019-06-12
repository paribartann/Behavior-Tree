#include "action.h"
#include "pseudoDomain.h"
#include <iostream>
#include <string>



tree::ActionNode::ActionNode(std::string key)
{
    this->key = key; 
    set_type(ACTION);
}


tree::ReturnStatus tree::ActionNode::Tick()
{
    std::cout<<"Action Node Ticked"<<std::endl;

    tree::pseudoDomain pd;

    return pd.call_function(this->key);

}