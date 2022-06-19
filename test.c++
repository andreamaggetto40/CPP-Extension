#include <iostream>
#include "headers/array_list.hpp"
#include "headers/set.hpp"
#include "headers/list.hpp"
#include "headers/circular_list.hpp"
#include "headers/doubly_list.hpp"



int main(int argc, char const *argv[])
{   
    list<char> first{}; vector<char> output{};

    first.append('a'); first.append('d'); first.append('e');

    first.wowels_appender(output);

    for(char it : output) cout<<it<<endl;

    

}
