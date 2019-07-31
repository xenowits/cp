#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void merge(vector<int> &v, int p, int q, int r)
{
  int n1 = q-p+1, n2 = r-q;
  int arr1[n1+1], arr2[n2+1];
  for(int i = 0 ; i < n1; ++i)
    arr1[i] = v[p+i];
  for(int i = 0 ; i < n2; ++i)
    arr2[i] = v[q+1+i];

  arr1[n1] = INT_MAX, arr2[n2] = INT_MAX;
  int i = 0 , j = 0, k;

  for(k = p; k <= r; ++k)
  {
    if (arr1[i] <= arr2[j])
    {
      v[k] = arr1[i];
      i+=1;
    }
    else
    {
      v[k] = arr2[j];
      j+=1;
    }
  }
}

void mergeSort(vector<int> &v, int p, int r)
{
  if (p<r)
  {
    int q = (p+r)/2;
    mergeSort(v,p,q);
    mergeSort(v,q+1,r);
    merge(v,p,q,r);
  }
}

void max_heapify(vector<int> &v, int i,int n)
{
  int l = 2*i+1, r = 2*i+2, largest;
  if (l < n && v[l] > v[i])
    largest = l;
  else
    largest = i;
  if (r < n && v[r] > v[largest])
    largest = r;
  if (largest != i)
  {
    swap(v[i], v[largest]);
    max_heapify(v,largest,n);
  }
}

void heapSort(vector<int> &v, int n)
{
  // build max_heap
  for(int i = n/2-1; i >= 0; --i)
  {
    max_heapify(v,i,n);
  }
  int N = n;
  for(int i = n-1; i >= 1; --i)
  {
    swap(v[i],v[0]);
    N -= 1;
    max_heapify(v,0,N);
  }
}

int main()
{
  vector<int> v{7,2,123,6,5,4,3};
  int n = v.size();
  //mergeSort(v,0,n-1);
  heapSort(v,n);
  for(int i = 0; i < v.size();++i)
    cout << v[i] << " ";
}
