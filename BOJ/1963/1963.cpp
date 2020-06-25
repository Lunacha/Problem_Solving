#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int T;
int n[2];
int prime[10001];

int bfs(queue<pair<int,int>> q, int visit[])
{
    while(!q.empty())
    {
        pair<int,int> element = q.front();
        q.pop();
        int num = element.first;
        int mov = element.second;
        
        int digit = 1000;
        int slice = num;
        while(digit> 0)
        {
            int a = slice / digit;    
            int k = num - a * digit;
            int start = 0;
            if(digit == 1000)
                start = 1;
            for(int i=start; i<=9; i++)
            {      
                int cur = i*digit + k;
                if(prime[cur] == 0 && visit[cur] == 0)
                {
                    if(cur == n[1])
                    {     
                        return mov + 1;
                    }
                    visit[cur] = 1;
                    q.push(pair<int,int>(cur,mov+1));
                }
            }
            slice %= digit;
            digit /= 10;
        }
    }
    return -1;
}

int main()
{
    cin >> T;

    for(int i=2; i<=1000; i++)
    {
        for(int j=1; i*j<10000; j++)
        {
            if(prime[i*j] != 1)
                prime[i*j] = 1;
        }
    }

    for(int i=0; i<T; i++)
    {
        queue<pair<int,int>> q;
        int visit[10001] = {0,};
        for(int j=0; j<2; j++)
        {
            cin >> n[j];
        }
        if(n[0] == n[1])
        {
            cout << 0 << '\n';
            continue;
        }
        q.push(pair<int,int>(n[0],0));
        visit[n[0]] = 1;
        int res = bfs(q,visit);
        if(res == -1)
            cout << "Impossible\n";
        else
            cout << res << '\n';
        
    }

    return 0;
}