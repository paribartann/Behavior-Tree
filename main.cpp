#include <iostream>
//#include "tree.h"
#include "selector.h"


using namespace std;

int main()
{
    tree::BT bt;

    tree::SelectorNode st; 
    tree::Node* root= bt.buildBT("BT_Fig8");

    bt.execute(root, 1000);

    return 0;
}
