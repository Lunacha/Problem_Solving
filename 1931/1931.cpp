#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool comp(vector<int> &a, vector<int> &b)
{
    
    if(a[1] == b[1])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}


int main()
{
    cin >> n;
    vector<vector<int>> t(n);

    for(int i=0; i<n; i++)
    {
        t[i] = vector<int>(2);
        cin >> t[i][0] >> t[i][1];
    }

    sort(t.begin(), t.end(), comp);

    int end = 0;
    int cnt = 0;

    for(int i=0; i<n; i++)
    {
        end <=
    }




    return 0;
}