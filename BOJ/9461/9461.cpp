#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
vector<int> numbers;
long long p[101];

int main()
{
    cin >> t;

    for(int i=0; i<t; i++)
    {
        cin >> n;
        numbers.push_back(n);
    }

    int max = *max_element(numbers.begin(),numbers.end());
    
    p[0] = 1;
    p[1] = 1;
    p[2] = 1;
    p[3] = 2;
    p[4] = 2;

    for(int i=5; i<max; i++)
        p[i] = p[i-1] + p[i-5];
    
    for(int i=0; i<t; i++)
        printf("%lli\n",p[numbers[i]-1]);
    

    return 0;
}