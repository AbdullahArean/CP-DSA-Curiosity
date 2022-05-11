#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define pqmaxi(a) priority_queue<int, vi> a
#define pqmini(a) priority_queue<int, vi, greater<int>> a
const int MAXN = 1005;
const int inf = INT_MAX;
char givenmap[MAXN][MAXN];
int r, c, spot[MAXN][MAXN];
int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct sted
{
    int xpos, ypos, test;
    sted(int x_, int y_, int t_) { xpos = x_, ypos = y_, test = t_; }
} inst(0, 0, 0);
queue<sted> Queue1;
void BFS()
{
    int tempx, tempy;
    while (!Queue1.empty())
    {
        inst = Queue1.front();
        Queue1.pop();
        for (int i = 0; i < 4; i++)
        {
            tempx = inst.xpos + direction[i][0];
            tempy = inst.ypos + direction[i][1];
            if (tempx >= 0 && tempx < r && tempy >= 0 && tempy < c && givenmap[tempx][tempy] != '#' && spot[tempx][tempy] > inst.test + 1)
            {
                spot[tempx][tempy] = inst.test + 1;
                Queue1.push(sted(tempx, tempy, inst.test + 1));
            }
        }
    }
}
int BFS(int xpos, int ypos)
{
    int tempx, tempy;
    givenmap[xpos][ypos] = '#';
    Queue1.push(sted(xpos, ypos, 0));
    while (!Queue1.empty())
    {
        inst = Queue1.front();
        Queue1.pop();
        if (!(inst.xpos && inst.xpos != r - 1 && inst.ypos && inst.ypos != c - 1))
            return inst.test + 1;
        for (int i = 0; i < 4; i++)
        {
            tempx = inst.xpos + direction[i][0];
            tempy = inst.ypos + direction[i][1];
            if (tempx >= 0 && tempx < r && tempy >= 0 && tempy < c && givenmap[tempx][tempy] != '#' && inst.test + 1 < spot[tempx][tempy])
            {
                givenmap[tempx][tempy] = '#';
                Queue1.push(sted(tempx, tempy, inst.test + 1));
            }
        }
    }
    return -1;
}
int main()
{
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int test, ex, ey;
    scanf("%d", &test);
    while (test--)
    {
        scanf("%d%d", &r, &c);
        memset(spot, 0x3f, sizeof(spot));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                scanf(" %c", &givenmap[i][j]);
                if (givenmap[i][j] == 'F')
                {
                    spot[i][j] = 0;
                    Queue1.push(sted(i, j, 0));
                }
                else if (givenmap[i][j] == 'J')
                    ex = i, ey = j;
            }
        }
        BFS();
        int ans = BFS(ex, ey);
        if (~ans)
            printf("%d\n", ans);
        else
            printf("IMPOSSIBLE\n");
        while (!Queue1.empty())
            Queue1.pop();
    }
    return 0;
}