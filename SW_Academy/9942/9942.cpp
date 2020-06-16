#include <iostream>
#include <algorithm>

using namespace std;

int t,n,k;
long long cnt;
int fac[11];
bool visit[11];
void dfs(int cur, int sum)
{
    if (cur == n)
    {
        if( sum + n >= k)
            cnt++;
        return;
    }
    for(int i= 1; i<=n; i++)
    {
        if(!visit[i])   
        {
            visit[i] = true;
            dfs(cur+1, sum + max(cur, i));
            visit[i] = false;       
        }
        
    }  
}

int main()
{
    cin >> t;
    
    fac[0] = 1;

    for(int i=1; i<=10; i++)
            fac[i] = fac[i-1] * i;

    for(int i=1; i<=t; i++)
    {
        cnt = 0;
        cin >> n >> k;
        
        dfs(1,0);
        printf("#%d %lld\n", i, fac[n] * cnt);
    }

    
    return 0;
}