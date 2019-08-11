#include <iostream>
#include <limits.h>
using namespace std;

template <class T> void Swap ( T& a, T& b )
{
  T c(a); a=b; b=c;
}

int partition(int arr[],int p, int r)
{
  int x = arr[r];
  int i = p-1, j = p;
  for (j = p; j < r; ++j)
  {
    if (arr[j] <= x)
    {
      Swap(arr[i],arr[j]);
      i += 1;
    }
  }
  swap(arr[r], arr[i+1]);
  return i+1;
}

void quicksort(int arr[], int p, int r)
{
  if (p < r)
  {
    int q = partition(arr,p,r);
    quicksort(arr,p,q-1);
    quicksort(arr,q+1,r);
  }
}

int main()
{
  int arr[] = {9,3,6,1,2,6};
  quicksort(arr,0,5);
  for (int i = 0 ; i < 6; ++i)
    cout << arr[i] << " ";
  cout << INT_MAX << endl;
}
