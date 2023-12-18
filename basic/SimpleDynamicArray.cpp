#include <iostream>

using namespace std;

int main()
{
    cout<<"Hello World";
    int* p = nullptr;
    int  x=0;
    int i=0;
    while(1)
    {
        cin>>x;
        if(x != -1)
        {
            p=(int*)realloc((void*)p,(i++)*sizeof(int));
            int *tp = p;
            tp = p +(i-1);
            *tp =x;
        }
        else
            break;
    }
    for(int k=0; k< i;k++)
    {
        cout<<*p<<" ";
        p++;
    }

    return 0;
}