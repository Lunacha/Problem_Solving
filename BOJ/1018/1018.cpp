#include <iostream>

using namespace std;

char chess[50][50];
int n,m;
char wb[2] = {'W','B'};

int count(int x,int y, int black)
{
    int cnt = 0;
    int start;
    int lane;

    for(int i=x; i<x+8; i++)
    {
        start = black;
        lane = start;
        for(int j=y; j<y+8; j++)
        {
            if(chess[i][j] != wb[lane%2])
            {  
                cnt++;
            }
            lane++;
        }
        black++;
    }

    return cnt;
}

int main()
{
    cin >> n;
    cin >> m;
    int aws = 2500;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>chess[i][j];
    }

    for(int i=0; i<=n-8;i++)
    {
        for(int j=0; j<=m-8;j++)
        {
            int cnt1 = count(i,j,0);
            int cnt2 = count(i,j,1);
            int cnt = cnt1 < cnt2 ? cnt1 : cnt2;
            if(aws > cnt)
                aws = cnt;
        } 
    }


    cout<< aws<<endl;


    return 0;
}