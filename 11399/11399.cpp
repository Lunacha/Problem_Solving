#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000];

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int sum = 0;
    int acc_sum = 0;

    for(int i=0;i<n; i++)
    {
        sum += arr[i];
        acc_sum += sum;
    }

    cout << acc_sum << '\n';

    return 0;
}