#include<bits/stdc++.h>
using namespace std;
int n, m, s, u, v, w, to[500005], val[500005], nxt[500005], head[500005], dis[100005];
bool vis[100005];
struct st{
    int id, dis;
    bool operator < (const st &a) const{
        return dis > a.dis;
    }
};
priority_queue<st> q;
int main(){
    // 输入点与边的数量以及边权
    scanf("%d%d%d", &n, &m, &s);
    // 通过链式前向星存图
    for (int i = 1; i <= m; i++){
        // 输入边的起点终点与权
        scanf("%d%d%d", &u, &v, &w);
        to[i] = v;
        val[i] = w;
        nxt[i] = head[u];
        head[u] = i;
    }
    // 默认从s点到所有的点的距离无限大
    for (int i = 1; i <= n; i++)dis[i] = INT_MAX;
    // s点到s点的距离为0
    dis[s] = 0;
    // 从s点开始
    q.push(st{ s, 0 });
    // 开始广搜
    while(!q.empty()){
        u = q.top().id;
        q.pop();
        if (vis[u])continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = nxt[i]){
            v = to[i], w = val[i];
            if (dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                q.push(st{ v, dis[v]});
            }
        }
    }
    for (int i = 1; i <= n; i++)printf("%d ", dis[i]);
    return 0;
}
