#pragma once

class Stack
{
public:
    struct Node
    {
        int value;
        Node* link;
        Node(int number, Node* ptr = nullptr) : value(number), link(ptr) {}
        ~Node() {}
    };

private:
    Node* top;

public:
    Stack() : top() {}
    Stack(int number) : top(new Node(number)) {}
    Stack(const Stack& C);
    ~Stack();


    void push(int value);
    int pop();
    int peek() const;
    void print() const;

    bool isEmpty() const;
};