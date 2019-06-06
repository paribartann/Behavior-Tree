#ifndef BT_NODE_H
#define BT_NODE_H

#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include "tree.h"



namespace tree
{
    class BTreeNode : public Node
    { 
        public:
            
            BTreeNode();   //Specifies that a constructor or conversion function
                                                    // (since C++11) is explicit, that is, it cannot be used
                                                    // for implicit conversions and copy-initialization.
            ~BTreeNode();
            ReturnStatus Tick(); //this has to be implemented by every inherited class

             
    };
}

#endif