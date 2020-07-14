#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int t,n;
int house[2];
int rock[2];
int store[105][105];
int visit[105];
bool is_valid = false;

void dfs(int pos_x, int pos_y)
{
    if(abs(pos_x - rock[0]) + abs(pos_y - rock[1]) <= 1000)
    {
        is_valid = true;
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(abs(pos_x - store[i][0]) + abs(pos_y - store[i][1]) <= 1000 && visit[i] == 0 && !is_valid)
        {
            visit[i] = 1;
            dfs(store[i][0], store[i][1]);
        }
    }
}

int main()
{
    cin >> t;

    for(int i=0; i<t; i++)
    {
        is_valid = false;
        fill_n(visit, 105, 0);
        cin >> n;
        cin >> house[0] >> house[1];
        for(int j=0; j<n; j++)
            cin >> store[j][0] >> store[j][1];
        cin >> rock[0] >> rock[1];
        dfs(house[0], house[1]);
        string ans = is_valid? "happy\n" : "sad\n";
        cout << ans; 
    }    

    return 0;
}