#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array{

private:
    T* _array;
    unsigned int _size;

public:

    Array(){

        std::cout << "Default constructor called" << std::endl;
        _array =  NULL;
        _size = 0;
    }
    Array(unsigned int n){
        _array = new T[n];
        _size = n;
    }

    Array(const Array& other)
    {
       _array =  new T[other._size];
       _size =  other._size;
       for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] _array;
            _array = new T[other._size];
            _size = other._size;
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
        return *this;
    }

    ~Array(){
        delete[] _array;
    }
    

    unsigned int size() const{
        return _size;
    }

    class outOfRange : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return "Index out of range";
            }
    };

    T& operator[](unsigned int index) {
        if (index >= _size)
            throw outOfRange();
        return _array[index];
    }
    const T& operator[](unsigned int index)const
    {
        if (index >= _size)
            throw outOfRange();
        return _array[index];
    }
};


#endif