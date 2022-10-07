#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Q. Create a doubly linked list. Perform Deletion of an element (given by the user at run time).
// User gives the index of the element to delete, I have used 0 based indexing here,
// if the user gives 0 that means that I delete the node at the head and so on.
// The function insertNodeFromStart handles insertion.
// The function printList is a utility function used to print the list from head to tail.
// The function deleteNodeFromStart handles the deletion of the node.
class Node
{
public:
  int data;
  Node *next;
  Node *prev;
  Node(int data)
  {
    this->data = data;
    prev = NULL;
    next = NULL;
  }
  Node(int data, Node *prev, Node *next)
  {
    this->data = data;
    this->prev = prev;
  }
};
// 0 based indexing
class DoublyLinkedList
{
public:
  Node *head;
  Node *tail;
  DoublyLinkedList(Node *head, Node *tail)
  {
    this->head = head;
    this->tail = tail;
  }
  void insertNodeFromStart(int data, int position)
  {
    Node *temp = head;
    Node *prev;
    while (temp != NULL && position--)
    {
      prev = temp;
      temp = temp->next;
    }
    Node *node = new Node(data);
    if (temp != NULL)
    {
      if (temp != head)
        temp->prev->next = node;
      node->prev = temp->prev;
      temp->prev = node;
      node->next = temp;
      if (temp == head)
        head = node;
    }
    else
    {
      prev->next = node;
      node->prev = prev;
      tail = node;
    }
  }

  void printList()
  {
    Node *temp = head;
    if (temp == NULL)
    {
      cout << "Empty List" << endl;
    }
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
  void deleteNodeFromStart(int position)
  {
    Node *temp = head;
    // while loop to traverse to the specified node to delete;
    while (temp != NULL && position--)
      temp = temp->next;

    // 3 cases to check, if the node to be deleted is head, we have to update head.
    // If it is the last node, we have to update tail.
    // If it is any node in between, we have to update its previous node's and next node's pointers.
    if (temp != NULL)
    {
      if (temp == head)
      {
        head = head->next;
        head->prev = NULL;
      }
      else if (temp->next == NULL)
      {
        tail = tail->prev;
        tail->next = NULL;
      }
      else
      {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
      }

      delete temp;
    }
  }
};

int main()
{
  // Initializing the doubly linked list with a single node having data 1;
  Node *n = new Node(1);
  DoublyLinkedList l(n, n);

  // Adding two new nodes having data 2 and 3;
  l.insertNodeFromStart(2, 1);
  l.insertNodeFromStart(3, 2);
  l.insertNodeFromStart(4, 3);

  // Linked List initially would look like 1 -> 2 -> 3;

  l.printList();
  int input1;
  cout << "Enter which node to delete (0-based indexing) : " << endl;
  cin >> input1;
  l.deleteNodeFromStart(input1);

  // Printing the list again to check if the node was deleted or not;
  l.printList();
}