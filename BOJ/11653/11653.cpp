#include <iostream>

using namespace std;

int main()
{
    int n;
    int divide = 2;

    cin >> n;
    
    while( n != 1)
    {
        if( n % divide == 0)
        {
            n /= divide;
            printf("%d\n",divide);
        }
        else
        {
            divide++;
        }
    }

    return 0;
}