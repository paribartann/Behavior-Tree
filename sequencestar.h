#ifndef SEQUENCE_STAR_NODE_H
#define SEQUENCE_STAR_NODE_H

#include "node.h"
#include <string>
#include <vector>


namespace tree{

    class SequenceStarNode : public Node
    {
        private:
            unsigned int current_child_index_;
        public:
            SequenceStarNode(std::string key, unsigned int);
            //SequenceStarNode();
            ReturnStatus Tick();
    };
}



#endif