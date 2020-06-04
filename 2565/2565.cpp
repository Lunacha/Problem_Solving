#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[101];
int ans;

bool comp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

int main()
{ 
    cin >> n;
    vector<vector<int>> a(n);

    for(int i=0; i<n; i++)
    {
        a[i] = vector<int>(2);
        cin >> a[i][0] >> a[i][1];
    }

    sort(a.begin(),a.end(), comp);

    dp[0] = 1;

    for(int i=1; i<a.size(); i++)
    {
        
        for(int j=0; j<i; j++)
        {
            if( a[i][1] > a[j][1])
            {
                if(dp[i] < dp[j])
                    dp[i] = dp[j];
            }
        }
        dp[i]++;

        if(ans < dp[i])
            ans = dp[i];
    }

    cout << a.size() - ans << endl;

    return 0;
}