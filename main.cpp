#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
    tree::BT bt;

    tree::Node* root = bt.buildBT("./bt_files/BT_Fig8");

    bt.execute(root, 1000);

    return 0;
}
