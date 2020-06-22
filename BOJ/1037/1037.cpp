#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[50];

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int max = 0;
    int min = 1000000;

    for(int i=0; i<n; i++)
    {
        if(max < arr[i])
            max = arr[i];

        if(min > arr[i])
            min = arr[i];
    }

    cout<< min*max << '\n';

    return 0;
}