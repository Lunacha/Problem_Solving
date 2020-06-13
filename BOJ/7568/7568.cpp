#include <iostream>

using namespace std;

int man[50][2];
int n;
int r[50] = {0,};

int main()
{
    
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>man[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n;j++)
        {
            if(man[i][0] > man[j][0] && man[i][1] > man[j][1])
                r[j]++;
            else if(man[i][0] < man[j][0] && man[i][1] < man[j][1])
                r[i]++;
        }
    }

    for(int i =0; i<n;i++)
        cout<<r[i]+1<<" ";

    return 0;
}