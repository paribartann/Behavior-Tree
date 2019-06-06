#include "selector.h"
#include <iostream>
#include <string>

tree::ReturnStatus tree::SelectorNode::Tick(Node* root)
{
    
   // Node* root = BT::buildBT("BT_Fig8");

    std::cout<<root->child.size()<<std::endl;

    child_i_status_ = SUCCESS;
    std::cout<<child_i_status_<<std::endl;

    return child_i_status_;
}