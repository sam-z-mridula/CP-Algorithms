/* IN THE NAME OF ALMIGHTY ALLAH */

#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int num = 100005;
int ldr[num];
int grp_sz[num];

void dsu_init(int n)
{
    for(int i = 0; i < n; i++)
    {
        ldr[i] = -1;
        grp_sz[i] = 1;
    }
}

int dsu_find(int node)
{
    if(ldr[node] == -1) return node;

    ldr[node] = dsu_find(ldr[node]);
    return ldr[node];
}

void dsu_union(int nodeA, int nodeB)
{
    int ldrA = dsu_find(nodeA);
    int ldrB = dsu_find(nodeB);

    if(grp_sz[ldrA] >= grp_sz[ldrB]){
        ldr[ldrB] = ldrA;
        grp_sz[ldrA] += grp_sz[ldrB];
    } else {
        ldr[ldrA] = ldrB;
        grp_sz[ldrB] += grp_sz[ldrA];
    }
}

int main()
{
    int n, e; cin >> n >> e;
    dsu_init(n);
    bool cycle = false;
    while (e--)
    {
        int a, b; cin >> a >> b;

        int ldrA = dsu_find(a);
        int ldrB = dsu_find(b);
        if(ldrA == ldrB) cycle = true;
        else dsu_union(a, b);
    }

    if(cycle) cout << "Cycle Detected";
    else cout << "No cycle";
}
