/* taken help from geek foo geeks */


#ifndef NODE_H
#define NODE_H

#include <string> 
#include <vector>

// Represents a node of an n-ary tree 
namespace tree{

    enum NodeType{SELECTOR, SEQUENCE, SELECTORSTAR, SEQUENCESTAR, ACTION, CONDITION};
     enum ReturnStatus{RUNNING, SUCCESS, FAILURE, IDLE};

    class Node 
    { 
        private: 
            ReturnStatus status_;
            NodeType type_; 
            unsigned int N_of_children_;    

        public:
            Node();
            ~Node();
            std::vector<Node*>child; 
            std::string key; 
            
            NodeType get_type() { return type_;}
            void set_type(NodeType _type) {type_ = _type;}

            ReturnStatus get_status() { return status_;}
            void set_status(ReturnStatus _status) {status_ = _status; }

            unsigned int get_num_children() {return N_of_children_;}
            void set_num_children(unsigned int num) {N_of_children_ = num; }


            virtual ReturnStatus Tick() = 0;

            std::vector<Node*>children_node; 
            // Children states
            std::vector<ReturnStatus> children_states_;

            // Vector size
           
            
            // child i status. Used to rout the ticks
            ReturnStatus child_i_status_;
            // ******************************** //
            
    }; 

    
    void LevelOrderTraversal(Node* root);
}   


#endif
   
