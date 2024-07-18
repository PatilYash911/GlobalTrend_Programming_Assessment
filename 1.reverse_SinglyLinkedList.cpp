#include <iostream>
using namespace std;

struct listNode
{
    int data;
    listNode *next;
    listNode(int val) : data(val), next(nullptr) {}
};

listNode *createLinkedList(int numNodes)
{
    if (numNodes <= 0)
        return nullptr;

    listNode *head = new listNode(1);
    listNode *current = head;

    for (int i = 2; i <= numNodes; ++i)
    {
        current->next = new listNode(i);
        current = current->next;
    }
    return head;
}

listNode *reverseLinkedList(listNode *head)
{
    listNode *prev = nullptr;
    listNode *current = head;

    while (current != nullptr)
    {
        listNode *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main()
{
    int numNodes = 5;

    listNode *head = createLinkedList(numNodes);

    cout << "Original list: ";
    listNode *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    listNode *reversedHead = reverseLinkedList(head);

    cout << "Reversed list: ";
    current = reversedHead;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    return 0;
}
