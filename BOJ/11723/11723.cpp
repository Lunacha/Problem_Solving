#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int m;
    int mask = 0;;
    string cmd;
    scanf("%d",&m);
    char str[20];
    
    for(int i=0; i<m; i++)
    {
        int x;
        
        scanf("%s", str);
        cmd = str;
        if(cmd == "all") 
            mask = (1<<21) - 1;
        else if(cmd == "empty") 
            mask = 0;
        else
        {
            scanf("%d",&x);
            if(cmd == "add") 
                mask |= (1<<(x-1));
            else if(cmd == "remove")
                mask &= ~(1<<(x-1));
            else if(cmd == "check") 
            {
                int res = (mask & (1<<(x-1))) ? 1:0;
                printf("%d\n",res);
            }
            else if(cmd == "toggle")
                mask ^= (1<<(x-1));
        }  
    }

    return 0;
}