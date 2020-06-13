#include <iostream>

using namespace std;

int n;
int k;
int num[500];

int GCD(int a, int b)
{
    if(a % b == 0)
        return b;
    else
    {
        return GCD(b, a%b);
    }
    
}

int main()
{
    cin >> n >> k;

    if(k > n/2)
        k = n-k;

    int res = 1;

    for(int i=0; i<k; i++)
    {
        num[i] = n;
        n--;
    }

    for(int i=k; i>=2; i--)
    {
        int mod = i;
        for(int j=0; j<k; j++)
        {  
            int gcd = GCD(num[j], mod);
            if( gcd != 1)
            {
                num[j] /= gcd;
                mod /= gcd;
                if( mod == 1)
                    break;
            }
        }
    }

    for(int i=0; i<k; i++)
    {
        res *= num[i];
        if(res > 10007)
            res %= 10007;
    }

    cout << res << '\n';

    return 0;
}
