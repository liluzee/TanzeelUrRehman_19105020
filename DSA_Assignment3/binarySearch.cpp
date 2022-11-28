#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &arr, int key, int start, int end)
{
  if (start > end)
    return -1;

  int mid = start + (end - start) / 2;

  if (arr[mid] == key)
  {
    return mid;
  }

  if (arr[mid] > key)
  {
    return binarySearch(arr, key, start, mid - 1);
  }
  else
  {
    return binarySearch(arr, key, mid + 1, end);
  }
}
int main()
{
  vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  int key;
  cin >> key;
  cout << endl;
  cout << binarySearch(a, key, 0, a.size() - 1);
}