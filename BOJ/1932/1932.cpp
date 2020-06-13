#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int t[500][500];
int dp[500][500];

int main()
{
    cin >> n ;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
            cin >> t[i][j];      
    }

    dp[0][0] = t[0][0];

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(j == 0)
                dp[i][j] = dp[i-1][j] + t[i][j];
            else if (j==i)
                dp[i][j] = dp[i-1][j-1] + t[i][j];
            else
                dp[i][j] = max(dp[i-1][j-1] , dp[i-1][j]) + t[i][j];
        }
    }

    int max = 0;

    for(int i=0; i<n; i++)
    {
        if(max < dp[n-1][i])
            max = dp[n-1][i];
    }

    printf("%d\n", max);

    return 0;
}