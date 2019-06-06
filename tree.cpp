
#include "tree.h"
#include <fstream>
#include <iostream>
#include <streambuf>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>


using namespace std;


int end_count = 0;

tree::BT::BT(){
    
}

tree::Node* tree::BT::buildBT(const string& fileName)
{
    ifstream infile;
    infile.open(fileName);
    string str;

    //reading the content into the string
    str.assign((istreambuf_iterator<char>(infile)),
               istreambuf_iterator<char>());

    // boost::split(result, str, boost::is_any_of("\n")); 
    stringstream ss(str);
    string item;
    
    while (getline(ss, item, '\n'))
    {
       result.push_back(item);
    }
   
    for (int i = 0; i < result.size(); i++)
    {
        stringstream input(result[i]);
        vector<string> splitWord;
        string word;
        int index = 0;
        while (input >> word)
        {   
            splitWord.push_back(word);
            index ++;
        }
        splittedBySpace.push_back(splitWord); //2D Vector which has element of each line such as OR, 3 and - , AND,2
    }

    string rootValue = "";
    int numberOfChildren_root = 0;
    
    rootValue = splittedBySpace[0][0];          //this will always be a root node according to our file
    // stringstream input(splittedBySpace[0][1]);
    // int x = 0;
    // input >> x;
    //cout<<x<<endl;
    //Node *nd;

    Node *root = newNode(rootValue);            //adding the above to the root of tree

    
    //building a tree (starting from 1 below the root)
    buildTree(1, splittedBySpace.size(), root, 1);
    
    //traversing along the tree and printing it
    LevelOrderTraversal(root); 

    return root;
      
}

void tree::BT::execute(Node* rootNode, int ticks_in_millisecond)
{
    /*while (true)
    {
        root->tick()
    }*/
    
}

// int BT::number_of_children(Node* root)
// {
//     return root->child.size
// }

//returns the control flow nodes or condition or action associated with the line number
string tree::BT::getBehavior(int depthIndex)
{
    return splittedBySpace[depthIndex][1];
}



//returns the number of children any behavior has
int tree::BT::getNumberOfChildren(int depthIndex)
{
    string val = "";
    if (depthIndex == 0)
        val = splittedBySpace[depthIndex][1];
    else
        val = splittedBySpace[depthIndex][2];
    stringstream input(val);
    int x = 0;
    input >> x;
    return x;
    
}

//returns the depth at where the control flow nodes or condition or action should be
int tree::BT::getDepth(int depthIndex)
{
    return (splittedBySpace[depthIndex][0]).length();
}



//this is a recursive function which takes the starting rootLine , last node of the tree, root of tree or subtree, and it's depth 
void tree::BT::buildTree(int rootStart, int rootEnd, Node* root, int depth)
{
   // Node * nd;
    int ithChild = -1;                          //denotes the child of each level (such as index [0] )
    int count = -1;                             //i am which number child of my parent
    for (int i = rootStart; i < rootEnd; i++)
    {
        count = count + 1;              //
        int level = getDepth(i);        //what is the level (-- / --- / ----)
        if (level != depth)             //if level and depth are not the same it goes on the check for the right one 
            continue;                   //basically looking for if the behavior belongs to the current depth or not

        //Secondary check for checking already parsed items 
        if (find(alreadyParsed.begin(), alreadyParsed.end(), rootStart+count) != alreadyParsed.end()) //checking if the following line has already been
            continue;                                                           //parsed, if so continue

        //cout<<getNumberOfChildren(i)<<endl;
        (root->child).push_back(newNode( getBehavior(rootStart+count)));           //root will vary as per the recursive function
        alreadyParsed.push_back( rootStart + count);                //put the index of the used behavior in alreadyParsed vector 
        ithChild++;                                                 //denotes the child number of any parents
        int num_of_children = getNumberOfChildren(i);   
   
        if (num_of_children > 0)
        {
            //buildTree(rootStart+count+1, splittedBySpace.size(), root->child[ithChild], depth+1);
            buildTree(rootStart+count+1, rootStart+count+1+num_of_children, root->child[ithChild], depth+1);
        }      
    }
}

