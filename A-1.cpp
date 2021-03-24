#include <iostream>
#include <cstring>
using namespace std;

char* concat(const char* c1, const char* c2)
{
    int l = strlen(c1) + strlen(c2);
    char* c = new char[l];
    strcpy(c, c1);
    strcat(c, c2);
    return c;
}

int main()
{
    char c1[]="Hello";
    char c2[]="World";
    char* c=concat(c1,c2);
    for(int i=0; i < strlen(c1)+strlen(c2); i++) cout << *(c+i);
}
