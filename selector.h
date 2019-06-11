#ifndef SELECTOR_NODE_H
#define SELECTOR_NODE_H

#include "node.h"
#include <string>
#include <vector>


namespace tree{

    class SelectorNode : public Node
    {
        public:
            SelectorNode(std::string key, unsigned int);
            ReturnStatus Tick();
    };
}



#endif