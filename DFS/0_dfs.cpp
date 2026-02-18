/* IN THE NAME OF ALMIGHTY ALLAH */

#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

vector<int> adj_list[1005];         // array of vectors
bool vis[1005];                     // array of bool elements

void dfs(int src)
{
    cout << src << " ";
    vis[src] = true;
    for(auto child : adj_list[src])
    {
        if(!vis[child]) dfs(child);
    }
}

int main()
{
    int n, e; cin >> n >> e;
    while(e--)
    {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    int src; cin >> src;                // source node / element
    dfs(src);
}