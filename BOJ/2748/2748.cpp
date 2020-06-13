#include <iostream>

using namespace std;

long long fibo[91];

int num;

long long fib(int n)
{
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i=2; i<= n; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    return fibo[n];
}

int main()
{
    cin >> num;

    cout << fib(num) << '\n';

    return 0;
}