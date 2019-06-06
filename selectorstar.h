#ifndef SELECTOR_STAR_NODE_H
#define SELECTOR_STAR_NODE_H

//#include "BT_node.h"
#include "tree.h"
#include <string>
#include <vector>

// using namespace tree;
// using namespace parsed;

namespace tree{

    class SelectorStarNode : public BT
    {
        private:
            unsigned int current_child_index_;
        public:
            SelectorStarNode();
            ReturnStatus Tick();
    };
}



#endif