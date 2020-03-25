#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000];
void maxheap(int i,int n)
{
    int largest=i;
    int l=2*i;
    int r=2*i+1;
    if(l<n && a[l]>a[i])
        largest=l;
    else
        largest=i;
    if(r<n && a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        swap(a[i],a[largest]);

        maxheap(n,largest);
    }
}

int main()
{

    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array element: ";
    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=n/2;i>=0;i--)
    {
        maxheap(i,n);
    }
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
