/* taken help from geek foo geeks */
#include <string> 
#include <vector>

   
// Represents a node of an n-ary tree 
namespace tree{
    class Node 
    { 
        public:
        std::string key; 
        std::vector<Node *>child; 
    }; 

    Node *newNode(std::string key); 
    void LevelOrderTraversal(Node * root);
}   

   
