#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


int n;
int dp[1000001];

int main()
{
    cin >> n;
    memset(dp,0, sizeof(int)*(n+1));

    dp[1] = 0;

    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0)
            dp[i] = min(dp[i],dp[i/2] + 1);
        if(i%3 == 0)
            dp[i] = min(dp[i],dp[i/3] + 1);
    }

    printf("%d\n",dp[n]);

    return 0;
}