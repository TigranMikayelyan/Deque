#include "my_deque.hpp"

int main()
{
    Deque<int> md;
    md.push_back(1);
    md.push_back(2);
    md.push_back(3);
    md.print();
    md.pop_back();
    md.pop_back();
    md.print();
    md.push_front(77);
    md.push_front(99);
    md.print();
    std::cout << "Size = " << md.size() << std::endl;
    md.clear();
    std::cout << "Size = " << md.size() << std::endl;
    md.print();
    std::cout << std::boolalpha << md.empty() << std::endl;
    md.push_back(3);
    std::cout << std::boolalpha << md.empty() << std::endl;
}