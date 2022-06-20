#include <iostream>
#include "headers/array_list.hpp"
#include "headers/set.hpp"
#include "headers/list.hpp"
#include "headers/circular_list.hpp"
#include "headers/doubly_list.hpp"
#include "headers/vector_list.hpp"

int main(int argc, char const *argv[])
{       
    list_vect<int> first{};

    for(int i = 0; i < 10; ++i,first.append(i));

    
}
