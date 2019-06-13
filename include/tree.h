/* 
#Copyright (C) <June, 2019>  <Paribartan Dhakal>

#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU Affero General Public License as
#published by the Free Software Foundation, either version 3 of the
#License, or (at your option) any later version.


#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU Affero General Public License for more details.
*/


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