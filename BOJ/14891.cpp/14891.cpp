#include <iostream>

using namespace std;

char gear[4][10];
int head[4];
bool gear_rotate[4];

int k, index, rotation;

void select_gear(int id, int rot)
{
    id -= 1;
    
    gear_rotate[id] = true;

    bool is_rotate = true;
    for(int i=id; i<=2; i++)
    {
        if(gear[i][(head[i]+8+2)%8] == gear[i+1][(head[i+1]+8-2)%8])
            is_rotate = false;
        gear_rotate[i+1] = is_rotate;
    }

    is_rotate = true;
    for(int i=id; i>=1; i--)
    {
        if(gear[i][(head[i]+8-2)%8] == gear[i-1][(head[i-1]+8+2)%8])
            is_rotate = false;
        gear_rotate[i-1] = is_rotate;
    }
    
    for(int i=0; i<4; i++)
    {
        if(gear_rotate[i])
        {
            if( (id-i) % 2 == 0 )
                head[i] = (head[i] + 8 - rot) % 8;
            else
                head[i] = (head[i] + 8 + rot) % 8;
        }
    }
}

int main()
{
    for(int i=0;i<4; i++)
    {
        cin >> gear[i];
    }

    cin >> k;

    for(int i=0; i<k; i++)
    {
        cin >> index >> rotation;

        select_gear(index,rotation);    
    }

    int res = 0;

    for(int i=0; i<4; i++)
    {
        if(gear[i][head[i]] == '1')
            res += 1 << i;
    }
    
    cout << res << '\n';
    return 0;
}