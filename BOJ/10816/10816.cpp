#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int card[500005];
int number;

int lower_binary(int num)
{
    int mid;
    int start = 0;
    int end = n-1;
    while(start < end)
    {
        mid = (start+end)/2;
        if(card[mid] >= num)
            end = mid;
        else
            start = mid + 1;
    }
    return end;
}

int upper_binary(int num)
{
    int mid;
    int start = 0;
    int end = n-1;
    while(start < end)
    {
        mid = (start+end)/2;
        if(card[mid] > num)
            end = mid;
        else
            start = mid + 1;
    }
    return end;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> card[i];
    
    sort(card,card+n);
    
    cin >> m;
    
    for(int i=0; i<m; i++)
    {
        cin >> number;
        int up = upper_binary(number);
        int down = lower_binary(number);
        
        if(up == n-1 && card[n-1] == number)
            up++;
        cout << up - down << " ";      
    }
    
    return 0;
}