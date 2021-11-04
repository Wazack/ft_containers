#include "includes/vector.hpp"
#include "includes/Map.hpp"
#include "includes/Utility.hpp"
#include <vector>
#include <map>
#include <stack>
#include "includes/Bst.hpp"
#include "test/test.hpp"

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
    vector_assign();
    std::cout << std::endl << std::endl;
    vector_modifier();
    return 0;
}
