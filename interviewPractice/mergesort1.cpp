#include <iostream>
#include <climits>

using namespace std;

void merge(int arr[], int p, int q, int r)
{
  int n1 = q-p+1, n2 = r-q;
  int arr1[n1+1], arr2[n2+1];
  arr1[n1] = INT_MAX, arr2[n2] = INT_MAX;
  for(int i = 0 ; i < n1;++i)
    arr1[i] = arr[p+i];
  for (int i = 0 ; i < n2; ++i)
    arr2[i] = arr[q+1+i];
  int i = 0, j = 0, k = p;
  for(k = p ; k <= r; ++k)
  {
    if (arr1[i] <= arr2[j])
    {
      arr[k] = arr1[i];
      i += 1;
    }
    else
    {
      arr[k] = arr2[j];
      j+=1;
    }
  }
}

void mergesort(int arr[], int p, int r)
{
  if (p < r)
  {
    int q = (p+r)/2;
    mergesort(arr,p,q);
    mergesort(arr,q+1,r);
    merge(arr,p,q,r);
  }
}

int main()
{
  int n;
  //cin >> n;
  int arr[] = {9,3,6,1,2,6};
  mergesort(arr,0,5);
  for(int i = 0 ; i < 6; ++i)
    cout << arr[i] << " ";
  return 0;
}
