/* taken help from geek foo geeks */
#include "node.h"
#include <string>
#include <iostream>
#include <queue>  
using namespace std;

namespace tree
{

    Node::Node(){
    }

    Node::~Node(){
    }
  
    // Prints the n-ary tree level wise 
    void LevelOrderTraversal(Node* root) 
    { 
        if (root==NULL) 
            return; 
    
        // Standard level order traversal code 
        // using queue 
        queue<Node *> q;  // Create a queue 
        q.push(root); // Enqueue root  
        while (!q.empty()) 
        { 
            int n = q.size(); 
    
            // If this node has children 
            while (n > 0) 
            { 
                // Dequeue an item from queue and print it 
                Node * p = q.front(); 
                q.pop(); 
                cout << p->key << " "; 
    
                // Enqueue all children of the dequeued item 
                for (int i=0; i<p->child.size(); i++) 
                    q.push(p->child[i]); 
                n--; 
            } 
    
            cout << endl; // Print new line between two levels 
        } 
    } 
} 
