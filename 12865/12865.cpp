#include <iostream>
#include <algorithm>

using namespace std;

int n,k;
int w[101];
int v[101];
int dp[101][100001];

int main()
{
    cin >> n >> k;

    int ans = 0;

    for(int i=1; i<=n; i++)
        cin >> w[i] >> v[i];

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j - w[i] >=0)
                dp[i][j] = max(dp[i-1][j-w[i]] + v[i], dp[i-1][j]);

            if(ans < dp[i][j])
                ans = dp[i][j];
        }
    }

    cout << ans << '\n';
    
    return 0;
}