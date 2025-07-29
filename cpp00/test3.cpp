#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::for_each
#include <utility> // for std::pair


int main(void)
{
    // typedef std::pair<std::string, int> student_t;
    // typedef std::vector<student_t> students_t;

    // students_t students;

    std::vector <std::string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
    std::vector <int> prices = {20000, 15000, 10000, 5000};

    for (int i = 0; i < cars.size(); i++)
    {
        for (int j = 0; j < prices.size(); j++)
        {
            std::cout << cars[i] << " " << prices[j] << std::endl;
        }
    }

}

