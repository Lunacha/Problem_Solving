#include <iostream>
#include <algorithm>

using namespace  std;

int n;
long long arr[300000];
long long table[300000];
long long que[3];

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        scanf("%lld",&arr[i]);

    sort(arr, arr+n);

    table[0] = 1;
    
    for(int k=1; k<n; k++)
    {
        table[k] = table[k-1] * 2;
        if(table[k] >= 1000000007)
            table[k] %= 1000000007;
    }

    long long sum = 0;



    for(int k=0; k<n/2; k++)
    {
        que[0] = table[k];
        que[1] = table[n-1-2*k] - 1;
        que[2] = arr[n-1-k] - arr[k];

        long long val = que[0];

        for(int a=1; a<=2; a++)
        {
            val *= que[a];
            if(val >= 1000000007)
                val %= 1000000007;
        }
        sum += val;

        if(sum >= 1000000007)
                sum %= 1000000007;
    }

    cout << sum << '\n';

    return 0;
}