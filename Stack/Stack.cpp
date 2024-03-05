#include <iostream>
#include <stack>
#include "stack.h"
using namespace std;

int main()
{
    cout << "Part 1. MY OWN STACK: " << endl;

    Stack S;
    S.push(1);
    S.push(12);
    S.push(40);
    S.push(11);

    S.print();
    cout << "Popping an element: " << S.pop() << endl;
    cout << "Peeking top-element: " << S.peek() << endl;

    S.print();

    cout << "Part 2. STACK STL: " << endl;
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    
    stack<int> myStack2 = myStack;

    cout << "Elements in my stack: ";
    while (!myStack.empty()) {
        cout << myStack.top() << ' ';
        myStack.pop();
    }
    cout << endl;

    cout << "Popping an element: " << myStack2.top() << endl;
    myStack2.pop();

    cout << "Element on the top: " << myStack2.top() << endl;

    cout << "Size of my stack: " << myStack2.size() << endl;
}

