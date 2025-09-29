#include "iter.hpp"
#include <iostream>

// void prinx2(int val)
// {
//     std::cout << val * 2 <<  " ";
// }

// int main()
// {
//     int arr[] =  { 2, 3, 4, 9, 7};

//     size_t len =  sizeof(arr) / sizeof(arr[0]);

//     iter(arr, len, prinx2);

// }


// void increment(int& val)
// {
//     val =  val + 1;
// }


// void printArr(int* array, size_t len)
// {
//     for (size_t i = 0; i < len; ++i)
//     {
//         std::cout << array[i] << " ";
//     }
//     std::cout << std::endl;
// }
// int main()
// {
//     int arr[] =  { 74, 76, 78, 80, 82};

//     size_t len =  sizeof(arr) /  sizeof(arr[0]);
//     printArr(arr, len);


//     iter(arr, len, increment);
//     printArr(arr, len);
// }



void increment(int& val) {
    val++;
}

void printConst(const int& val) {
    std::cout << val << " ";
}

void printStr(const std::string& s) {
    std::cout << s << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    iter(arr, 5, increment);

    std::cout << "After increment \n";

    iter(arr, 5, printConst); 
    
    std::cout << std::endl;

    
    std::string strs[] = {"hello", "world"};
    iter(strs, 2, printStr); 
}