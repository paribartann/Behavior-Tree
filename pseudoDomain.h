
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
        //int charge;
        
        ReturnStatus status_GA, status_GB, status_GC, status_DC;
  };
}



#endif   //PSEUDO_DOMAIN_H






