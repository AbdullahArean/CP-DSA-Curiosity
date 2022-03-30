#include <bits/stdc++.h>
using namespace std;
#define IO ios_base :: sync_with_stdio(0),cin.tie(0)
#define ll long long int
#define ull unsigned long long int

#define WHITE 0
#define GREY 1
#define BLACK 2


int depth[1005][1005];
int color[1005][1005];
char grid[1005][1005];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int BFS(int n,int m,int sx, int sy, int desx, int desy){
    queue<int>q;
    int i,vx,vy,ux,uy;
    while(!q.empty()) q.pop();
    q.push(sx);
    q.push(sy);

    color[sx][sy] = GREY;
    depth[sx][sy] = 0;

    while(!q.empty()){
        ux = q.front();
        q.pop();

        uy = q.front();
        q.pop();

        for(i=0; i<4; i++)
        {
            vx = ux + dx[i];
            vy = uy + dy[i];

            if(vx>=0 && vx<n && vy>=0 && vy<m && grid[vx][vy]!='#' && color[vx][vy]==WHITE)
            {
                color[vx][vy]=GREY;
                depth[vx][vy]=depth[ux][uy]+1;
                q.push(vx);
                q.push(vy);
            }
        }
        color[ux][uy]=BLACK;
    }
    if(depth[desx][desy]==INT_MIN) return -1;
    return depth[desx][desy];
}



int main(){
   IO; //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    
    int n,m;
    scanf("%d%d",&n, &m);

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            color[i][j] = 0;
            depth[i][j] = INT_MIN;
        }

    for(int i=0; i<n; i++)
        scanf("%s",grid[i]);
    
    printf("%d\n",BFS(n,m,0,0,n-1,m-1));
}
