#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class myStack
{
public:
  vector<char> charStack;

  // Pushes a character given as input to the stack;
  void push(char c)
  {
    charStack.push_back(c);
  }

  // Pops the current top element of the stack;
  void pop()
  {
    if (charStack.size() == 0)
      cout << "Stack is empty";
    charStack.pop_back();
  }

  // Returns the current top element of the stack;
  char top()
  {
    if (charStack.size() == 0)
      return '0';
    return charStack[charStack.size() - 1];
  }

  // Returns the current size of the stack;
  int size()
  {
    return charStack.size();
  }

  // Returns true if stack is empty, and false if it isn't;
  bool empty()
  {
    return (charStack.size() == 0);
  }
};

// isValid function takes a string as input
// and uses the myStack class implemented
// above to check if it has valid usage of parentheses.
bool isValid(string s)
{
  myStack s1;

  for (int i = 0; i < s.length(); i++)
  {
    // if we encounter an opening bracket, we push it to the stack
    if (s[i] == '{' || s[i] == '(' || s[i] == '[')
    {
      s1.push(s[i]);
      continue;
    }

    // if we encounter a closing bracket and it matches the current top of
    // the stack that is the most recent opening bracket, that means
    // we can remove it from our stack and they are valid.

    if (s[i] == '}')
    {
      // if we encounter a correct closing bracket, pop
      if (!s1.empty() && s1.top() == '{')
      {
        s1.pop();
        continue;
      }
      // if we encounter a closing bracket that is incorrectly placed,
      // for example, "[]}", when we encounter '}' in this string
      // we can simply return 0 because it will never be balanced and there's no
      // point checking further.
      else
        return 0;
    }
    if (s[i] == ')')
    {
      if (!s1.empty() && s1.top() == '(')
      {
        s1.pop();
        continue;
      }
      else
        return 0;
    }
    if (s[i] == ']')
    {
      if (!s1.empty() && s1.top() == '[')
      {
        s1.pop();
        continue;
      }
      else
      {
        return 0;
      }
    }
  }
  // In the end, if all the brackets were closed properly,
  // our stack would be empty and therefore the parantheses
  // would be balanced.
  if (s1.empty())
    return 1;
  else
    return 0;
}
int main()
{
  string s1 = "{}[](){{()}}";
  string s2 = "{[]}(";

  // in the above example, s1 has balanced usage of parantheses
  if (isValid(s1))
  {
    cout << "Given string has balanced parantheses" << endl;
  }
  else
  {
    cout << "Given string has unbalanced parantheses" << endl;
  }

  // s2 has unbalanced parantheses, and the output gives the same result.
  if (isValid(s2))
  {
    cout << "Given string has balanced parantheses" << endl;
  }
  else
  {
    cout << "Given string has unbalanced parantheses" << endl;
  }
}