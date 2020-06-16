#include <iostream>

using namespace std;

int t;
int n;
int arr[1000];

int main()
{
    cin >> t;
    
    for(int i=0; i<t; i++)
    {
        cin >> n;

        int max = -1;

        for(int j=0; j<n; j++)
            cin >> arr[j];

        for(int j=0; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                int mul = arr[j] * arr[k];
                int check = mul / 10;
                int last = mul % 10;
                bool candid = true;
                while(check != 0)
                {              
                    int digit = check % 10;
                    if( digit + 1 != last)
                    {
                        candid = false;
                        break;
                    }
                    last = digit;
                    check /= 10;
                }
                if(candid)
                {
                    if(max < mul)
                        max = mul;
                }
                
            }
        }
        printf("%d\n",max);
    }

    return 0;
}