#include <iostream>

using namespace std;

int n;
int man[20][20];
int team[2][10];
int diff = 100000;

int calculate_skill(int team_num, int mem_n)
{
    int skill = 0;
    for(int i=0; i<mem_n; i++)
    {
        int member1 = team[team_num][i];
        for(int j=0; j<mem_n; j++)
        {
            int member2 = team[team_num][j];
            skill += man[member1][member2];
        }
    }

    return skill;
}

void dfs(int start_n, int link_n, int cnt)
{
    if (cnt == n)
    {
        int start_skill = calculate_skill(0, start_n);
        int link_skill = calculate_skill(1, link_n);
        int skill_diff = abs(start_skill - link_skill);

        diff = diff > skill_diff ? skill_diff : diff; 
    }

    if( start_n < n/2)
    {
        team[0][start_n] = cnt;
        dfs(start_n + 1, link_n, cnt + 1);
         
    }
    if( link_n < n/2)
    {
        team[1][link_n] = cnt;
        dfs(start_n, link_n + 1, cnt + 1);
    }
}       

int main()
{
    cin >> n;
    for(int i = 0; i<n; i++)
    {
        for(int j= 0; j<n; j++)
            cin >> man[i][j];
    }

    dfs(0, 0, 0);

    printf("%d\n", diff);

    return 0;
}
