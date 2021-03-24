#include <iostream>
using namespace std;

int main()
{
    int* p = new int;
    int* p2 = p;
    *p = 10;
    delete p; //xóa con trỏ p thì con trỏ p2 ko còn vùng bộ nhớ để trỏ đến
    *p2 = 100;
    cout << *p2;
    delete p2;
}
