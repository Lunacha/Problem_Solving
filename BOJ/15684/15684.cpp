#include <iostream>

using namespace std;

bool line[40][20];
int n,m,h;
int MIN = 4;

bool simulate()
{
    bool res = true;
    int node[n+1];
    for(int i=1; i<=n;i++)
        node[i] = i;
    for(int i=1; i<=h;i++)
    {
        for(int j=1; j<=n-1;j++)
        {
            if(line[i][j])
            {
                int temp = node[j];
                node[j] = node[j+1];
                node[j+1] = temp;
            }
        }
    }
    for(int i=1; i<=n;i++)
    {
        if(node[i] != i)
            return false;
    }

    return true;
}

void draw_line(int start, int num)
{
    if(num == 4)
        return;   
    if(simulate())
    {
        if(MIN > num)
            MIN = num;
        return;
    }

    for(int i=start; i<=h; i++)
    {
        for(int j=1; j<=n-1; j++)
        {
            if(line[i][j] || line[i][j-1] || line[i][j+1])
                continue; 
            line[i][j] = true;   
            draw_line(i, num+1);        
            line[i][j] = false;
        }
    }   
}

int main()
{
    cin >> n >> m >> h;
    
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        line[a][b] = true;
    }

    draw_line(1,0);
    
    if(MIN != 4)
        cout << MIN << "\n";
    else
        cout << -1 << "\n";
    

    return 0;
}