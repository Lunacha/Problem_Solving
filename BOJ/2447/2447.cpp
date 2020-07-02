#include <iostream>

using namespace std;

const int SIZE = 3*3*3*3*3*3*3*3;
int n;
char table[SIZE][SIZE];

void make_star(int num)
{
    if(num == n)
        return;
    
    for(int i=0; i<num*3; i++)
    {
        for(int j=0; j<num*3; j++)
            table[i][j] = table[i%num][j%num];
    }
    for(int i=num; i<2*num; i++)
    {
        for(int j=num; j<2*num; j++)
            table[i][j] = ' ';
    }

    make_star(num*3);
}

int main()
{
    cin >> n;

    for(int i=0;i<3;i++)
    {
        for(int j=0; j<3; j++)
            table[i][j] = '*';
    }

    table[1][1] = ' ';

    make_star(3);

    for(int i=0; i<n;i++)
    {
        for(int j=0; j<n;j++)
            printf("%c",table[i][j]);
        printf("\n");
    }

    return 0;
}