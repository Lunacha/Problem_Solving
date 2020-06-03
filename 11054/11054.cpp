#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
int dp[1001];
int r_dp[1001];
int ans = 0;

int main()
{
    cin >> n;
    for(int i=1; i<=n;i++)
        cin >> arr[i];
    

    for(int i=1;i<=n;i++)
    {
        dp[i] = 1;
        for(int j=1; j<=i; j++)
        {
            if(arr[j]<arr[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }

    for(int i= n; i >= 1; i--)
    {
        r_dp[i] = 1;
        for(int j=n; j >= i; j--)
        {
            if(arr[j] < arr[i] && r_dp[i] < r_dp[j] + 1)
                r_dp[i] = r_dp[j] + 1;
        }
    }

    for(int i=0; i<=n; i++)
    {
        if( ans < dp[i] + r_dp[i])
            ans = dp[i] + r_dp[i]-1;
    }

    /*for(int i=2;i<=n;i++)
    {
        bool flag1 = false;
        bool flag2 = false;

        dp[i][0] = 0;
        dp[i][1] = 0;

        for(int j=1; j<i;j++)
        {
            if(arr[i] > arr[j])
            {
                if(dp[i][1] < dp[j][1])
                {
                    dp[i][1] = dp[j][1];
                }
                flag1 = true;
            }
            else if(arr[i] < arr[j])
            {
                if(dp[j][1] > 1)
                {
                    int select = max(dp[j][0],dp[j][1]+1);
                    if(dp[i][0] < select)
                        dp[i][0] = select;
                    flag2 = true;
                }
            }
        }
        if(flag1)
            dp[i][1]++;
        if(flag2)
            dp[i][0]++;
            
        if(ans < dp[i][0])
            ans = dp[i][0];
    }*/

    cout << ans <<'\n';

    return 0;
}