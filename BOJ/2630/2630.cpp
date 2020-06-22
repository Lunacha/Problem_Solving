#include <iostream>

using namespace std;

int n;
int p[128][128];
int w,b;

void slice(int startX, int startY, int size)
{
    int color = p[startX][startY];

    if( size == 1 )
    {
        if(color == 0)
            w++;
        else
            b++;
        return;     
    }
    
    bool flag = true;

    for(int i=startX; i<startX+size; i++)
    {
        bool brk = false;
        for(int j=startY; j<startY+size; j++)
        {
            if(p[i][j] != color)
            {
                flag = false;
                brk = true;
                break;
            }
        }
        if(brk)
            break;
    }

    if(flag)
    {
        if(color == 0)
            w++;
        else
            b++;
        return;
    }
    else
    {
        slice(startX, startY, size/2);
        slice(startX + size/2, startY, size/2);
        slice(startX, startY + size/2, size/2);
        slice(startX + size/2, startY + size/2, size/2); 
    }
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            scanf("%d",&p[i][j]);
    }

    slice(0,0,n);

    cout << w << '\n' << b << '\n';

    return 0;
}