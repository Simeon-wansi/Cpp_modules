#include "easyfind.hpp"
#include <list>
#include <deque>
#include <vector>

// int main(void)
// {
//     std::vector<int> tab;
//     tab.push_back(1);
//     tab.push_back(2);
//     tab.push_back(3);
//     tab.push_back(4);
//     tab.push_back(5);

//     try
//     {
//         std::vector<int>::iterator res = easyfind(tab, 5);
//         std::cout <<"Found: " << *res << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << "\n";
//     }

//     try
//     {
//         std::vector<int>::iterator res = easyfind(tab, 8);
//         std::cout <<"Found: " << *res << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << "\n";
//     }
// }


int main(void)
{
    std::deque<int> myDeque;
    myDeque.push_back(1);
    myDeque.push_back(2);
    myDeque.push_back(3);
    myDeque.push_back(4);
    myDeque.push_back(5);

    try
    {
        std::deque<int>::iterator res = easyfind(myDeque, 5);
        std::cout <<"Found: " << *res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }

    try
    {
        std::deque<int>::iterator res = easyfind(myDeque, 8);
        std::cout <<"Found: " << *res << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
    }
}

// int main(void)
// {
//     std::list<int> myList;
//     myList.push_back(1);
//     myList.push_back(2);
//     myList.push_back(3);
//     myList.push_back(4);
//     myList.push_back(5);

//     try
//     {
//         std::list<int>::iterator res = easyfind(myList, 5);
//         std::cout <<"Found: " << *res << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << "\n";
//     }

//     try
//     {
//         std::list<int>::iterator res = easyfind(myList, 8);
//         std::cout <<"Found: " << *res << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << "\n";
//     }
// }




