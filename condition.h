#ifndef CONDITION_NODE_H
#define CONDITION_NODE_H

#include "node.h"
#include <string>
#include <vector>


namespace tree{

    class ConditionNode : public Node
    {
        public:
            ConditionNode(std::string key);
            ReturnStatus Tick();
    };
}



#endif