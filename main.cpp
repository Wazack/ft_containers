#include "includes/Vector.hpp"
#include "includes/Map.hpp"
#include "includes/Utility.hpp"
#include <vector>
#include <map>

int main ()
{
    ft::Map<char, int> mymap;
    ft::Map<char, int> map;
    ft::Map<char, int>::iterator it;
    ft::Map<char, int>::iterator ite;
    ft::pair<ft::Map<char, int>::iterator, bool> ret;

    ret = mymap.insert(ft::pair<char, int>('b', 3));
    ret = mymap.insert(ft::pair<char, int>('a', 2));
    ret = mymap.insert(ft::pair<char, int>('a', 4));

    // it = ret.first;
    // std::cout << it->first << std::endl;
    it = mymap.begin();
    ite = mymap.end();
    std::cout << (*it).first << ", " << (*it).second << std::endl;
    ++it;
    std::cout << (*it).first << ", " << (*it).second << std::endl;
    ++it;
    std::cout << (*ite).first << ", " << (*ite).second << std::endl;
    // for (ft::Map<char, int>::iterator tt = mymap.begin(); tt != mymap.end(); ++tt)
    // {
    //     std::cout << (*tt).first << " " << (*tt).second << std::endl;
    // }

    return 0;
}