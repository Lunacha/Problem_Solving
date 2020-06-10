#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int numbers[100];

int GCD(int a, int b)
{
    if(a%b == 0)
    {
        return b;
    }

    return GCD(b, a%b);
}

int main()
{   
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> numbers[i];

    vector<int> res;

    sort(numbers,numbers+n);
    
    int gcd = numbers[1] - numbers[0];

    for(int i=2; i<n; i++)
    {
        gcd = GCD(gcd, numbers[i] - numbers[i-1]);
    }

    for(int i = 1; i*i <= gcd; i++)
    {
        if(i*i == gcd)
        {
            res.push_back(i);
        }
        else if(gcd % i == 0)
        {
            res.push_back(i);
            res.push_back(gcd/i);
        }
    }

    sort(res.begin(),res.end());

    for(int i = 1; i<res.size(); i++)
        printf("%d ", res[i]);
    printf("\n");

    return 0;
}

