/* 
#Copyright (C) <June, 2019>  <Paribartan Dhakal, Bala Tripura Sundari Yerrapothu>

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
#include <unistd.h>
#include <map>
#include "pseudoDomain.h"

using namespace std;
using namespace tree;


int pseudoDomain::gaCount = 5;
int pseudoDomain::gbCount = 4; 
int pseudoDomain::gcCount = 3; 
int pseudoDomain::dcCount = 0; 
int pseudoDomain::charge = 50; 
ReturnStatus pseudoDomain::not_carryingPackage = SUCCESS; 
ReturnStatus pseudoDomain::status_GA;
ReturnStatus pseudoDomain::status_GB;
ReturnStatus pseudoDomain::status_GC;
ReturnStatus pseudoDomain::status_DC;

pseudoDomain::pseudoDomain()
{

}

tree::ReturnStatus pseudoDomain::not_carrying_packageTP()
{
    return pseudoDomain::not_carryingPackage;
}

tree::ReturnStatus pseudoDomain::battery_low()
{
    if ( charge < 25 )
        return SUCCESS;
    else
        return FAILURE;
}

tree::ReturnStatus pseudoDomain::call_function(string function_name)
{
    typedef tree::ReturnStatus (tree::pseudoDomain::*F_ptr)();
    std::map<std::string, F_ptr> myMap;

    myMap["GA"] = &pseudoDomain::GA;
    myMap["GB"] = &pseudoDomain::GB;
    myMap["GC"] = &pseudoDomain::GC;
    myMap["DC"] = &pseudoDomain::DC;
    
    F_ptr fun = myMap[function_name];

    return (this->*fun)();
   
}

tree::ReturnStatus pseudoDomain::call_condition(string function_name)
{
    typedef tree::ReturnStatus (tree::pseudoDomain::*F_ptr)();
    std::map<std::string, F_ptr> myMap;

    myMap["tp"] = &pseudoDomain::not_carrying_packageTP;
    myMap["t"] = &pseudoDomain::battery_low;
    
    F_ptr fun = myMap[function_name];

    return (this->*fun)();
   
}

tree::ReturnStatus pseudoDomain::GA()
{
    cout<<"GA count: "<<pseudoDomain::gaCount<<endl;
    pseudoDomain::charge --;
    if (pseudoDomain::status_GA != RUNNING)
        pseudoDomain::gaCount = 5;
    pseudoDomain::gaCount--;
    if(pseudoDomain::gaCount > 0)
    {
        cout<<"GA still running\n";
        pseudoDomain::status_GA = RUNNING;
    }
    else {       
        cout<<"GA returned success and package has now been picked\n\n";
        pseudoDomain::not_carryingPackage = FAILURE; 
        pseudoDomain::status_GA = SUCCESS;
    }
    return pseudoDomain::status_GA;
}

tree::ReturnStatus pseudoDomain::GB()
{
    cout<<"GB count: "<<pseudoDomain::gbCount<<endl;
    pseudoDomain::charge --;
    if (pseudoDomain::status_GB != RUNNING)
        pseudoDomain::gbCount = 4;
    pseudoDomain::gbCount--;
    if(pseudoDomain::gbCount > 0)
    {
        cout<<"GB still running\n";
        pseudoDomain::status_GB = RUNNING;
    }
    else{
        cout<<"GB returned success and the package has now been dropped\n\n";
        pseudoDomain::not_carryingPackage = SUCCESS; 
        pseudoDomain::status_GB = SUCCESS;
    }
    return pseudoDomain::status_GB;
}


tree::ReturnStatus pseudoDomain::GC()
{
    cout<<"GC count: "<<pseudoDomain::gcCount<<endl;
    pseudoDomain::gaCount = 5;
    pseudoDomain::gbCount = 4;
    pseudoDomain::charge --;
    if (pseudoDomain::status_GC != RUNNING)
        pseudoDomain::gcCount = 3;
    pseudoDomain::gcCount--;
    if(pseudoDomain::gcCount > 0)
    {
        cout<<"GC still running\n";
        pseudoDomain::status_GC = RUNNING;
    }
    else
    {
        cout<<"GC returned success and now going to DC\n\n";
        pseudoDomain::status_GC = SUCCESS;   
    }
    return pseudoDomain::status_GC;
}

tree::ReturnStatus pseudoDomain::DC()
{
    cout<<"DC count: "<<pseudoDomain::dcCount<<endl;
    pseudoDomain::charge --;
    sleep(2);
    if (pseudoDomain::status_DC != RUNNING)
        pseudoDomain::dcCount = 0;
    pseudoDomain::dcCount--;
    if(pseudoDomain::dcCount > 0)
    {
        cout<<"DC still running\n";
        pseudoDomain::status_DC = RUNNING;
    }
    else
    {
        pseudoDomain::charge = 100;
        pseudoDomain::status_DC = SUCCESS;
    }
    return pseudoDomain::status_DC;
}







