#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,k;

    cin >> n >>k;

    int start =1;
    int end = k; //k번째 수는 k보다 클 수 없다
    int res;
    while(start<=end)
    {
        int cnt = 0;
        int mid = (start+end) / 2; 
        for(int i=1; i<=n; i++)
            cnt += min(mid/i, n); //mid값을 탐색했을때 k번째임을 확인하려면 mid보다 작거나 같은 값의 개수가 k~k+(mid중복값 개수) 사이여야 한다
        if(cnt < k)
            start = mid + 1;
        else
        {
            res = mid; //mid중복값이 여러개일경우가 존재하기 때문에 일단 res에 저장하고 다시 탐색
            end = mid-1;
        }
    }

    cout << res << '\n';

    return 0;
}