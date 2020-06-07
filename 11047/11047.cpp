#include <iostream>

using namespace std;

int n,k;
int a[10];

int main()
{
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    int cnt = 0;
    while( k !=0 )
    {
        cnt += k/a[n-1];
        k %= a[n-1];
        n--;
    }

    cout << cnt << '\n';

    return 0;
}