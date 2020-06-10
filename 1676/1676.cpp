#include <iostream>

using namespace std;

int main()
{
    int n;
    
    cin >> n;

    int two = 0;
    int five = 0;
    int res = 0;
    if(n!=0)
    {
        for(int i=1; i<=n; i++)
        {
            bool flag = true;
            int num = i;
            while(flag)
            {
                flag = false;
                if( num % 2 == 0)
                {
                    two ++;
                    num /= 2;
                    flag = true;
                }
                if( num % 5 == 0)
                {
                    five ++;
                    num /= 5;
                    flag = true;
                }
            }
        }
        res = two < five? two: five;
    }
    
    printf("%d\n",res);

    return 0;
}