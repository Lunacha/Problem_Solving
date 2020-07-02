#include <iostream>
#include <stack>

using namespace std;

int k, n;
stack<int> st;

int main()
{
    cin >> k;

    for(int i=0; i<k; i++)
    {
        cin >> n;
        if( n == 0)
            st.pop();
        else
            st.push(n);
    }
    int sum = 0;
    while(!st.empty())
    {
        sum += st.top();
        st.pop();
    }

    cout << sum << '\n';

    return 0;
}