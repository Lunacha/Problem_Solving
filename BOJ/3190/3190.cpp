#include <iostream>
#include <list>
#define P pair<int,int>

using namespace std;

int n,k,l,t;
int x,y;
char c_dir;
int dir;
int map[105][105];
int turn[10005];
int time;
int direction[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
list<P> snake;


int main()
{
    cin >> n >> k;

    for(int i=0; i<k; i++)
    {
        cin >> x >> y;
        map[x][y] = 1; 
    }

    cin >> l;
    for(int i=0; i<l; i++)
    {
        cin >> t >> c_dir;
        if(c_dir == 'L')
            turn[t] = -1;
        else
            turn[t] = 1;
    }

    snake.push_front(P(1,1));
    dir = 0;

    while(true)
    { 
        if(turn[time] == -1)
            dir = (dir + 4 - 1) % 4;
        else if(turn[time] == 1)
            dir = (dir + 1) % 4;

        time++; 

        int next_x = snake.front().first + direction[dir][0];
        int next_y = snake.front().second + direction[dir][1];
        
        if(next_x > n || next_x < 1 || next_y > n || next_y < 1) //map collision
            break;
    
        //self collision
        bool flag = false;
        for(list<P>::iterator iter = snake.begin(); iter != snake.end(); ++iter) 
        {  
            if(iter->first == next_x && iter->second == next_y) 
            {
                flag = true;
                break;
            }
        }
        if(flag)
            break;

        //move snake
        P next = P(next_x,next_y);
        snake.push_front(next);
        if(map[next_x][next_y] != 1) //apple
        {
            snake.pop_back();
        }
        else
            map[next_x][next_y] = 0;
         
    }

    cout << time << '\n';

    return 0;
}