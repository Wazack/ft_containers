#include "includes/Vector.hpp"
#include <vector>

int main()
{
    std::vector<long long> myvector;
    ft::Vector<long long> test(5, 2);
    std::vector<long long>::iterator it;
    std::vector<long long>::iterator itb;
    
    for (int i=0; i<100; i++) test.push_back(i);

    std::cout << "size: " << test.size() << '\n';
    std::cout << "capacity: " << test.capacity() << '\n';
    std::cout << "max_size: " << test.max_size() << '\n';
    std::cout << test.begin() << std::endl;
    return 0;
}