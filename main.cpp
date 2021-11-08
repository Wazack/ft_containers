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
    ft::map<char, int>::iterator it;
    std::map<char, int> re;
    std::map<char, int>::iterator itre;
    ft::pair<ft::map<char,int>::iterator,bool> ret;
    std::pair<std::map<char,int>::iterator,bool> retre;

    test.insert(ft::pair<char, int>('a', 1));
    ret = test.insert(ft::pair<char, int>('a', 5));
    test.insert(ft::pair<char, int>('f', 10));
    re.insert(std::pair<char, int>('a', 1));
    retre = re.insert(std::pair<char, int>('a', 5));
    re.insert(std::pair<char, int>('f', 10));
    std::cout << ret.first->second << std::endl;
    std::cout << retre.first->second << std::endl;
    return 0;
}
