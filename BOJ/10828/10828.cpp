#include <iostream>
#include <string>
#include <stack>

using namespace std;

int n;
int element;
string command;
stack<int> st;


int main()
{
    cin >> n;

    for(int i=0;i<n; i++)
    {
        cin >> command;
        if(command == "push")
        {
            cin >> element;

            st.push(element);

        }
        else if(command == "pop")
        {
            if(!st.empty())
            {
                cout << st.top() << '\n';
                st.pop();
            }
            else
                cout << -1 << '\n';
            
        }
        else if(command == "size")
            cout << st.size() << '\n';
        else if(command == "empty")
        {
            int res = st.empty()? 1 : 0;
            cout << res << '\n';
        }
        else if(command == "top")
        {
            if(!st.empty())
                cout << st.top() << '\n';
            else
                cout << -1 <<'\n';
        }
    }

    return 0;
}