#include <iostream>
#include <vector>

using namespace std;

int n;
int num;
int fib[41];
vector<int> vec;


int main()
{
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> num;
        vec.push_back(num);     
    }

    fib[0] = 0;
    fib[1] = 1;
    
    for(int i=2; i<=40; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    for(int i=0; i<n; i++)
    {
        if( vec[i] == 0 )
            printf("%d %d\n",1,0);
        else
            printf("%d %d\n",fib[vec[i]-1], fib[vec[i]]);
    }

    return 0;
}