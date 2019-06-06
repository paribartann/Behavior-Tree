#ifndef SEQUENCE_STAR_NODE_H
#define SEQUENCE_STAR_NODE_H

//#include "BT_node.h"
#include "tree.h"
#include <string>
#include <vector>

// using namespace tree;
// using namespace parsed;

namespace tree{

    class SequenceStarNode : public BT
    {
        private:
            unsigned int current_child_index_;
        public:
            SequenceStarNode();
            ReturnStatus Tick();
    };
}



#endif