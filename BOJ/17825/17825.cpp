#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int board[33][6] =
{
    {0,1,2,3,4,5},
    {2,2,3,4,5,6},
    {4,3,4,5,6,7},
    {6,4,5,6,7,8},
    {8,5,6,7,8,9},
    {10,21,22,23,29,30},
    {12,7,8,9,10,11},
    {14,8,9,10,11,12},
    {16,9,10,11,12,13},
    {18,10,11,12,13,14},
    {20,24,25,29,30,31},
    {22,12,13,14,15,16},
    {24,13,14,15,16,17},
    {26,14,15,16,17,18},
    {28,15,16,17,18,19},
    {30,26,27,28,29,30},
    {32,17,18,19,20,32},
    {34,18,19,20,32,32},
    {36,19,20,32,32,32},
    {38,20,32,32,32,32},
    {40,32,32,32,32,32},
    {13,22,23,29,30,31},
    {16,23,29,30,31,20},
    {19,29,30,31,20,32},
    {22,25,29,30,31,20},
    {24,29,30,31,20,32},
    {28,27,28,29,30,31},
    {27,28,29,30,31,20},
    {26,29,30,31,20,32},
    {25,30,31,20,32,32},
    {30,31,20,32,32,32},
    {35,20,32,32,32,32},
    {0,32,32,32,32,32}
};

bool isFull[33];
int best_score = 0;
int dice[10];
queue <vector<int>> q;

void move_piece(int p1, int p2, int p3, int p4, int score,int cnt)
{
    //cout << "(" << p1 << " " << p2 << " " << p3 << " " << p4 << " " << score << " " << cnt << ")\n";
    if(cnt == 10)
    {
        if(score > best_score)
            best_score = score;
        return;
    }

    if(!isFull[board[p1][dice[cnt]]] && p1 != 32)
    {
        int next_p1 = board[p1][dice[cnt]];
        isFull[p1] = false;
        if(next_p1 != 32)
            isFull[next_p1] = true;
        move_piece(next_p1, p2, p3, p4, score+board[next_p1][0], cnt+1);
        isFull[p1] = true;
        isFull[next_p1] = false;
    }
    if(!isFull[board[p2][dice[cnt]]] && p2 != 32)
    {
        int next_p2 = board[p2][dice[cnt]];
        isFull[p2] = false;
        if(next_p2 != 32)
            isFull[next_p2] = true;
        move_piece(p1, next_p2, p3, p4, score+board[next_p2][0], cnt+1);
        isFull[p2] = true;
        isFull[next_p2] = false;
    }
    if(!isFull[board[p3][dice[cnt]]] && p3 != 32)
    {
        int next_p3 = board[p3][dice[cnt]];
        isFull[p3] = false;
        if(next_p3 != 32)
            isFull[next_p3] = true;
        move_piece(p1, p2, next_p3, p4, score+board[next_p3][0], cnt+1);
        isFull[p3] = true;
        isFull[next_p3] = false;
    }
    if(!isFull[board[p4][dice[cnt]]] && p4 != 32)
    {
        int next_p4 = board[p4][dice[cnt]];
        isFull[p4] = false;
        if(next_p4 != 32)
            isFull[next_p4] = true;
        move_piece(p1, p2, p3, next_p4, score+board[next_p4][0], cnt+1);
        isFull[p4] = true;
        isFull[next_p4] = false;
    }
}

int main(){

    for(int i=0; i<10; i++)
        cin >> dice[i];
    move_piece(0,0,0,0,0,0);

    cout<< best_score << '\n';

    return 0;
}