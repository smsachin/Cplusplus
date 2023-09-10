#include <iostream>
using namespace std;

template <class T>
class MyVectorTemplate
{
    public:
    T *vec=nullptr;
    int size=0,capacity=1;
    MyVectorTemplate()
    {
        vec = new T[capacity];
    }
    MyVectorTemplate(std::initializer_list<T> list)
    {
        vec = new T[capacity];
        for(auto it =list.begin(); it!=list.end(); it++)
        {
            push(*it);
            
        }
        
    }
    void push(int val)
    {
        ++size;
        if(size > capacity)
        {
            capacity *=2;
            int *temp = new T[capacity];
            for(int i=0;i<size;i++)
            {
                temp[i] = vec[i];
            } 
            delete[] vec;
            vec=temp;
            vec[size-1] =val;
        }
        else
        {
            vec[size-1] =val;
        }
    }
    void print()
    {
        for (int i =0; i<size; i++)
            cout<<vec[i]<<" ";
            cout<<"\n";
    }
    T getLast()
    {
        return vec[size-1];
    }
    T pop()
    {
        --size;
    }
    ~MyVectorTemplate()
    {
        delete[] vec;
    }

};
int main()
{
    MyVectorTemplate<int> vv;
    vv.push(5);
    vv.push(9);
    vv.push(8);
    vv.push(6);
    vv.push(2);
    vv.print();
    MyVectorTemplate<int> vx{1,2,3,4,6};
    vx.print();
    cout<<vx.getLast()<<endl;
    vx.pop();
    cout<<vx.getLast()<<endl;
    vx.print();
    cout<<"Hello World";

    return 0;
}