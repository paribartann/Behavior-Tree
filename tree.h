#include <string>
#include <vector>
#include "node.h"

namespace parse
{
    class BT {
        public:
            BT();   //constructor
            tree::Node* buildBT(const std::string&);
            void execute(int, tree::Node*);

            //utility functions
            std::string getBehavior(int);
            int getNumberOfChildren(int);
            int getDepth(int);
            void buildTree(int, int, tree::Node*, int);
            
        private:
            std::vector<std::string> result; 
            std::vector < std::vector<std::string> > splittedBySpace;
            std::vector<std::string> splitWord;
            std::vector<int> alreadyParsed;
            int tickPeriod;        
    };
}