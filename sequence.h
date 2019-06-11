#ifndef SEQUENCE_NODE_H
#define SEQUENCE_NODE_H

#include "node.h"
#include <string>
#include <vector>


namespace tree{

    class SequenceNode : public Node
    {
        public:
            SequenceNode(std::string key, unsigned int);
            ReturnStatus Tick();
    };
}



#endif