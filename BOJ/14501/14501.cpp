#include <iostream>

using namespace std;

int n;
int t[16];
int p[16];
int res = 0;

void dfs(int day, int pay)
{
    if(day == n+1)
    {
        if(pay >= res)
            res = pay;
        return;
    }
    
    if(day > n+1)
        return;

    dfs(day+t[day], pay+p[day]);
    dfs(day+1, pay);
}

int main()
{
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> t[i] >> p[i];

    dfs(1,0);

    cout << res << '\n';

    return 0;
}