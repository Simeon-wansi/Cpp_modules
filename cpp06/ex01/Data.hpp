#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>

class Data
{
    private:
    int _id;
    std::string _name;

    public:
        Data();
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data();
        Data(int id, std::string name);
        int getId() const;
        std::string getName() const;
};

#endif 