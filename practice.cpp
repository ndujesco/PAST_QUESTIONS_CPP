#include <iostream>

using namespace std;

void increase(int);
void increase_(int &);
void increaseByPointer(int *);

int main()
{

    int a = 1;
    int b = 1;
    int c = 1;

    increase(a);
    cout << a << endl
         << endl;

    increase_(b);
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

void increase_(int &num)
{
    num++;
    cout << num << endl;
}