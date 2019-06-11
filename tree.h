#ifndef TREE_H
#define TREE_H

#include <string>
#include <vector>
#include "node.h"

#include "action.h"
#include "condition.h"
#include "selector.h"
#include "selectorstar.h"
#include "sequence.h"
#include "sequencestar.h"

namespace tree
{
    class BT : public Node{
        public:
            BT();   //constructor
            Node* buildBT(const std::string&);
            void execute(Node*, int);
            //********************************//

            std::string getBehavior(int);
           
            unsigned int getNumberOfChildren(int);
            int getDepth(int);

            //recursive function to build a tree
            void buildTree(int, int, Node*, int);

            
            ReturnStatus Tick();

            
            
        private:
            Node* root;
            Node* rootC;
            //*********** This is required for building a tree ************// 
            std::vector<std::string> result; 
            std::vector < std::vector<std::string> > splittedBySpace;
            std::vector<std::string> splitWord;
            std::vector<int> alreadyParsed;
            //*********** This is required for building a tree ************// 

    };
}

#endif