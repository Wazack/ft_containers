#include "includes/vector.hpp"
#include "includes/Map.hpp"
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
    // ft::Bst<ft::pair<char, int> > bst;
    // ft::Bst<ft::pair<char, int> >::iterator it = bst.begin();
    std::map<char, int> test;
    std::map<char, int>::iterator it = test.begin();
    (void)it;
    ft::Map<char, int> test1;
    ft::Map<char, int>::iterator it1 = test1.begin();
    std::cout << (*it).first << std::endl;
    std::cout << (*it1).first << std::endl;
    // ft::BstIterator<ft::Bst<ft::tree<ft::pair<char, int> > > > it = bst.begin();

    return 0;
}
