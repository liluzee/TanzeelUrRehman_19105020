#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// utility function for printing the array
void printArr(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// utility function to swap two elements
void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;

  return;
}

void bubbleSort(vector<int> &arr, int n)
{
  int i, j;

  int comparisonCount = 0;
  int swapCount = 0;
  bool swapped;
  for (i = 0; i < n - 1; i++)
  {
    swapped = false;
    for (j = 0; j < n - i - 1; j++)
    {
      comparisonCount++;
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swapCount++;
        swapped = true;
      }
    }
    if (swapped == false)
      break;
  }
  cout << "Comparisons : " << comparisonCount << endl;
  cout << "Swaps : " << swapCount << endl;
}

void selectionSort(vector<int> &arr, int n)
{
  int swapCount = 0;
  int comparisonCount = 0;
  for (int i = 0; i < n - 1; i++)
  {

    int min_idx = i;
    for (int j = i + 1; j < n; j++)
    {
      comparisonCount++;
      if (arr[j] < arr[min_idx])
        min_idx = j;
    }
    if (min_idx != i)
    {
      swap(arr[min_idx], arr[i]);
      swapCount++;
    }
  }

  cout << "Comparisons : " << comparisonCount << endl;
  cout << "Swaps : " << swapCount << endl;
}

// In this implementation, for a given input
// we can see the number of comparisons and swaps that both the algorithms will make.

// In the worst case, that is a reverse sorted array for bubble sort, it will take
// O(n^2) swaps and the same number of comparisons.
// In the best case, it will make O(n) comparisons and stop after the first pass.

// In all cases selection sort will make O(n^2) comparisons and will make at most n-1 swaps.
int main()
{
  vector<int> a;
  vector<int> b;

  int n;
  cout << "Input the number of elements : ";
  cin >> n;

  cout << "Input the elements : " << endl;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
    b.push_back(tmp);
  }

  cout << "Bubble sort stats : " << endl;
  bubbleSort(a, a.size());

  cout << "Selection sort stats : " << endl;
  selectionSort(b, b.size());
}