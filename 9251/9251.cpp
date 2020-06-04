#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char a[1001], b[1001];
int dp[1001][1001];

int main()
{
    scanf("%s %s", a, b);
    int len_a = strlen(a);
    int len_b = strlen(b);
 
    for(int i=1; i<=len_a; i++)
    {
        for(int j=1; j<=len_b; j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }    
        }
    }

    printf("%d\n", dp[len_a][len_b]);


    return 0;
}