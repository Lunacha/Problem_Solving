#include <iostream>

using namespace std;
int n,m;
int arr[9];
bool check[9];

void dfs(int cnt)
{   
    if(cnt == m)
    {        
        for(int i = 0; i<m ; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    

    for(int i = 1; i<=n; i++)
    {
        if(!check[i])
        {
            check[i] = true;
            arr[cnt] = i;
            dfs(cnt+1);
            check[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;

    dfs(0);

    return 0;
}