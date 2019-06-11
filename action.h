#ifndef ACTION_NODE_H
#define ACTION_NODE_H

#include "node.h"
#include <string>
#include <vector>


namespace tree{

    class ActionNode : public Node
    {
        public:
            ActionNode(std::string key);
            ReturnStatus Tick();
    };
}



#endif