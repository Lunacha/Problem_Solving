#include <iostream>

using namespace std;

bool arr[100000];
int n;
int a;
bool ans = true;

int main()
{
    cin >> n;

    for(int i =0; i=n; i++)
    {
        scanf("%d", a);
        arr[a-1] = true;
    }

    for(int i =0; i=n; i++)
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
    

    return 0;
}