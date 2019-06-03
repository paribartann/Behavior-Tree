#ifndef SEQUENCE_NODE_WITH_MEMORY_H
#define SEQUENCE_NODE_WITH_MEMORY_H


#include <string>
#include <vector>
#include "BT_node.h"
#include <string>

namespace BTree
{
class SequenceNodeWithMemory : public BTreeNode
{
public:
    // Constructor
    explicit SequenceNodeWithMemory(std::string name);
    SequenceNodeWithMemory(std::string name, int reset_policy);
    ~SequenceNodeWithMemory();
    int DrawType();
    // The method that is going to be executed by the thread
    BTree::ReturnStatus Tick();
    
private:
    unsigned int current_child_idx_;
    unsigned int reset_policy_;
};
}  // namespace BT

#endif  // SEQUENCE_NODE_WITH_MEMORY_H