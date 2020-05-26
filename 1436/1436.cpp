#include <iostream>

using namespace std;

int n;

int main()
{
    cin >> n;
    int cnt = 0;
    int num = 1;
    while(1)
    {
        int present = num;
        while(present >= 100)
        {
            if(present % 1000 == 666)
            {
                cnt++;
                break;
            }
            else
                present /= 10;            
        }
        
        if( cnt == n)
            break;
        
        num++;
    }

    cout<<num<<endl;

    return 0;
}