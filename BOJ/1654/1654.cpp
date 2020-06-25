#include <iostream>

using namespace std;

long long k, n;
long long lan[10005];
long long len_max = 0;

long long b_search(long long front, long long end)
{ 
    if(front > end)
        return len_max;

    long long len = (front + end) / 2;
    long long num = 0;

    for(int i=0; i<k; i++)
        num += lan[i] / len;

    if( num < n)
    {
        return b_search(front, len-1);
    }
    else
    {   
        if(len > len_max)
           len_max = len;
        return b_search(len + 1 , end);
    }
}

int main()
{
    int max = 0;
    cin >> k >> n ;
    for(int i=0; i<k; i++)
    {
        cin >> lan[i];
        if(lan[i] > max)
            max = lan[i];
    }

    cout << b_search(1,max) << '\n';

    return 0;
}