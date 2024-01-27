
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    string s;
    cin>>n>>s;
    string s1=s,s2=s;
    reverse(s2.begin(),s2.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << n - dp[n][n]<<endl;;

    return 0;
}
