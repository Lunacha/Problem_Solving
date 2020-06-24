#include <iostream>
#include <map>

using namespace std;

long long n;
const int m = 1000000;
const int p = m/10*15;
int fib[p];

int main()
{
    cin >> n;
    
    fib[0] = 0;
    fib[1] = 1;

    for(int i=2; i<p; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] %= m;
    }
    
    cout << fib[n%p] << '\n';

    return 0;
}