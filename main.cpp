#include "includes/Vector.hpp"
#include <vector>

int main()
{
    ft::Vector<int> myvector;
    ft::Vector<int>::iterator it;
    ft::Vector<int>::iterator it2;
    ft::Vector<int>::iterator it3;

    for (size_t i = 0; i < 10; i++)
        myvector.push_back(i);
    
    it = myvector.begin() + 4;
    it2 = myvector.begin() + 6;
    it = myvector.erase(it, it2);
    // it = myvector.begin();
    for (; it != myvector.end(); ++it)
        std::cout << *it << std::endl;
    
    return 0;
}