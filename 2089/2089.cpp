#include <iostream>

using namespace std;

void m_binary(int n)
{
    if( n == 0)
        return;
    if( n % -2 == 0)
    {
        m_binary(n/-2);
        printf("0");
    }
    else
    {
        m_binary((n-1) / -2);
        printf("1");
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    if( n==0 )
    {
        printf("0");
    }
    else
    {
        m_binary(n);
    }
    

    return 0;
}