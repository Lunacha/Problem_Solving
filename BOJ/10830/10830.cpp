#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> arr(5,vector<int>(5));
vector<vector<int>> ans(5,vector<int>(5));

int n;
long long b;

vector<vector<int>> calculate(vector<vector<int>> &a, vector<vector<int>> &b)
{
    vector<vector<int>> c(n, vector<int>(n));
    for(int i=0;i<n; i++)
    {
        for(int j=0;j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
               c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= 1000;
        }
    }

    return c;
}

vector<vector<int>> divide(vector<vector<int>> &mat, long long b)
{
    if(b == 1)
        return mat;
    else if(b%2 == 0)
    {
        vector<vector<int>> res = divide(mat,b/2);
        return calculate(res,res);
    }
    else
    {
        vector<vector<int>> res = divide(mat,b-1);
        return calculate(res,mat);
    }
    
}

int main()
{
    cin >> n >> b;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin >> arr[i][j];
    }
  
    ans = divide(arr,b);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << ans[i][j] % 1000 << " ";
        cout<<"\n";
    }

    return 0;
}