#include <iostream>

using namespace std;

int n;
int aws = 0;

int main()
{
    cin >> n;
    
    for(int i=1; i<n; i++)
    {
        int num = i;
        int sum = num;
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }

        if( n == sum)
        {
            aws = i;
            break;
        }
    }

    cout << aws << endl;

    return 0;
}