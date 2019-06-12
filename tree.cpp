
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
    unsigned int numberOfChildren_root = 0;
    
    rootValue = splittedBySpace[0][0];          //this will always be a root node according to our file
    numberOfChildren_root = getNumberOfChildren(0);
  

    if (rootValue == "AND")
    {
        root = new SequenceNode(rootValue, numberOfChildren_root);   
    }
    else if (rootValue == "ANDM")
    {
        root = new SequenceStarNode(rootValue, numberOfChildren_root);
    }
    else if (rootValue == "ORM")
    {
        root = new SelectorStarNode(rootValue, numberOfChildren_root);
    }
    else if (rootValue == "OR")
    {
        root = new SelectorNode(rootValue, numberOfChildren_root);
    }
    else if (rootValue == "t" || rootValue == "tp")
    {
        root = new ConditionNode(rootValue);
    }
    else
    {
        root = new ActionNode(rootValue);
    }
    
    //building a tree (starting from 1 below the root)
    buildTree(1, splittedBySpace.size(), root, 1);
    
    //traversing along the tree and printing it
    //LevelOrderTraversal(root); 

    return root;
}

void tree::BT::execute(Node* rootNode, int ticks_in_millisecond)
{
    rootNode->Tick();
}


//returns the control flow nodes or condition or action associated with the line number
string tree::BT::getBehavior(int depthIndex)
{
    return splittedBySpace[depthIndex][1];
}

tree::ReturnStatus tree::BT::Tick(){
     
     //this is just for the sake of doing
     return tree::SUCCESS;
}

//returns the number of children any behavior has
unsigned int tree::BT::getNumberOfChildren(int depthIndex)
{
    string val = "";
    if (depthIndex == 0)
        val = splittedBySpace[depthIndex][1];
    else
        val = splittedBySpace[depthIndex][2];
    stringstream input(val);
    unsigned int x = 0;
    input >> x;
    return x;
    
}

//returns the depth at where the control flow nodes or condition or action should be
int tree::BT::getDepth(int depthIndex)
{
    return (splittedBySpace[depthIndex][0]).length();
}



//this is a recursive function which takes the starting rootLine , last node of the tree, root of tree or subtree, and it's depth 
void tree::BT::buildTree(int rootStart, int rootEnd, Node* rootNode, int depth)
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

 
        if (getBehavior(i) == "AND")
        {
            rootC = new SequenceNode("AND", getNumberOfChildren(i));   
        }
        else if (getBehavior(i) == "ANDM")
        {
            rootC = new SequenceStarNode("ANDM", getNumberOfChildren(i));
        }
        else if (getBehavior(i) == "ORM")
        {
            rootC = new SelectorStarNode("ORM", getNumberOfChildren(i));
        }
        else if (getBehavior(i) == "OR")
        {
            rootC = new SelectorNode("OR", getNumberOfChildren(i));
        }
        else if (getBehavior(i) == "t" || getBehavior(i) == "tp")
        {
            rootC = new ConditionNode(getBehavior(i));
        }
        else
        {
            rootC = new ActionNode(getBehavior(i));
        }

        (rootNode->child).push_back(rootC);           //root will vary as per the recursive function
        alreadyParsed.push_back( rootStart + count);                //put the index of the used behavior in alreadyParsed vector 
        ithChild++;                                                 //denotes the child number of any parents
        unsigned int num_of_children = getNumberOfChildren(i);   
   
        if (num_of_children > 0)
        {
            //buildTree(rootStart+count+1, splittedBySpace.size(), root->child[ithChild], depth+1);
            buildTree(rootStart+count+1, rootStart+count+1+num_of_children, rootNode->child[ithChild], depth+1);
        }      
    }
}

