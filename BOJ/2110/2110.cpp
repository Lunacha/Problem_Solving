#include <iostream>
#include <algorithm>

using namespace std;

int n,c;
long long home[200005];
long long d_max = 0;
int b_search(long long front, long long end)
{
    if(front > end)
        return d_max;
    long long mid = (front + end) / 2;
    int num = 1;
    int start = 0;
    for(int i=start+1; i<n; i++)
    {
        if(home[i]- home[start] >= mid)
        {
            start = i;
            num++;
        }      
    }    
     
    if(num >= c)      
    {
        if(mid >= d_max)
            d_max = mid;
        return b_search(mid+1,end);  
    }
    else
        return b_search(front,mid-1);  
}

int main()
{
    cin >> n >> c;
    for(int i=0; i<n; i++)
        cin >> home[i];

    sort(home,home+n);

    if(c == 2)
        cout << home[n-1] - home[0] << '\n';
    else
        cout << b_search(1,(home[n-1] - home[0])/(c-1)) <<'\n';

    return 0;
}