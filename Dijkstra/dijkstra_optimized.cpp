/* IN THE NAME OF ALMIGHTY ALLAH */

#include <bits/stdc++.h>
using namespace std;

const int num = 1e3 + 5;
vector<pair<int, int>> adj[num];
int dis[num];

#define nl '\n'

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();

        int p_node = p.second;
        int p_dis = p.first;

        for(auto x : adj[p_node])
        {
            int x_node = x.first;
            int x_dis = x.second;
            if(p_dis + x_dis < dis[x_node])
            {
                dis[x_node] = p_dis + x_dis;
                pq.push({dis[x_node], x_node});
            }
        }
    }
}

int main()
{
    int n, e; cin >> n >> e;
    while (e--)
    {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for(int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    int src; cin >> src;
    dijkstra(src);
}