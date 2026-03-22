/* IN THE NAME OF ALMIGHTY ALLAH
____  ___.__ .__                          _________ .__               .___           
\   \/  /|__||  | ___  __  ____ _______   \_   _   \|  |  _____     __| _/ ____      
 \     / |  ||  | \  \/ /_/ __ \\_  __ \   |  | ) _/|  |  \__  \   / __ |_/ __ \     
 /     \ |  ||  |__\   / \  ___/ |  | \/   |  |_)  \|  |__ / __ \_/ /_/ |\  ___/     
/___/\  \|__||____/ \_/   \___  >|__|      |_____  /|____/(____  /\____ | \___  >    
      \_/                     \/                 \/            \/      \/     \/     
*/

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
#define nl '\n'
#define cy cout << "YES"
#define cn cout << "NO"

const int num = 1e5 + 5;
vector<pair<ll, ll>> adj[num];
ll dis[num];
ll par[num];

void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    dis[src] = 0;

    while(!pq.empty())
    {
        pair<ll, ll> p = pq.top();
        pq.pop();

        ll p_node = p.second;
        ll p_dis = p.first;

        for(auto x : adj[p_node])
        {
            ll x_node = x.first;
            ll x_dis = x.second;
            if(p_dis + x_dis < dis[x_node])
            {
                dis[x_node] = p_dis + x_dis;
                pq.push({dis[x_node], x_node});
                par[x_node] = p_node;
            }
        }
    }
}

void solve()
{
    ll n, e; cin >> n >> e;
    while (e--)
    {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for(ll i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
        par[i] = -1;
    }

    dijkstra(1);

    if(dis[n] == LLONG_MAX) { cout << -1; return; }

    ll node = n;
    vi path;
    while(node != -1)
    {
        path.push_back(node);
        node = par[node];
    }

    reverse(path.begin(), path.end());
    for(auto val : path) cout << val << ' ';
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    
    ll T = 1;
    // cin >> T;
    while (T--) { solve(); cout << nl; }
}
/*
-------------------------------------
 Coded by : Sameeha Zahan Mridula
-------------------------------------
*/