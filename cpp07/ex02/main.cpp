#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 10

// int main(void)
// {
//     Array<int> tab(5);
//     int *tab2 = new int[5];

//     for (int i = 0; i < 5; i++)
//     {
//         const int value = rand() % 100;

//         tab2[i] = value;
//     }

//     for ( int i = 0; i < 5; i++)
//     {
//         std::cout << tab2[i] << " ";
//     }
//     std::cout << std::endl;

//     delete [] tab2;
//     return 0;
// }

// int main(void)
// {
//     Array<float> tab(5);
//     float *tab2 = new float[5];

//     for (int i = 0; i < 5; i++)
//     {
//         const float value = rand() % 100 / 3.14f;

//         tab2[i] = value;
//     }

//     for ( int i = 0; i < 5; i++)
//     {
//         std::cout << tab2[i] << " ";
//     }
//     std::cout << std::endl;

//     delete [] tab2;
//     return 0;
// }



int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    Array<int> tmp2;

    std::cout << "TEst temp2";



    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    std::cout << "Numbers values \n";
    for (int i = 0 ; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << " ";
    }

    std::cout << "\nMirror values \n";
    for (int i = 0 ; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    std::cout << "\n test values \n";
    for (int i = 0 ; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout << "Test non valid index\n";
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Test to change MAX_VAL value\n";
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "changing all the value of numbers\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}