/* taken help from geek foo geeks */
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
            

        public: 
            Node();
            ~Node();
            std::vector<Node*>child; 
            std::string key; 
            
            NodeType get_type() { return type_;}
            void set_type(NodeType _type) {type_ = _type;}

            ReturnStatus get_status() { return status_;}
            void set_status(ReturnStatus _status) {status_ = _status; }

            ReturnStatus Tick();
            
            

    }; 

    Node* newNode(std::string key); 
    void LevelOrderTraversal(Node* root);
}   

   
