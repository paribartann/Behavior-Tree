 

#include <iostream>
#include <unistd.h>
#include <map>
#include "pseudoDomain.h"

using namespace std;
using namespace tree;


int pseudoDomain::gaCount = 5;
int pseudoDomain::gbCount = 4;
int pseudoDomain::gcCount = 3;
int pseudoDomain::dcCount = 2;
int pseudoDomain::charge = 100;
ReturnStatus pseudoDomain::not_carryingPackage = SUCCESS;

pseudoDomain::pseudoDomain()
{
    //not_carryingPackage = tree::SUCCESS;
}

tree::ReturnStatus pseudoDomain::not_carrying_packageTP()
{
    return not_carryingPackage;
}

tree::ReturnStatus pseudoDomain::battery_low()
{
    if ( charge < 25 )
        return tree::SUCCESS;
    else
        return tree::FAILURE;
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
    pseudoDomain::charge --;
    if (status_GA != RUNNING)
        pseudoDomain::gaCount = 5;
    pseudoDomain::gaCount--;
    if(pseudoDomain::gaCount > 0)
    {
        cout<<"GA still running\n";
        status_GA = RUNNING;
    }
    else {       
        cout<<"GA returned success and package has now been picked\n\n";
        not_carryingPackage = FAILURE; 
        status_GA = SUCCESS;
    }
    return status_GA;
}

tree::ReturnStatus pseudoDomain::GB()
{
    pseudoDomain::charge --;
    if (status_GB != RUNNING)
        pseudoDomain::gbCount = 4;
    pseudoDomain::gbCount--;
    if(pseudoDomain::gbCount > 0)
    {
        cout<<"GB still running\n";
        status_GB = RUNNING;
    }
    else{
        cout<<"GB returned success and the package has now been dropped\n\n";
        not_carryingPackage = SUCCESS; 
        status_GB = SUCCESS;
    }
    return status_GB;
}


tree::ReturnStatus pseudoDomain::GC()
{
    pseudoDomain::gaCount = 5;
    pseudoDomain::gbCount = 4;
    pseudoDomain::charge --;
    if (status_GC != RUNNING)
        pseudoDomain::gcCount = 3;
    pseudoDomain::gcCount--;
    if(pseudoDomain::gcCount > 0)
    {
        cout<<"GC still running\n";
        status_GC = RUNNING;
    }
    else
    {
        cout<<"GC returned success and now going to DC\n\n";
        status_GC = SUCCESS;   
    }
    return status_GC;
}

tree::ReturnStatus pseudoDomain::DC()
{
    
    pseudoDomain::charge --;
    sleep(2);
    if (status_DC != RUNNING)
        pseudoDomain::dcCount = 0;
    pseudoDomain::dcCount--;
    if(pseudoDomain::dcCount > 0)
    {
        cout<<"DC still running\n";
        status_DC = RUNNING;
    }
    else
    {
        pseudoDomain::charge = 100;
        status_DC = SUCCESS;
    }
    return status_DC;
}







