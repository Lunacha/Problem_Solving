#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, V;
int mat[1001][1001];
int visit[1001];

void dfs(int v)
{
    cout << v << ' ';
    visit[v] = 1;
    for(int i=1; i<=N; i++)
    {
        if(visit[i] == 0 && mat[v][i] == 1)
            dfs(i);
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    visit[v] = 1;
    while(!q.empty())
    {
        v = q.front();
        cout << q.front() << ' ';
        q.pop();
        for(int i=1; i<=N; i++)
        {
            if(visit[i] == 0 && mat[v][i] == 1)
            {
                q.push(i);
                visit[i] = 1;
            }
        }
    }
}

int main()
{
    int x, y;
    cin >> N >> M >> V;
    for(int i=0; i<M; i++)
    {
        cin >> x >> y;
        mat[x][y] = mat[y][x] = 1;
    }
    dfs(V);
    memset(visit,0,sizeof(visit));
    cout << '\n';
    bfs(V);

    return 0;
}