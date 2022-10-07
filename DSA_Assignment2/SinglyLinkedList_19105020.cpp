#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *next;

  // Constructor for creating a node.
  Node(int d)
  {
    this->data = d;
    this->next = NULL;
  }
};

class LinkedList
{
public:
  Node *head;
  LinkedList(Node *m)
  {
    this->head = m;
  }
  void insertAfterN(int n, int d)
  {
    Node *temp = head;

    // Edge case in which I'll have to update head of the linked list;
    if (n == 0)
    {
      Node *newN = new Node(d);
      newN->next = head;
      head = newN;
      return;
    }
    // For loop to travel to the point of insertion
    for (int i = 0; i < n - 1; i++)
    {
      if (temp->next != NULL)
        temp = temp->next;
    }

    // Simply creating a new node and inserting in the list by updating next values
    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
  }

  void insertAfterNvalue(int n, int d)
  {
    Node *temp = head;

    // This loop takes our temp pointer to the required value, after which we want to insert our element.
    while (temp != NULL && temp->data != n)
    {
      temp = temp->next;
    }

    // Now we create a new node, and just update the next pointers to fit it into the linked list;
    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
  }

  void printList()
  {
    Node *t = head;
    while (t != NULL)
    {
      cout << t->data << " ";
      t = t->next;
    }
    cout << endl;
  }
};

/*
Create a singly linked list. Perform Insertion of an element
after a Specified Value (given by the user at run time)

This can be interpreted in two ways, the user gives the value of the node after
which the insertion is to be made, or the user gives us the number of nodes after
which the insertions is to be made. (The user gives the data of the new node in both cases);


For this I have implemented two functions,
The first function, insertAfterN, simply takes the number of nodes after which the insertion is to be made,
The second function, insertAfterNvalue, takes a value and looks for the value in the linked list, and
then inserts the new node after the node which contains this given value.
*/

int main()

{
  // Creating a dummy linked list l
  // which contains 1 -> 2 -> 3
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);

  n1->next = n2;
  n2->next = n3;

  LinkedList l(n1);

  cout << "Initially my linked list is : " << endl;
  l.printList();

  cout << endl;
  int input1;
  cout << "Input after which element do you want to insert the new element?" << endl;
  cin >> input1;

  int input2;
  cout << "Input the value for the new element : " << endl;
  cin >> input2;

  l.insertAfterNvalue(input1, input2);

  cout << endl;
  cout << "Now the linked list is : " << endl;
  l.printList();
  cout << endl;

  int input3;
  cout << "Input after how many elements do you want to insert the new element?" << endl;
  cin >> input3;

  int input4;
  cout << "Input the value for the new element : " << endl;
  cin >> input4;

  l.insertAfterN(input3, input4);
  l.printList();
}