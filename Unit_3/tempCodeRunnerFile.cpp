// 1) WAP to build a simple stock price tracker that keeps a history of daily stock prices
// entered by the user. To allow users to go back and view or remove the most recent price,
// implement a stack using a linked list to store these integer prices.
// Implement the following operations:
// a. record(price) – Add a new stock price (an integer) to the stack.
// b. remove() – Remove and return the most recent price (top of the stack).
// c. latest() – Return the most recent stock price without removing it.
// d. isEmpty() – Check if there are no prices recorded.
#include <iostream>
using namespace std;

class Node
{
public:
    float price;
    Node *next;

    Node(float price)
    {
        this->price = price;
        next = nullptr;
    }
};

void insert(Node *&head, float price)
{
    head = new Node(price);
}

void record(Node *&head, float price)
{
    if (head == NULL) {
        insert(head, price);
        return;
    }

    Node *new_node = new Node(price);
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

float remove(Node *&head)
{
    if (head == NULL)
        return -1; 

    if (head->next == NULL) {
        float n = head->price;
        delete head;
        head = NULL;
        return n;
    }