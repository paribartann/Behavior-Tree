#ifndef SELECTOR_STAR_NODE_H
#define SELECTOR_STAR_NODE_H


#include "node.h"
#include <string>
#include <vector>


namespace tree{

    class SelectorStarNode : public Node
    {
        private:
            unsigned int current_child_index_;
        public:
            SelectorStarNode(std::string key, unsigned int);
            ReturnStatus Tick();
    };
}



#endif