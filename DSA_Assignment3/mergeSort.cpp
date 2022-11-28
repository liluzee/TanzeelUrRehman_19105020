#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Merge sort requires two different functions,
// the merge function to merge two sorted arrays
// and the mergeSort function which divides the array, sorts them and calls the merge function.
// Merge two subarrays L and M into arr

// utility function for printing the array
void printArr(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// merge function which takes as input three integers which denote
// p -> start of first array
// q -> end of first array, and q + 1 is the start of second array
// r -> end of second array
void merge(vector<int> &arr, int p, int q, int r)
{

  // Create two new arrays from the three pointers that we have.
  // Create L <- A[p..q] and M <- A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  vector<int> L(n1);
  vector<int> M(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2)
  {
    if (L[i] <= M[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &arr, int l, int r)
{
  if (l < r)
  {
    // m is the mid point where we divide the array
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}
int main()
{
  vector<int> a;

  // input the number of elements
  int n;
  cout << "Input the number of elements : ";
  cin >> n;

  cout << "Input the elements : " << endl;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  mergeSort(a, 0, a.size() - 1);

  cout << "Sorted array : " << endl;
  printArr(a);
}