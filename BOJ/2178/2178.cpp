#include <iostream>
#include <queue>

using namespace std;

int n,m;
char maze[105][105];
int check[105][105];
queue <pair<int,int>> q;

void bfs()
{
    check[0][0] = 1;
    q.push(pair<int,int>(0,0));

    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();

        if(p.first == n-1 && p.second == m-1)
        {
            cout << check[p.first][p.second] << '\n';
            break;
        }

        if(p.second>0 && maze[p.first][p.second-1] == '1' && check[p.first][p.second-1] ==0 )
        { 
            check[p.first][p.second-1] = check[p.first][p.second] + 1;    
            q.push(pair<int,int>(p.first,p.second-1));
        }
        if(p.second < m-1 && maze[p.first][p.second+1] == '1' && check[p.first][p.second+1] ==0)
        {
            check[p.first][p.second+1] = check[p.first][p.second] + 1;    
            q.push(pair<int,int>(p.first,p.second+1));
        }       
        if(p.first>0 && maze[p.first-1][p.second] == '1' && check[p.first-1][p.second]==0)
        {
            check[p.first-1][p.second] = check[p.first][p.second] + 1;    
            q.push(pair<int,int>(p.first-1,p.second));
        }    
        if(p.first<n-1 && maze[p.first+1][p.second] == '1' && check[p.first+1][p.second]==0)
        {
            check[p.first+1][p.second] = check[p.first][p.second] + 1;    
            q.push(pair<int,int>(p.first+1,p.second));
        }
    }
}

int main()
{
    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        cin >> maze[i];    
    }

    bfs();

    return 0;
}