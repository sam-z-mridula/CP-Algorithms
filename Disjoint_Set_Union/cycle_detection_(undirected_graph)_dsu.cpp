/* IN THE NAME OF ALMIGHTY ALLAH */

#include <bits/stdc++.h>
using namespace std;

int ldr[1005];
int grp_sz[1005];

#define nl '\n'

int find(int node)
{
    if(ldr[node] == -1) return node;

    int leader = find(ldr[node]);
    ldr[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int ldr1 = find(node1);
    int ldr2 = find(node2);

    if(grp_sz[ldr1] >= grp_sz[ldr2]){
        ldr[ldr2] = ldr1;
        grp_sz[ldr1] += grp_sz[ldr2];
    } else {
        ldr[ldr1] = ldr2;
        grp_sz[ldr2] += grp_sz[ldr1];
    }
}

int main()
{
    memset(ldr, -1, sizeof(ldr));
    memset(grp_sz, 1, sizeof(grp_sz));

    int n, e; cin >> n >> e;
    bool cycle = false;
    while (e--)
    {
        int a, b; cin >> a >> b;

        int ldrA = find(a);
        int ldrB = find(b);
        if(ldrA == ldrB) cycle = true;
        else dsu_union(a, b);
    }

    if(cycle) cout << "Cycle Detected";
    else cout << "No cycle";
}
