#include <iostream>

using namespace std;

int a,b;

int GCD(int a, int b)
{
    if( a % b == 0)
        return b;
    else
        return GCD(b, a%b);
}

int main()
{
    cin >> a >> b;

    int gcd = GCD(a,b);
    int lcm = a*b / gcd ;

    cout << gcd << '\n' << lcm << '\n';

    return 0;
}