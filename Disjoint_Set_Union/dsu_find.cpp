/* IN THE NAME OF ALMIGHTY ALLAH */

#include <bits/stdc++.h>
using namespace std;

int ldr[1005];

#define nl '\n'

int find(int node)
{
    if(ldr[node] == -1) return node;

    int leader = find(ldr[node]);
    ldr[node] = leader;
    return leader;
}

int main()
{
    memset(ldr, -1, sizeof(ldr));

    ldr[0] = 1;
    ldr[2] = 1;
    ldr[3] = 1;
    ldr[4] = 5;
    ldr[5] = 3;

    cout << find(5);
}