#include <bits/stdc++.h>
using namespace std;

template <class Type>
class myStack
{
public:
    myStack(int u) {array = new Type[u]; topPtr = -1; size =u;}
    ~myStack()     {delete[] array;}
    bool empty()
    {
        if (topPtr == -1)
            return true;
        else
            return false;
    }
    void push(Type t)
    {
        if (topPtr == size - 1)
        {
            cout << "Stack Overflowed!" << endl;
            return;
        }
        array[++topPtr] = t;
    }
    void pop(Type &t)
    {
        if (topPtr == -1)
            return;
        t = array[topPtr--];
    }
    Type top()
    {
        if (topPtr > -1)
            return array[topPtr];
    }

private:
    Type *array;
    int size;
    int topPtr;
};

int main(void)
{
    int temp;
    cout << "Example:" << endl;
    myStack<int> example(5);
    example.push(1);
    cout << "After push the number 1." << endl;
    cout << "top element:" << example.top() <<endl;
    example.push(2);
    example.push(3);
    example.push(4);
    example.push(5);
    cout << "After push the number 2 to 5." << endl;
    cout << "top element:" << example.top() <<endl;
    example.pop(temp);
    cout << "Now pop the top element." << endl;
    cout << "top element:" << temp <<endl;
    example.pop(temp);
    cout << "Now pop the top element." << endl;
    cout << "top element:" << temp <<endl;
    example.pop(temp);
    cout << "Now pop the top element." << endl;
    cout << "top element:" << temp <<endl;
    cout << "Example end. Thanks!" << endl;
    return 0;
}
