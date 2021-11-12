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
    std::map<char,int> mymap;

    mymap ['a']=101;
    mymap ['c']=202;
    mymap ['b']=404;
    mymap ['j']=505;
    mymap ['h']=606;
    mymap ['i']=606;
    mymap ['d']=606;
    mymap ['e']=606;

    mymap.erase('c');
    for (std::map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
        std::cout << it->first << std::endl;

    return 0;
}
