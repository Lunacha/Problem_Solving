#include <iostream>
#include <string>
#include <map>
using namespace std;
int t, n;
int main()
{
    cin >> t;
    int cnt = 0;
    int mul = 1;
    string a[2];
    map<string, int> clothes;
    pair<map<string, int>::iterator, bool> iter;
    for(int i=0; i<t; i++)
    {  
        clothes.clear();
        mul = 1;
        cin >> n;
        for(int j=0; j<n; j++)
        {
            cin >> a[0] >> a[1];
            iter = clothes.insert(pair<string, int> (a[1],1));
            if(!iter.second)
                clothes[a[1]]++;
        }
        for(map<string,int>::iterator it = clothes.begin(); it != clothes.end(); it++)
            mul *= (it->second +1);
        cout << mul - 1 << '\n';
    }
    return 0;
}