#include <iostream>
#include <memory>
using namespace std;

int main()
{
    cout << "Hello World!\n";

    unique_ptr<int> a(new int(12));

    cout << *a << endl;

    a.reset();
    cout << *a << endl;

    return 0;
}