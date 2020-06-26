#include <iostream>

using namespace std;
typedef unsigned long long ull;
ull a,b,c;
ull n_square(ull n,ull r)
{
    ull next;
    if(r == 1)
    {
        next = n;
        if (next >= c)
            next %= c;
        return next;
    }
    else if(r % 2 == 0)  
    {
        next = n*n;
        if (next >= c)
            next %= c;
        return n_square(next, r/2);
    }
    else
    {
        next = n_square(n, r-1) * n;   
        if(next >= c)
            next %= c;
        return next;
    }
}
    
int main()
{
    cin >> a >> b >> c;
    ull ans = n_square(a,b);
    cout << ans << '\n';
    return 0;
}