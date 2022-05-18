#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
C. 
(max 10 points) Write a C++ class template basing on the class animal of task B.

(8 points) allow to choose the data type of leg_count, show usage examples of having it both integer and string.

(+2) all methods implemented outside class.
*/

template <class T>
class animal
{
    string name;
    T leg_count;
public:
    animal(string n, T l);
    virtual void print();
    virtual ~animal();
};

template <class T>
animal<T>::animal(string n, T l) {name = n; leg_count = l;}

template <class T>
void animal<T> :: print() {cout << name << ": " << leg_count << " legs" << endl;}

template <class T>
animal<T> :: ~animal() {cout << "Animal deleted" << endl;}


int main()
{
    animal<int> a("cat", 4);
    a.print();

    animal<string> b("penguin", "two");
    b.print();


    return 0;
}