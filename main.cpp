#include "includes/vector.hpp"
#include "includes/Map.hpp"
#include "includes/Utility.hpp"
#include <vector>
#include <map>
#include <stack>
#include "includes/Bst.hpp"
#include "test/test.hpp"
// int main ()
// {
    // std::map<char, int> mymap;
//     std::map<char, int> map;
    // std::map<char, int>::iterator it;
//     std::map<char, int>::iterator ite;
//     ft::pair<std::map<char, int>::iterator, bool> ret;

//     ret = mymap.insert(ft::pair<char, int>('b', 3));
//     ret = mymap.insert(ft::pair<char, int>('a', 2));
//     ret = mymap.insert(ft::pair<char, int>('a', 4));

//     // it = ret.first;
//     // std::cout << it->first << std::endl;
//     it = mymap.begin();
//     ite = mymap.end();
//     std::cout << (*it).first << ", " << (*it).second << std::endl;
//     ++it;
//     std::cout << (*it).first << ", " << (*it).second << std::endl;
//     ++it;
//     std::cout << (*ite).first << ", " << (*ite).second << std::endl;
//     // for (std::map<char, int>::iterator tt = mymap.begin(); tt != mymap.end(); ++tt)
//     // {
//     //     std::cout << (*tt).first << " " << (*tt).second << std::endl;
//     // }

//     return 0;
// }

int main()
{
    vector_constructor();
    std::cout << std::endl << std::endl;
    vector_iterator();
    std::cout << std::endl << std::endl;
    vector_capacity();
    std::cout << std::endl << std::endl;
    vector_access();
    std::cout << std::endl << std::endl;
    vector_modifier();
    return 0;
}

// int main(){
//     ft::Bst<ft::pair<char, int> > test;
//     ft::Bst<ft::pair<char, int> >::iterator it;

//     test.insert(ft::pair<char, int>('b', 2));
//     test.insert(ft::pair<char, int>('c', 2));

//     it = test.begin();
// }