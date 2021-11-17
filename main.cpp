#include "includes/vector.hpp"
#include "includes/map.hpp"
#include "includes/Utility.hpp"
#include <vector>
#include <map>
#include <stack>
#include "includes/Bst.hpp"
#include "test/test.hpp"

// int main()
// {
//     vector_constructor();
//     std::cout << std::endl << std::endl;
//     vector_iterator();
//     std::cout << std::endl << std::endl;
//     vector_capacity();
//     std::cout << std::endl << std::endl;
//     vector_access();
//     std::cout << std::endl << std::endl;
//     vector_assign();
//     std::cout << std::endl << std::endl;
//     vector_modifier();
//     std::cout << std::endl << std::endl;
//     vector_operators();
//     std::cout << std::endl << std::endl;
//     stack_tester();

//     return 0;
// }

int main()
{
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;

    // insert some values:
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;

    it=mymap.find('b');
    mymap.erase (it);                   // erasing by iterator

    mymap.erase ('c');                  // erasing by key

    it=mymap.find ('e');
    mymap.erase ( it, mymap.end() );    // erasing by range

    // show content:
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    return 0;
}
