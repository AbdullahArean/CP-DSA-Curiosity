#include<bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(vector<int> &a, int n, int i){
     int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && a[l] > a[largest])
    largest = l;
  if (r < n && a[r] > a[largest])
    largest = r;

  if (largest != i)
  {
    swap(&a[i], &a[largest]);
    heapify(a,n, largest);
  }

}
void heapsort(vector<int> &a){
    int n= a.size();
    for(int i=n/2-1; i>= 0; i--){
        heapify(a,n, i);
    }
    for(int i=n-1; i>0 ; i--){
        swap(&a[0], &a[i]);
        heapify(a, i,0);
    }

}
int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    heapsort(a);
     for(int i=0; i<n; i++) cout<<a[i]<<endl;
    return 0;
}