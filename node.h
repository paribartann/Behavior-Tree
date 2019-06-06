/* taken help from geek foo geeks */
#include <string> 
#include <vector>

// Represents a node of an n-ary tree 
namespace tree{
    

    class Node 
    { 
        public: 
            std::vector<Node*>child; 
            std::string key; 
            std::string type;

            //virtual ReturnStatus Tick() = 0;
            
            

    }; 

    Node* newNode(std::string key); 
    void LevelOrderTraversal(Node* root);
}   

   
