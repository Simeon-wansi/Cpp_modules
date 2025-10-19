#include <iostream>
#include <vector>
#include <deque>

// int main()
// {
//     std::vector <int> vec;
//     std::deque<int> deq;

//     vec.push_back(1);
//     vec.push_back(20);
//     vec.push_back(3);
//     vec.push_back(40);

//     vec[3] = 4;
//     vec.at(1) = 2;
    
//     deq.push_back(4);
//     deq.push_front(1);
//     deq.push_back(5);
//     deq.push_front(0);

//     deq[2] = 3;
//     deq.at(1) = 2;

//     for (size_t i = 0; i < vec.size(); i++)
//         std::cout << vec[i] << " ";
    
//     std::cout << std::endl;
    
//     for (std::deque<int>::iterator it =  deq.begin(); it != deq.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
// }

// #include <list>
// // struct node
// // {
// //     int data;
// //     struct node *next;
// // };

// // int main()
// // {
// //     struct node *n1;

// //     n1->data = 5;
// //     n1->next =  nullptr;

// //     std::list<int> list1;

// //     std::vector<int> vec;

    
// // }



// #include <list>
// #include <set>


// int main()
// {
//     std::list<int> list1;
//     std::set<int> set1;
//     std::multiset<int> mset1;

//     list1.push_back(1);
//     list1.push_back(2);
//     list1.push_back(3);
//     list1.push_back(4);
//     list1.push_back(5);

//     list1.insert(list1.end(), 0);


//     set1.insert(1);;
//     set1.insert(2);
//     set1.insert(3);
//     set1.insert(4);
//     set1.insert(4);

//     mset1.insert(1);
//     mset1.insert(2);
//     mset1.insert(3);
//     mset1.insert(4);
//     mset1.insert(4);

//     for (std::list<int>::iterator it =  list1.begin(); it != list1.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     for (std::set<int>::iterator it =  set1.begin(); it != set1.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     for (std::multiset<int>::iterator it =  mset1.begin(); it != mset1.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;
// }



// #include <map>

// int main()
// {
//     std::map<std::string, int> map1;
//     std::multimap<std::string, int> mmap1;

//     map1["simeon"] = 1;
//     map1["Joel"] = 2;
//     map1["John"] = 3;
//     map1["John"] = 4;


//     mmap1.insert(std::make_pair("simeon", 1));
//     mmap1.insert(std::make_pair("Joel", 2));
//     mmap1.insert(std::make_pair("John", 3));
//     mmap1.insert(std::make_pair("John", 4));


//     for (std::map<std::string, int>::iterator it = map1.begin(); it != map1.end(); ++it)
//         std::cout << it->first << " : " << it->second << std::endl;

//     std::cout << "--------\n";
//     for (std::multimap<std::string, int>::iterator it = mmap1.begin(); it != mmap1.end(); ++it)
//         std::cout << it->first << " : " << it->second << std::endl;
// }



// #include <stack>
// #include <queue>


// int main()
// {
//     std::stack<int> st;
//     std::queue<int> qu;

//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);
//     st.push(5);

//     qu.push(1);
//     qu.push(2);
//     qu.push(3);
//     qu.push(4);
//     qu.push(5);

//     // std::cout << "Stack: ";
//     // while (!st.empty())
//     // {
//     //     std::cout << st.top() << " ";
//     //     st.pop();
//     // }

//     // std::cout << std::endl;
//     // std::cout << "Queue: ";
//     // while (!qu.empty())
//     // {
//     //     std::cout << qu.front() << " ";
//     //     qu.pop();
//     // }

//     std::cout << st.top() << " ";
//     // std::cout << qu.top() << " ";
//     std::cout << qu.front() << " ";
//     // std::cout << st.front() << " ";
//     std::cout << qu.back() << " ";
//     // std::cout << st.back() << " ";
//     std::cout << std::endl;
// }



#include <vector>


int main()
{
    std::vector<int> vec;

    vec.push_back(44);
    vec.push_back(452);
    vec.push_back(21);
    vec.push_back(0);

    std::cout << "before: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;

    std::cout << "after: ";
    std::sort(vec.begin(), vec.end());
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}


#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>


template <typename T>
class MutantStack : public std::stack<T>{

    public:
        MutantStack() {};
        MutantStack(T const &src) : std::stack<T>(src) {};
        MutantStack(MutantStack const & src){*this = src;};
        ~MutantStack() {};
        MutantStack & operator=(MutantStack const & rhs) {
            std::stack<T>::operator=(rhs);
            return *this;
        };
        typedef typename std::stack<T>::container_type::iterator iterator;
        const_iterator begin() {return this->c.begin();}
        const_iterator end() {return this->c.end();}
        
        
};

#endif