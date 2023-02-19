#include<bits/stdc++.h>
using namespace std;
struct edge {
    int u, v, w;
    // 重载运算符(重新定义"<"的比较规则)
    bool operator < (const edge &x)const{
        return w < x.w;
    }
}e[200005];
int fa[5005], n, m, ans, cnt;
// 并查集查找共同祖先
int findfa(int x){
    if (fa[x] == x)return x;
    return fa[x] = findfa(fa[x]);
}
void unite(int x, int y){
    int fax = findfa(x), fay = findfa(y);
    if (fax != fay)fa[fax] = fay;
}
int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    // 由于重载了"<"故不需要cmp函数 
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= n; i++)fa[i] = i;
    for (int i = 1; i <= m; i++){
        if (findfa(e[i].u) != findfa(e[i].v)){
            unite(e[i].u, e[i].v);
            ans += e[i].w;
            cnt++;
        }
        // 当边数达到n - 1就输出答案
        if (cnt == n - 1){
            printf("%d", ans);
            return 0;
        }
    }
    printf("orz");
    return 0;
}
