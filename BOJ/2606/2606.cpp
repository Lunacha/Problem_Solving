# include <iostream>

using namespace std;

int com[101][101];
int visit[101];
int n, e, x, y;
int com_n;

void dfs(int cur)
{
    for(int i=1; i<= n; i++)
    {
        if(com[cur][i] == 1 && visit[i] == 0)
        {
            visit[i] = 1;
            com_n++;
            dfs(i); 
        }
    }
}

int main()
{
    cin >> n >> e;
    for(int i=0; i<e; i++)
    {
        cin >> x >> y;
        com[x][y] = 1;
        com[y][x] = 1;
    }
    visit[1] = 1;
    dfs(1);
    cout << com_n << '\n';
    return 0;
}