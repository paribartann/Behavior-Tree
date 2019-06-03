#ifndef BT_NODE_H
#define BT_NODE_H

#include <iostream>
#include <unistd.h>

#include <string>
#include <vector>

namespace BTree
{
    enum NodeType{ACTION_NODE, CONDITION_NODE, CONTROL_NODE};
    enum Nodes{SELECTOR, SEQUENCE, SELECTORSTAR, SEQUENCESTAR, ACTION, CONDITION};
    enum ReturnStatus{RUNNING, SUCCESS, FAILURE, IDLE, HALTED, EXIT};


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


            //made public for the base classes
            // Children vector
            std::vector<BTreeNode*> children_nodes_;

            // Children states
            std::vector<ReturnStatus> children_states_;

            // Vector size
            unsigned int N_of_children_;
            // child i status. Used to rout the ticks
            ReturnStatus child_i_status_;

    };
}

#endif