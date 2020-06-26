#include <iostream>

using namespace std;

const int SIZE = 3*3*3*3*3*3*3;

int n;
int paper[SIZE+1][SIZE+1];
int m_one, zero, one;
void slice(int x,int y, int size)
{
    int color = paper[x][y];
    bool is_different = false;
    for(int i=x; i<x+size;i++)
    {
        for(int j=y; j<y+size;j++)
        {
            if(paper[i][j] != color)
            {
                is_different = true;
                break;
            }
        }
    }

    if(is_different)
    {
        slice(x, y, size/3);
        slice(x, y + size/3, size/3);
        slice(x, y + 2* size/3, size/3);
        slice(x + size/3, y, size/3);
        slice(x + size/3, y + size/3, size/3);
        slice(x + size/3, y + 2* size/3, size/3);
        slice(x + 2* size/3, y, size/3);
        slice(x + 2* size/3, y + size/3, size/3);
        slice(x + 2* size/3, y + 2* size/3, size/3);
    }
    else
    {
        if(color == -1)
            m_one++;
        else if(color == 0)
            zero++;
        else
            one++;        
    }   
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> paper[i][j];
        }
    }
    slice(0,0,n);
    cout << m_one << '\n' << zero << '\n' << one <<'\n';

    return 0;
}