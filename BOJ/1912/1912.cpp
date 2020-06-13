#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int dp[100001];


int main()
{
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> arr[i];

    dp[1] = arr[1];
    int ans = arr[1];   
    
    for(int i=2; i<=n; i++)
    {
        if(dp[i-1] < 0)
            dp[i] = arr[i];
        else
            dp[i] = dp[i-1] + arr[i];        

        if(ans < dp[i])
        {
            ans = dp[i];
        }    
    }

    printf("%d\n", ans);

    return 0;
}