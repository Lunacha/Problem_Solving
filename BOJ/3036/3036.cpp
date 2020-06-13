#include <iostream>

using namespace std;

int n;
int r[100];

int GCD(int a, int b)
{
    if( a % b == 0)
        return b;
    else
    {
        return GCD(b, a%b);
    }
    
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> r[i];

    int std = r[0];

    for(int i=1; i<n; i++)
    {
        int gcd = GCD(std,r[i]);
        printf("%d/%d\n",r[0]/gcd,r[i]/gcd);
    }

    return 0;
}