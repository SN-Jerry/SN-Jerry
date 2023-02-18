#include<bits/stdc++.h>
using namespace std;
int n, m, s, u, v, w, to[500005], val[500005], head[500005], nxt[500005], dis[100005];
bool vis[100005];
struct st
{
    int id, dis;
    bool operator < (const st &a) const{
        return dis > a.dis;
    }
};
priority_queue<st> q;
int main(){
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d", &u, &v, &w);
        to[i] = v;
        val[i] = w;
        nxt[i] = head[u];
        head[u] = i;
    }
    for (int i = 1; i <= n; i++)dis[i] = INT_MAX;
    dis[s] = 0;
    q.push(st{s, 0});
    while(!q.empty()){
        u = q.top().id;
        q.pop();
        if (vis[u])continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = nxt[i]){
            int v = to[i], w = val[i];
            if (dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                q.push(st{v, dis[v]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    return 0;
}
