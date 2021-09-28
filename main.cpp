#include "includes/Vector.hpp"
#include <vector>

int main ()
{
    std::vector<int> vector;
    std::vector<int> vector2;
    ft::Vector<int> myvector;
    ft::Vector<int> myvector2;
    bool wut1;
    bool wut2;

    // for (size_t i = 0; i < 10; i++)
    // {
        // if (i == 5)
        // {
        //     vector2.push_back(100);
        //     myvector2.push_back(100);
        // }
        // else
        // {
            // if (i == 9)
            // {
            //     vector2.push_back(10000);
            //     myvector2.push_back(10000);
            // }
            // else
            // {
                // vector.push_back(100);
                // vector2.push_back(i);
                // myvector.push_back(100);
                // myvector2.push_back(i);
            // }
        // }
    // }
    // vector.resize(5);
    // myvector.resize(5);
    vector.push_back(3);
    vector.push_back(2);
    vector.push_back(1);
    vector.push_back(4);
    vector2.push_back(3);
    vector2.push_back(2);
    vector2.push_back(3);
    myvector.push_back(3);
    myvector.push_back(2);
    myvector.push_back(1);
    myvector.push_back(4);
    myvector2.push_back(3);
    myvector2.push_back(2);
    myvector2.push_back(3);
    wut1 = vector > vector2;
    wut2 = myvector > myvector2;
    std::cout << "Before: " << std::endl;
    for (ft::Vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << "myvector: " << *it << std::endl;
    
    for (ft::Vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); ++it)
        std::cout << "myvector2: " << *it << std::endl;
    
    ft::swap(myvector, myvector2);

    std::cout << "after: " << std::endl;
    for (ft::Vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << "myvector: " << *it << std::endl;
    
    for (ft::Vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); ++it)
        std::cout << "myvector2: " << *it << std::endl;
    std::cout << "vector: " << wut1 << std::endl;
    std::cout << "myvector: " << wut2 << std::endl;
    return 0;
}