#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

int t,p,n;

int main()
{
    cin >> t;
    for(int i=0; i<t; i++)
    {
        deque<string> dq;
        string func;
        string arr;
        bool front = true;
        bool error = false;
        cin >> func;
        cin >> n;
        cin >> arr;
        arr = arr.substr(1,arr.size()-2);
        string buffer;
        stringstream tmp(arr);
        while(getline(tmp,buffer,','))
        {
            dq.push_back(buffer);
        }
        
        for(int j=0; j<func.size(); j++)
        {
            if(func[j] == 'R')
                front = !front;      
            else
            {
                if(dq.size()!=0)
                {
                    if(front)
                        dq.pop_front();
                    else
                        dq.pop_back();
                }
                else
                {
                    error = true;
                    break;
                }
            }
        }
        if(!error)
        {
            cout<<"[";
            if(front)
            {
                if(dq.size()!=0)
                    cout<<dq[0];
                for(int j=1; j<dq.size();j++)
                {
                    cout<<"," << dq[j];
                }
            }
            else
            {
                if(dq.size()!=0)
                    cout<<dq[dq.size()-1];
                for(int j=dq.size()-2; j>=0;j--)
                {
                    cout<<"," << dq[j];
                }
            }
            cout<<"]\n";
        }
        else
            cout << "error\n";

    }

    return 0;
}