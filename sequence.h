<<<<<<< HEAD
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
=======
#ifndef SELECTOR_NODE_H
#define SELECTOR_NODE_H

#include <control_node.h>
#include <string>

namespace BT
{
class SelectorNode : public ControlNode
{
public:
    // Constructor
    explicit SelectorNode(std::string name);
    ~SelectorNode();//destructor

    BT::ReturnStatus Tick();    // The method that is going to be executed what the node is ticked
};
}  // namespace BT

#endif  // SELECTOR_NODE_H
>>>>>>> 50b0338a421ad904611c0bbde870d39592baf8fa
