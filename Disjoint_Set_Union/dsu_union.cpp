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

    dsu_union(1, 2);
    dsu_union(0, 2);
    dsu_union(3, 4);
    dsu_union(4, 5);

    cout << find(5);
}