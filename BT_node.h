#ifndef BT_NODE_H
#define BT_NODE_H

#include <iostream>
#include <unistd.h>

#include <string>

namespace BTree
{
    enum NodeType{ACTION_NODE, CONDITION_NODE, CONTROL_NODE};
    enum Nodes{SELECTOR, SEQUENCE, SELECTORSTAR, SEQUENCESTAR, ACTION, CONDITION};
    enum ReturnStatus{RUNNING, SUCCESS, FAILURE};


    class BTreeNode
    {
        private:
            std::string name_;
            bool has_parent_;

        public:
            ReturnStatus status_;
            NodeType type_;
            explicit BTreeNode(std::string name);   //Specifies that a constructor or conversion function
                                                    // (since C++11) is explicit, that is, it cannot be used
                                                    // for implicit conversions and copy-initialization.
            ~BTreeNode();
            virtual BTree::ReturnStatus Tick() = 0; //this has to be implemented by every inherited class

            //might not need this
            void SetNodeState(ReturnStatus new_state);


            //other utility functions
            ReturnStatus get_status();
            void set_status(ReturnStatus new_status);


            std::string get_name();
            void set_name(std::string new_name);

            NodeType get_type();
            bool has_parent();
            void set_has_parent(bool value);

    };
}

#endif