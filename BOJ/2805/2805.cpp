#include <iostream>
#include <algorithm>

using namespace std;

long long n,m;
long long tree[1000000];

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
        scanf("%lld", &tree[i]);
    
    sort(tree, tree+n);

    long long min = 0;
    long long max = tree[n-1];

    long long height = 0;
    while(min <= max)
    {
        long long mid = (min + max) /2;
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            if(tree[i] - mid > 0)
                sum += tree[i] - mid;
        }
        if(sum >= m)
        {
            height = mid;
            min = mid + 1;
        }
        else
            max = mid - 1;   
    }

    cout << height << '\n';

    return 0;
}