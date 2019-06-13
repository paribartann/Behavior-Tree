

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

#ifndef PSEUDO_DOMAIN_H
#define PSEUDO_DOMAIN_H
#include<string>
#include "node.h"

namespace tree{
  class pseudoDomain
  {
      public:
        pseudoDomain(); //constructor

        ReturnStatus GA();
        ReturnStatus GB();
        ReturnStatus GC();
        ReturnStatus DC();
        ReturnStatus not_carrying_packageTP();
        ReturnStatus battery_low();
        ReturnStatus call_function(std::string);
        ReturnStatus call_condition(std::string);

        static int gaCount, gbCount, gcCount, dcCount, charge;
        
        static ReturnStatus not_carryingPackage;
        
        static ReturnStatus status_GA, status_GB, status_GC, status_DC;
  };
}



#endif   //PSEUDO_DOMAIN_H






