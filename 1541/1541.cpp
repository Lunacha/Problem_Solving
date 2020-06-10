#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    string num = "";
    bool minus = false;
    int result = 0;

    cin >> str;

    for(int i=0; i<=str.size();i++)
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '\0')
        {
            if(minus)
                result -= stoi(num);
            else
                result += stoi(num);
            num = "";
            
            if(str[i] == '-')
                minus = true;
                
        }
        else
        {
            num += str[i];
        }
    }

    cout<< result << '\n';

    return 0;
}