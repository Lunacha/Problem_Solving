#include <iostream>

using namespace std;

int main()
{
    int n,k;

    cin >> n>>k;

    int res = 1;

    if(k > n/2)
        k = n-k;

    if( k !=0)
    {
        for(int i=0; i<k; i++)
        {
            res *= n;
            n--;
        }

        while(k != 1)
        {
            res /= k;
            k--;
        }
    }

    cout << res << '\n';

    return 0;
}