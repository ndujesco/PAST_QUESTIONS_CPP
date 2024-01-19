#include <iostream>

using namespace std;

void increase(int);
void increaseByPointer(int *);
void increaseByReference(int &);

int main()
{

    int a = 1;
    int b = 1;
    int c = 1;

    increase(a);
    cout << a << endl
         << endl;

    increaseByReference(b);
    cout << b << endl
         << endl;

    increaseByPointer(&c);
    cout << c << endl
         << endl;

    return 0;
}

void increase(int a)
{
    a++;
    cout << a << endl;
}

void increaseByPointer(int *a)
{
    (*a)++;
    cout << *a << endl;
}

void increaseByReference(int &a)
{
    a++;
    cout << a << endl;
}