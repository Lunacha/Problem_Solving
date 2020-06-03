#include <iostream>
#include <cstring>

using namespace std;

int n;
long long dp[101];
long long endi[10];

int main()
{
    cin >> n;
   
    for(int i=1;i<10;i++)
        endi[i] = 1;
    endi[0] = 0;

    dp[1] = 9;

    for(int i=2; i<=n; i++)
    {
        int arr[10] = {0,};   

        for(int j=0; j<10; j++)
        {
            if(j == 0)
                arr[j+1] += endi[j];
            else if(j == 9)
                arr[j-1] += endi[j];
            else
            {
                arr[j+1] += endi[j];
                arr[j-1] += endi[j];
            }      
        }

        for(int j=0;j<10;j++)
            endi[j] = arr[j] % 1000000000;

        for(int j=0; j<10; j++)
            dp[i] += endi[j];
        dp[i] %= 1000000000;
        
    }

    printf("%lli\n", dp[n]);

    return 0;
}