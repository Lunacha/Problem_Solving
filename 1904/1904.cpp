#include <iostream>

using namespace std;

int n;

int fib[1000001];


int main()
{
    cin >> n;

    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 2;

    for(int i=3; i<=n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
        fib[i] %= 15746;
    }

    cout << fib[n] <<'\n';
    

    return 0;
}