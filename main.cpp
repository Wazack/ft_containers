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
    ft::map<char, int> test;
    std::map<char, int> re;
    std::map<char, int>::iterator tr;

    test.insert(ft::pair<char, int>('j', 10));
    test.insert(ft::pair<char, int>('a', 1));
    test.insert(ft::pair<char, int>('f', 10));
    re.insert(std::pair<char, int>('a', 1));
    re.insert(std::pair<char, int>('j', 10));
    re.insert(std::pair<char, int>('f', 10));
    tr = re.begin();
    tr = re.insert(tr, std::pair<char, int>('f', 20));
    tr++;
    std::cout << tr->first << std::endl;
    for (std::map<char, int>::iterator it = re.begin(); it != re.end(); ++it)
    {
        std::cout << it->first << std::endl;
    }
    
    return 0;
}
