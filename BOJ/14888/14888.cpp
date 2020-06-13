#include <iostream>


using namespace std;

const int MAX = 100000001;

int n;
int num[11];
int op[4];
int maxres = -MAX;
int minres = MAX;

void dfs(int plus, int minus, int mul, int div, int cnt, int res)
{
    if( cnt == n)
    {
        maxres = maxres < res ? res : maxres;
        minres = minres > res ? res : minres;
    }

    if (plus > 0)
        dfs(plus-1, minus, mul, div, cnt + 1, res + num[cnt]);
    if (minus > 0)
        dfs(plus, minus-1, mul, div, cnt + 1, res - num[cnt]);
    if (mul > 0)
        dfs(plus, minus, mul-1, div, cnt + 1, res * num[cnt]);
    if (div > 0)
        dfs(plus, minus, mul, div-1, cnt + 1, res / num[cnt]);
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> num[i];
    for(int i=0; i<4; i++)
        cin >> op[i];
    
    dfs(op[0],op[1],op[2],op[3], 1, num[0]);

    printf("%d\n", maxres);
    printf("%d\n", minres);

    return 0;
}