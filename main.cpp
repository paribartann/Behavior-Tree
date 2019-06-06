#include <iostream>
//#include "tree.h"
#include "selector.h"


using namespace std;

int main()
{
    tree::BT bt;

    tree::SelectorNode st; 
    tree::Node* root= bt.buildBT("BT_Fig8");

   // cout<<root->key<<endl;
    //cout<<root->child.size()<<endl;
    cout<<root->child[2]->get_type()<<"\n";
    // cout<<root->child[1]->child.size()<<"\n";
    // cout<<root->child[2]->child.size()<<"\n";
    // cout<<root->child[0]->child[0]->child.size()<<"\n";
    // cout<<root->child[0]->child[1]->child.size()<<"\n";
    
    st.Tick();
    //cout<<root->tick()<<endl;

    return 0;
}
