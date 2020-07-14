#include <iostream>
#include <queue>

using namespace std;

int relation[105][105];
int bacon[105];
int n,m;

void check_relation(int user1, int user2)
{
    int visit[105] = {0,};
    queue<pair<int,int>> q;
    for(int i=1; i<=n; i++)
    {
        if(relation[user1][i] == 1)
            q.push(pair<int,int>(i,1));
    }
    while(!q.empty())
    {
        int user = q.front().first;
        int step = q.front().second;
        visit[user] = 1;
        q.pop();
        if(user == user2)
        {
            bacon[user1] += step;
            bacon[user2] += step;
            break;
        }
        else
        {
            for(int i=1; i<=n; i++)
            {
                if(relation[user][i] == 1 && visit[i] == 0)
                    q.push(pair<int,int>(i,step+1));
            }
        }
    }
}

int main()
{  
    cin >> n >> m;

    for(int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        relation[a][b] = 1;
        relation[b][a] = 1;
    }
    for(int i=1;i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            check_relation(i,j);
        }
    }

    int min = 10000;
    int min_user = 0;
    for(int i=1; i<=n; i++)
    {
        if(bacon[i] < min)
        {
            min = bacon[i];
            min_user = i;
        }    
    }

    cout<<min_user<< '\n';

    return 0;
}