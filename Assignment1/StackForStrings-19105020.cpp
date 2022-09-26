#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class StackForStrings
{
public:
  vector<string> strings;

  // Pushes a string given as input to the stack;
  void push(string s)
  {
    strings.push_back(s);
  }

  // Pops the current top element of the stack;
  void pop()
  {
    if (strings.size() == 0)
      cout << "Stack is empty";
    strings.pop_back();
  }

  // Returns the current top element of the stack;
  string top()
  {
    if (strings.size() == 0)
      return "-1";
    return strings[strings.size() - 1];
  }

  // Returns the current size of the stack;
  int size()
  {
    return strings.size();
  }

  // Returns true if stack is empty, and false if it isn't;
  bool isEmpty()
  {
    return (strings.size() == 0);
  }
};

int main()

{

  StackForStrings s1;
  s1.push("1ac");
  s1.push("2ac");

  cout << s1.top() << endl;
  s1.pop();
  cout << s1.top() << endl;
  s1.pop();

  cout << s1.top();
}