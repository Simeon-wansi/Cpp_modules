

// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

class myexecption: public exception
{
    virtual const char* what() const throw()
    {
        return " The devide by Zero Exception\n";
    }
};


int main()
{
    try 
    {
        int a = 10, b=0;

        if (b==0)
        {
            myexecption m;
            throw m;
        }
        cout<<" THe Division operation is: " << a/b << endl;
    }
    catch(exception &e)
    {
        cout<<" The Exception caught here : " << e.what();
    }
}