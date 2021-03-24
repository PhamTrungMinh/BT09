#include <iostream>
using namespace std;

int length(char a[]);
char* reverse(char a[]);
char* delete_char(char a[], char c);
char* pad_right(char a[], int n);
char* pad_left(char a[], int n);
char* truncate(char a[], int n);
bool is_palindrome(char a[]);
char* trim_left(char a[]);
char* trim_right(char a[]);

int main()
{
    char *a = new char[10];
    cin >> a;
    char c;
    cin >> c;
    int n;
    cin >> n;
    cout << reverse(a) << endl;
    cout << delete_char(a,c) << endl;
    cout << pad_left(a,n) << endl;
    cout << pad_right(a,n) << endl;
    cout << truncate(a,n) << endl;
    cout << trim_left(a) << endl;
    cout << trim_right(a) << endl;
}

int length(char a[])
{
    int i=0;
    while(*(a+i)!='\0') i++;
    return i;
}

char* reverse(char a[])
{
    int l=length(a);
    char* c= new char[l];
    for(int i=0; i<l; i++){
        c[i] = a[l-1-i];
    }
    return c;
}

char* delete_char(char a[], char c)
{
    int l=length(a);
    char* ch = new char[l];
    for(int i=0; i<l; i++) ch[i]=a[i];
    for(int i=0; i<l; i++){
        if(ch[i]==c){
            for(int j=i; j<l-1; j++){
                ch[j]=ch[j+1];
            }
            ch[l-1]='\n';
            l--;
            i--;
        }
    }
    return ch;
}

char* pad_right(char a[], int n)
{
    int l=length(a);
    char* ch = new char[l];
    if(l<n){
        for(int i=0; i<l; i++) ch[i]=a[i];
        for(int i=l; i<n; i++) ch[i]='_';
    }
    else
    {
        for(int i=0; i<l; i++) ch[i]=a[i];
    }
    return ch;
}

char* pad_left(char a[], int n)
{
    int l=length(a);
    char* ch = new char[l];
    for(int i=0; i<l; i++) ch[i]=a[i];
    while(l<n){
        l++;
        for(int i=l-1; i>0; i--){
            *(ch+i)=*(ch+i-1);
        }
        *ch = '_';
    }
    return ch;
}

char* truncate(char a[], int n)
{
    int l=length(a);
    char* ch = new char[l];
    if(l>n){
        for(int i=0; i<n; i++){
            *(ch+i) = *(a+i);
        }
    }
    else for(int i=0; i<l; i++) ch[i]=a[i];
    return ch;
}

bool is_palindrome(char a[])
{
    int l = length(a);
    for(int i=0; i<l/2; i++){
        if(*(a+i) != *(a+l-1-i)) return false;
    }
    return true;
}

char* trim_left(char a[])
{
    int l=length(a);
    char* ch = new char[l];
    for(int i=0; i<l; i++) ch[i]=a[i];
    while(*ch == '_'){
        for(int i=0; i<l-1; i++){
            *(ch+i)=*(ch+i+1);
        }
        *(ch+l-1)='\n';
        l--;
    }
    return ch;
}

char* trim_right(char a[])
{
    int l=length(a);
    char* ch = new char[l];
    for(int i=0; i<l; i++) ch[i]=a[i];
    while(*(ch+l-1) == '_'){
        *(ch+l-1)='\n';
        l--;
    }
    return ch;
}

