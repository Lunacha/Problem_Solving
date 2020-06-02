#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int house[1000][3];
int dp[1000][3];

int main()
{
    cin >> n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<3; j++)
            cin >> house[i][j]; 
    }

    dp[0][0] = house[0][0];
    dp[0][1] = house[0][1];
    dp[0][2] = house[0][2];

    for(int i = 1; i<n; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + house[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + house[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + house[i][2];
    }

    int min = 1000001;
    for(int i=0; i<3; i++)
    {
        if(min > dp[n-1][i])
            min = dp[n-1][i];
    }

    printf("%d\n",min);

    return 0;
}