#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
int seq[100005];
stack<int> user;
string res;

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> seq[i];

    int index = 0;
    int num = 1;

    while(index != n)
    {
        if(seq[index] >= num)
        {
            for(int i=0; i<=seq[index]-num; i++)
            {
                user.push(num);
                res += "+";
                num++;
            }
        }
        
        if(seq[index] < num)
        {
            if(!user.empty())
            {
                if(user.top() == seq[index])
                {
                    user.pop();
                    res += "-";
                    index++;
                }
                else
                {
                    res = "NO";
                    break;
                }
            }
            else
            {
                res = "NO"; 
                break;
            }  
        }     
    }

    if(res == "NO")
        cout << res << '\n';
    else
    {
        for(int i=0; i<res.size(); i++)
            cout << res[i] << '\n';
    }

    return 0;
}