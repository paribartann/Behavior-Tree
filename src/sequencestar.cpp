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

#include "../include/sequencestar.h"
#include <iostream>
#include <string>


tree::SequenceStarNode::SequenceStarNode(std::string key, unsigned int num)
{
    current_child_index_ = 0;
    this->key = key; 
    set_type(SEQUENCESTAR);
    set_num_children(num);
}

tree::ReturnStatus tree::SequenceStarNode::Tick()
{
    std::cout<<"SequenceStar Node ticked"<<std::endl;
    while (current_child_index_ < get_num_children())
    {
        if (child[current_child_index_]->get_type() == tree::ACTION || child[current_child_index_]->get_type() == tree::CONDITION)
        {
                child_i_status_ = child[current_child_index_]->Tick();
        }
        else
        {
            //this will take care of control nodes
            child_i_status_ = child[current_child_index_]->Tick();
        }

        //now checking the returned status of the children nodes
        if (child_i_status_ == tree::SUCCESS)// || child_i_status_ == tree::RUNNING)
        {
             set_status(child_i_status_);
            if (current_child_index_ != (get_num_children() - 1))
            {
                current_child_index_++;
            }
            else
            {
                return tree::SUCCESS;
            }
        }
        else
        {
            return child_i_status_;
        }
    }   
    return child_i_status_;
}




