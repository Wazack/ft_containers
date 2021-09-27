#include "includes/Vector.hpp"
#include <vector>

int main ()
{
    ft::Vector<int> test;
    std::vector<int> rvector;
    std::vector<int>::reverse_iterator it;
    std::vector<int>::iterator itd;
    ft::Vector<int>::reverse_iterator rit;
    ft::Vector<int>::iterator ritd;

    for (size_t i = 0; i < 10; i++)
    {
        rvector.push_back(i);
        test.push_back(i);
    }
    it = rvector.rbegin();
    rit = test.rbegin();
    std::cout << "it: " << it[1] << std::endl;
    std::cout << "rit: " << rit[1] << std::endl;

    return 0;
}