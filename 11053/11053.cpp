#include <iostream>

using namespace std;

int n;
int arr[1001];
int dp[1001];

int main()
{
    cin >> n;

    int ans = 1;

    for(int i=1; i<=n; i++)
        cin >> arr[i];

    dp[1] = 1;
    
    for(int i=2; i<=n; i++)
    {
        dp[i] = 0;
        for(int j=1; j<i; j++)
        {
            if(arr[i] > arr[j])
            {
                if(dp[i] < dp[j])
                    dp[i] = dp[j];
            }
        }
        dp[i]++;
        if(ans < dp[i])
            ans = dp[i];    
    }

    cout << ans << '\n';

    return 0;
}