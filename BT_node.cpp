#include <BT_node.h>
#include <string>


//constructor
BTree::BTreeNode::BTreeNode(std::string name) 
{
    // Initialization
    name_ = name;
    has_parent_ = false;
    //set_status(BT::IDLE); //what is the status initially?
}

//destructor
BTree::BTreeNode::~BTreeNode() {}

void BTree::BTreeNode::set_status(ReturnStatus new_status)
{
    // state_ update
    status_ = new_status;
}

//getting the status of the nodes
BTree::ReturnStatus BTree::BTreeNode::get_status()
{
    return status_;
}

void BTree::BTreeNode::set_name(std::string new_name)
{
    name_ = new_name;
}


//for name and type of the nodes
std::string BTree::BTreeNode::get_name()
{
    return name_;
}


BTree::NodeType BTree::BTreeNode::get_type()
{
    return type_;
}


//for parents
bool BTree::BTreeNode::has_parent()
{
    return has_parent_;
}

void BTree::BTreeNode::set_has_parent(bool value)
{
    has_parent_ = value;
}