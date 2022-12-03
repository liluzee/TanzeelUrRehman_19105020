#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int d, Node *l = NULL, Node *r = NULL)
  {
    data = d;
    left = l;
    right = r;
  }
};

// Utility function to get inOrder Traversal of the tree.
void inOrder(Node *n)
{
  if (n == NULL)
    return;
  inOrder(n->left);
  cout << n->data << " ";
  inOrder(n->right);
}

// Function that inserts a new node with value v into the tree.
Node *insertNode(Node *root, int v)
{
  if (root == NULL)
  {
    root = new Node(v);
  }
  else if (root->data <= v)
  {
    root->right = insertNode(root->right, v);
  }
  else if (root->data > v)
  {
    root->left = insertNode(root->left, v);
  }

  return root;
}

// Function that takes an array vector as input converts it into a BST and returns the root.
Node *arrayToBST(vector<int> arr, int start, int end)
{

  // Base condition for recursion
  if (start > end)
    return NULL;

  int mid = start + (end - start) / 2;

  // Create a new node with the middle element
  Node *current = new Node(arr[mid]);

  // Recursively call it on the left and right halves of the array to construct the respective subtree.
  current->left = arrayToBST(arr, start, mid - 1);
  current->right = arrayToBST(arr, mid + 1, end);
  return current;
}

// Utility function to find the node with minimum value.
Node *minValueNode(Node *n)
{
  Node *current = n;
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Function to delete the node with value data and returns the new root node.
Node *deleteNode(struct Node *root, int data)
{
  if (root == NULL)
    return root;

  // If the root's data is smaller than the our node to be deleted,
  // that means the node to be deleted is in the left subtree.
  if (data < root->data)
    root->left = deleteNode(root->left, data);

  // If the root's data is larger than the our node to be deleted,
  // that means the node to be deleted is in the right subtree.
  else if (data > root->data)
    root->right = deleteNode(root->right, data);

  // If neither of the two conditions work, that means the root is the element to be deleted.
  else
  {
    // If the node to be deleted has no children, then we can simply delete the node and replace it with NULL.
    if (root->left == NULL and root->right == NULL)
      return NULL;
    // If the node has only one child subtree, then replace the node with that subtree
    else if (root->left == NULL)
    {
      Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      free(root);
      return temp;
    }

    // For node with two children, we get the inorder successor
    // that is the smallest node in the right subtree.
    struct Node *temp = minValueNode(root->right);

    // Then we copy the inorder successor's content to this node
    root->data = temp->data;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int main()
{
  int n;
  cout << "Enter the number of elements : ";
  cin >> n;

  vector<int> arr(n);
  cout << "Input the elements : ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  // In order to convert an array to BST, first we have to sort it.

  sort(arr.begin(), arr.end());

  Node *root = arrayToBST(arr, 0, arr.size() - 1);

  while (true)
  {
    cout << "The inorder traversal of the tree looks like : " << endl;
    inOrder(root);
    cout << endl;

    cout << "Input 1 for inserting" << endl;
    cout << "Input 2 for deleting" << endl;
    cout << "Input 3 to exit" << endl;

    int choice;
    cin >> choice;
    if (choice == 1)
    {
      cout << "Enter the number to insert:" << endl;
      int ip;
      cin >> ip;
      root = insertNode(root, ip);
    }
    else if (choice == 2)
    {
      cout << "Enter the number to delete:" << endl;
      int ip;
      cin >> ip;
      root = deleteNode(root, ip);
    }
    else
    {
      break;
    }
  }
}
