#include <iostream>

using namespace std;

int n;
char c[70][70];
int index = 0;

void slice(int startX, int startY, int size)
{
    char cr = c[startX][startY];

    bool flag = true;

    for(int i=startX; (i<startX+size)&&flag; i++)
    {
        for(int j=startY; (j<startY+size)&&flag; j++)
        {
            if(c[i][j] != cr)
                flag = false;
        }
    }

    if(!flag)
    {
        cout << "(";
        slice(startX,startY,size/2);
        slice(startX,startY+ size/2,size/2);
        slice(startX + size/2,startY,size/2);
        slice(startX + size/2,startY + size/2,size/2);
        cout << ")";
    }
    else
    {
        cout << cr;
    }
    
}

int main()
{
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> c[i];

    slice(0,0,n);
    return 0;
}