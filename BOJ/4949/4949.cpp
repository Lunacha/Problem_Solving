#include <iostream>
#include <string>
#include <stack>

using namespace std;

void valid_check(string s)
{
    stack<char> st;

    for(int i=0; i<s.size(); i++)
    {
        char tmp = s[i];
        if(tmp == '[' || tmp == '(' )
            st.push(tmp);
        else if(tmp == ']')
        {
            if(!st.empty())
            {
                if( st.top() == '[')
                st.pop();
                else
                {
                    cout << "no\n";
                    return;
                }
            }
            else
            {
                cout << "no\n";
                    return;
            }    
        }      
        else if(tmp == ')')
        {
            if(!st.empty())
            {
                if( st.top() == '(')
                st.pop();
                else
                {
                    cout << "no\n";
                    return;
                }
            }
            else
            {
                cout << "no\n";
                    return;
            }   
        }
    }
    if(!st.empty())
        cout << "no\n";
    else
        cout << "yes\n";

    return;
}

int main()
{
    string str;

    while(true)
    {
        getline(cin,str);
        if(str == ".")
            break;
        else
            valid_check(str);
        
    }

    return 0;
}