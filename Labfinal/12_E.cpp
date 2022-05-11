#include <bits/stdc++.h>
using namespace std;
const int maxv = 10010;
const int maxe = 100010;

vector<int> G[maxv];
int PARR[maxv];
int RANKHH[maxv];
int PREVV[maxv];
int clk;
int r1, c2, q3;
int ver;
void initial(int givenn)
{
    for (int i = 0; i <= givenn; i++)
    {
        PARR[i] = i;
        RANKHH[i] = 0;
    }
}

int findParent(int givenx)
{
    if (PARR[givenx] == givenx)
    {
        return givenx;
    }
    else
    {
        return PARR[givenx] = findParent(PARR[givenx]);
    }
}
void UniteTwo(int givenx, int giveny)
{
    givenx = findParent(givenx);
    giveny = findParent(giveny);
    if (givenx == giveny)
        return;
    if (RANKHH[givenx] < RANKHH[giveny])
    {
        PARR[givenx] = giveny;
        RANKHH[giveny] += RANKHH[givenx];
    }
    else
    {
        PARR[giveny] = givenx;
        RANKHH[givenx] += RANKHH[giveny];
    }
}
int dfsrun(int u, int fa)
{
    int lowu = PREVV[u] = ++clk;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!PREVV[v])
        {
            int lowv = dfsrun(v, u);
            lowu = min(lowu, lowv);
            if (lowv == PREVV[v])
                UniteTwo(u, v);
        }
        else if (v != fa)
            lowu = min(lowu, PREVV[v]);
    }
    return lowu;
}
void IsCUt()
{
    memset(PREVV, 0, sizeof(PREVV));
    for (int i = 0; i < ver; i++)
    {
        if (!PREVV[i])
        {
            clk = 0;
            dfsrun(i, -1);
        }
    }
}

int main()
{
//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    while (scanf(" %d%d%d ", &r1, &c2, &q3) != EOF)
    {
        if (r1 + c2 + q3 == 0)
            break;
        for (int i = 0; i < r1; i++)
        {
            G[i].clear();
        }
        ver = r1;
        // initial(ver);
        for (int i = 0; i < c2; i++)
        {
            int u, v;
            scanf(" %d %d ", &u, &v);
            u -= 1;
            v -= 1;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        IsCUt();
        for (int i = 0; i < q3; i++)
        {
            int u, v;

            scanf(" %d%d ", &u, &v);
            u -= 1;
            v -= 1;
            if (findParent(u) == findParent(v))
                puts(" Y ");
            else
                puts(" N ");
        }
        puts(" - ");
    }
    return 0;
}