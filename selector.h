#ifndef SELECTOR_NODE_H
#define SELECTOR_NODE_H

//#include "BT_node.h"
#include "tree.h"
#include <string>
#include <vector>

// using namespace tree;
// using namespace parsed;

namespace tree{

    class SelectorNode : public BT
    {
        public:
            ReturnStatus Tick();
    };
}



#endif