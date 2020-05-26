#include <iostream>
#include <vector>

using namespace std;

int mat[9][9] = {0,};
vector<pair<int,int>> blank;

bool check_condition(int r, int c, int i)
{
    for(int k=0; k<9; k++)
    {
        if(mat[r][k] == i)
            return false;
        if(mat[k][c] == i)
            return false;
    }

    int a = r/3;
    int b = c/3;

    for(int k=a*3; k<a*3+3; k++)
    {
        for(int l=b*3; l<b*3+3; l++)
        {
            if(mat[k][l] == i)
                return false;
        }
    }

    return true;
}

void dfs(int cnt)
{
    if( cnt == blank.size())
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
                cout<<mat[i][j]<<' ';
            cout << '\n'; 
        }
        exit(0);
    }

    for(int i=1; i<=9; i++)
    {
        int r = blank[cnt].first;
        int c = blank[cnt].second;
        if(check_condition(r,c,i))
        {
            mat[r][c] = i;
            dfs(cnt + 1);
            mat[r][c] = 0;
        }
    }
}

int main()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin>>mat[i][j];

            if(mat[i][j] == 0)
                blank.push_back(make_pair(i,j));
        }
    }

    dfs(0);

    return 0;
}