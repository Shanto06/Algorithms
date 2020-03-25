#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];

void merge(int a[],int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int temp[100];
    int j=mid+1;
    int k=s;

    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=e)
    {
        temp[k++]=a[j++];
    }

    for(int i=s;i<=e;i++)
    {
        a[i]=temp[i];
    }
}

void mergeSort(int a[],int s,int e)
{
    if(s<e)
    {
        int mid=(s+e)/2;
        mergeSort(a,s,mid);
        mergeSort(a,mid+1,e);
        merge(a,s,e);

    }

}
int main()
{

    cout<<"Enter array size: ";
    cin>>n;
    cout<<"Enter array Element: ";

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergeSort(a,0,n-1);

    cout<<"Sorted array: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }


    return 0;
}
