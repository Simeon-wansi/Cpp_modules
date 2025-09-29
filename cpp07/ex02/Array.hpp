#ifndef ARRAY_HPP
#define ARRAY_HPP


template <typename T>

class Array{

private:
    T* _array;
    unsigned int _size;

public:

    Array(){
        _array =  NUL;
        _size = 0;
    }
    Array(unsigned int n){
        _array = new T[n];
        _size = n;
    }

    Array(const Array& other)
    {
        *this = other;
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
    
};

#endif