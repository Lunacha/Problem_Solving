#include <iostream>
#include <cstring>

using namespace std;

bool arr[100000] = {false,};
int t;
int n;
int a;

int main()
{
    cin >> t;

    for(int h =0; h<t; h++)
    {
        cin >> n;
        bool ans = true;

        for(int i =0; i<n; i++)
        {
            cin >> a;
            arr[a-1] = true;
        }

        for(int i =0; i<n; i++)
        {
            if(!arr[i])
            {
                ans = false;
                break;
            }
        }

        if(ans)
            printf("Yes\n");
        else
            printf("No\n");
        
        memset(arr,false,sizeof(bool)*n);
    }

    
    

    return 0;
}