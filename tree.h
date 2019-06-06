#include <string>
#include <vector>
#include "node.h"

namespace tree
{
    enum NodeType{SELECTOR, SEQUENCE, SELECTORSTAR, SEQUENCESTAR, ACTION, CONDITION};
    enum ReturnStatus{RUNNING, SUCCESS, FAILURE};
    
    class BT {
        public:
            BT();   //constructor
            Node* buildBT(const std::string&);
            void execute(Node*, int);

            // ReturnStatus status_;
            // NodeType type_;

            //int number_of_children(Node*);
            //utility functions
            std::string getBehavior(int);
            std::string getType(std::string);
            int getNumberOfChildren(int);
            int getDepth(int);

            //recursive function to build a tree
            void buildTree(int, int, Node*, int);

            ReturnStatus status_;
            NodeType type_;

            //virtual ReturnStatus Tick() = 0;

            std::vector<Node*>children_node; 
            // Children states
            std::vector<ReturnStatus> children_states_;

            // Vector size
            unsigned int N_of_children_;
            
            // child i status. Used to rout the ticks
            ReturnStatus child_i_status_;
            // ******************************** //
            
        private:

            //*********** This is required for building a tree ************// 
            std::vector<std::string> result; 
            std::vector < std::vector<std::string> > splittedBySpace;
            std::vector<std::string> splitWord;
            std::vector<int> alreadyParsed;
            //*********** This is required for building a tree ************// 

    };
}