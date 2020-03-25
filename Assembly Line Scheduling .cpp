#include<bits/stdc++.h>
#include<vector>
using namespace std;

int assemblyLineScheduling(int n, vector<int> entry, vector<int> exit, vector<vector<int> > processing, vector<vector<int> > transfer)
{
    vector<vector<int> > dp(2, vector<int>(n+1));
    int i;


    dp[0][0]=entry[0]+processing[0][0];
    dp[1][0]=entry[1]+processing[1][0];

    for(i=1;i<n;i++)
    {

        dp[0][i]=min(dp[0][i-1],dp[1][i-1]+transfer[1][i-1])+processing[0][i];
        dp[1][i]=min(dp[1][i-1],dp[0][i-1]+transfer[0][i-1])+processing[1][i];



    }


    dp[0][n]=dp[0][n-1]+exit[0];
    dp[1][n]=dp[1][n-1]+exit[1];



    return min(dp[0][n],dp[1][n]);
}

int main()
{
    int i,n;
    vector<int> entry(2), exit(2);

    cout<<"Enter the number of stations ";
    cin>>n;

    vector<vector<int> > processing(2, vector<int> (n));
    vector<vector<int> > transfer(2, vector<int> (n-1));

    cout<<"Enter the entry time for assembly line 1 and 2 respectively"<<endl;
    cin>>entry[0]>>entry[1];


    cout<<"Enter the exit time for assembly line 1 and 2 respectively"<<endl;
    cin>>exit[0]>>exit[1];

    cout<<"Entry the processing time at all staions on assembly line 1"<<endl;
    for(i=0;i<n;i++)
        cin>>processing[0][i];

    cout<<"Entry the processing time at all staions on assembly line 2"<<endl;
    for(i=0;i<n;i++)
        cin>>processing[1][i];

    cout<<"Enter the transfer time from each station of assembly line 1 to next station of assembly line 2"<<endl;
    for(i=0;i<n-1;i++)
        cin>>transfer[0][i];

    cout<<"Enter the transfer time from each station of assembly line 2 to next station of assembly line 1"<<endl;
    for(i=0;i<n-1;i++)
        cin>>transfer[1][i];

    cout<<"The minimum time required to get all the jobs done is "<<endl;
    cout<<assemblyLineScheduling(n, entry, exit, processing, transfer);


    cout<<endl;
    return 0;
}
