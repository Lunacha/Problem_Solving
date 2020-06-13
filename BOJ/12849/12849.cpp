#include <iostream>
#define MOD 1000000007

using namespace std;

long long dp[8][100000];
int up_dp[8][100000];
int d;
int map[8][8] = 
{{0,1,0,1,0,0,0,0},
{1,0,1,1,0,0,0,0},
{0,1,0,1,1,1,0,0},
{1,1,1,0,0,1,0,0},
{0,0,1,0,0,1,1,0},
{0,0,1,1,1,0,0,1},
{0,0,0,0,1,0,0,1},
{0,0,0,0,0,1,1,0}};

int main()
{
    cin >> d;

    dp[1][0] = 1;
    dp[3][0] = 1;

    for(int j =1; j<d; j++)
    {
        for(int i =0; i<8; i++)
        {
            for(int k=0; k<8; k++)
            {
                if(map[i][k] == 1)
                    dp[i][j] += dp[k][j-1];
            }
            dp[i][j] %= MOD;
            
        }
    }

    cout << dp[0][d-1] << '\n';


    return 0;
}