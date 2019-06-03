#ifndef SEQUENCE_NODE_H
#define SEQUENCE_NODE_H


#include <string>
#include <vector>
#include "BT_node.h"

namespace BTree
{
class SequenceNode : public BTreeNode
{
public:
    // Constructor
    explicit SequenceNode(std::string name);
    ~SequenceNode();
    BTree::ReturnStatus Tick();
};
}  // namespace BT

#endif  // SEQUENCE_NODE_H