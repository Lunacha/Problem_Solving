#include <iostream>
#include <string>

using namespace std;

int t;
string brk;

void check_bracket(string brk)
{
    int valid = 0;
    for(int j=0; j<brk.size(); j++)
    {
        if(brk[j] == '(')
        {
            valid++;
        }
        else
        {
            if(valid == 0)
            {
                cout << "NO\n";
                return;
            }
            valid--;
        }
    }

    if(valid == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    cin >> t;
    
    for(int i=0; i<t; i++)
    {
        cin >> brk;

        check_bracket(brk);
    }

    return 0;
}