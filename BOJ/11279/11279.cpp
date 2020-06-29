#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, less<int>> pq;

int n, temp;

int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&temp);
        if(temp == 0)
        {
            if(pq.empty())
                 printf("0\n");
            else
            {
                printf("%d\n",pq.top());
                pq.pop();
            }
        }
        else
        {
            pq.push(temp);
        }  
    }

    return 0;
}