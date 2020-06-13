#include <iostream>

using namespace std;

int n;
int ans;
int col[16];

bool check(int cnt, int i)
{
    int x;
    for( x =1; x<cnt; x++)
    {
        if(i == col[x])
            return false;

        if(cnt-x == abs(i - col[x]))
            return false;
    }
    
    return true;
}

void dfs(int cnt)
{
    if(cnt == n)
    {
        ans++;
    }
    else
    {
        for(int i =1; i<=n; i++)
        {      
            if(check(cnt+1,i))
            {
                col[cnt+1] = i;
                dfs(cnt+1);
                col[cnt+1] = 0;
            }
            
        }    
    }
       
}

int main()
{
    scanf("%d", &n);
    dfs(0);
    printf("%d\n", ans);
    return 0;
}