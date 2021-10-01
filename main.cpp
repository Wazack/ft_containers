#include "includes/Vector.hpp"
#include "includes/Map.hpp"
#include "includes/Utility.hpp"
#include <vector>
#include <map>

int main ()
{
    std::map<char, int> mymap;
    ft::Map<char, int> map;
    ft::Map<char, int>::iterator it;

    map.insert(ft::pair<char, int>('g', 10));
    map.insert(ft::pair<char, int>('e', 55));
    map.insert(ft::pair<char, int>('h', 11));
    map.insert(ft::pair<char, int>('f', 9));

    it = map.end();
    std::cout << (*it).first << std::endl;
    std::cout << map.empty() << std::endl;
    // map.test();
    // // for (size_t i = 0; i < 10; i++)
        // mymap.insert(std::pair<char, int>('a' + i, i));

    for (std::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
    {
        std::cout << (*it).first << std::endl;
        std::cout << it->first << " : " << it->second << std::endl;
    }

    return 0;
}