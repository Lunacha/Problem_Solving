#include <iostream>
#include <algorithm>

using namespace std;

int n,m;

int two, five = 0;

int two_count(int num)
{
    int cnt = 0;
    
    for(long long i = 2; num / i >= 1; i *= 2)
        cnt += num / i;

    return cnt;
}

int five_count(int num)
{
    int cnt = 0;
    
    for(long long i = 5; num / i >= 1; i *= 5)
        cnt += num / i;

    return cnt;
}

int main()
{
    cin >> n >> m;
    
    two += two_count(n);
    two -= two_count(n-m);
    two -= two_count(m);
    five += five_count(n);
    five -= five_count(n-m);
    five -= five_count(m);
    
    cout << (five<two?five:two) << '\n';
    

    return 0;
}