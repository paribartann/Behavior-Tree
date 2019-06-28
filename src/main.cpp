/* 
#Copyright (C) <June, 2019>  <Paribartan Dhakal>

#This program is free software: you can redistribute it and/or modify
#it under the terms of the GNU Affero General Public License as
#published by the Free Software Foundation, either version 3 of the
#License, or (at your option) any later version.


#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU Affero General Public License for more details.
*/


#include <iostream>
#include "../include/tree.h"

using namespace std;

int main(int argc, char* argv[])
{
    tree::BT bt;

    const char* fileName = argv[1];
    cout<<fileName<<endl;

    tree::Node* root = bt.buildBT(fileName);

    bt.execute(root, 1000);

    return 0;
}
