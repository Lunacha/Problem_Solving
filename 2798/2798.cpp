#include <iostream>

using namespace std;

int n,m;
int num[100] = {0,};


int main()
{
    int sum = 0;
    int max = 0;
    
    cin >> n >> m;
    for (int i = 0; i<n; i++)
    {
        cin >> num[i];
    }

    for (int i =0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            for(int k = j+1; k<n; k++)
            {
                sum = num[i] + num[j] + num[k];
                if(sum > max && sum <= m)
                    max = sum;
            }
        }
    }

    cout<<max<<endl;

    return 0;
}