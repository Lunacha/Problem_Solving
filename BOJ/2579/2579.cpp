#include <iostream>
#include <algorithm>

using namespace std;

int n;
int stair[300];
int dp[300];

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> stair[i];
    
    dp[0] = stair[0];
    dp[1] = stair[0] + stair[1];
    dp[2] = max(stair[0]+ stair[2], stair[1]+ stair[2]);

    for(int i=0; i<n; i++)
    {
        int dp1 = dp[i-2] + stair[i];
        int dp2 = dp[i-3] + stair[i-1] + stair[i];
        dp[i] = max(dp1,dp2);
    }

    printf("%d\n",dp[n-1]);


    return 0;
}