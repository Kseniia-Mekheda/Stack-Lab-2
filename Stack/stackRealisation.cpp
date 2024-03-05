#include "stack.h"
#include <iostream>

using namespace std; 

Stack::~Stack() {
    while (!isEmpty())
    {
        pop();
    }
}

void Stack::push(int value)
{
    Node* newElement = new Node(value);
    newElement->link = top;
    top = newElement;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Steck is empty, it is impossible to pop an element." << endl;
        return 0;
    }

    int valueForPop = top->value;
    Node* victim = top;
    top = top->link;
    delete victim;
    return valueForPop;
}

int Stack::peek() const
{
    if (isEmpty())
    {
        cout << "Steck is empty, it is impossible to pop an element." << endl;
        return 0;
    }

    return top->value;
}

bool Stack::isEmpty() const
{
    return top == nullptr;
}

void Stack::print() const
{

    if (isEmpty())
    {
        cout << "Steck is empty, it is impossible to pop an element." << endl;
    }

    cout << "Your stack: " << endl;
    Node* temp = top;
    while (temp != nullptr)
    {
        cout << temp->value << ' ';
        temp = temp->link;
    }
    cout << endl;
}

Stack::Stack(const Stack& C)
{
    if (C.top == nullptr) {
        top = nullptr;
        return;
    }

    top = new Node(C.top->value);
    Node* current = top;
    Node* otherCurrent = C.top->link;

    while (otherCurrent != nullptr) {
        current->link = new Node(otherCurrent->value);
        current = current->link;
        otherCurrent = otherCurrent->link;
    }
}