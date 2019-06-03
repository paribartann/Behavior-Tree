#ifndef SELECTOR_NODE_WITH_MEMORY_H
#define SELECTOR_NODE_WITH_MEMORY_H

#include <control_node.h>
#include <string>

namespace BT
{
class SelectorNodeWithMemory : public ControlNode
{
public:
    // Constructor
    explicit SelectorNodeWithMemory(std::string name);
    SelectorNodeWithMemory(std::string name, int reset_policy);
    ~SelectorNodeWithMemory();
    
    BT::ReturnStatus Tick();
    
private:
    unsigned int current_child_idx_;
    unsigned int reset_policy_;
};
}  // namespace BT


#endif  // SELECTOR_NODE_WITH_MEMORY_H
