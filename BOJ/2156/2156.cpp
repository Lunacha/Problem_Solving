#include <iostream>
#include <algorithm>

using namespace std;

int n;
int wine[10001];
int dp[10001];

int main()
{
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> wine[i];

    dp[1] = wine[1];
    dp[2] = wine[1]+wine[2];
    dp[3] = max(wine[1]+wine[3],max(wine[1]+wine[2], wine[2]+wine[3]));

    for(int i=4; i<=n; i++)
    {
        int result = 0;
        result = max(dp[i-2] + wine[i], dp[i-3]+wine[i-1]+wine[i]);    
        result = max(result,dp[i-1]);
        dp[i] = result;
    }

    cout << dp[n] << '\n';


    return 0;

}