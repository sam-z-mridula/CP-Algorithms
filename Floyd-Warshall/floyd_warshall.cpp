/* IN THE NAME OF ALMIGHTY ALLAH */

#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
using ll = long long;

ll adj[1005][1005];
int n, e;

void floyd_warshall()
{
    for (int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(adj[i][k] != LLONG_MAX && adj[k][j] != LLONG_MAX && adj[i][k] + adj[k][j] < adj[i][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
}

void print_graph()
{
    bool cycle = false;
    for(int i = 0; i < n; i++)
        if(adj[i][i] < 0) cycle = true;

    if(cycle) cout << "Negative Cycle detected\n";
    else
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(adj[i][j] == LLONG_MAX) cout << "INF ";
                else cout << adj[i][j] << ' ';
    }
}

int main()
{
    cin >> n >> e;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = LLONG_MAX;

    while(e--)
    {
        ll a, b, c; 
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
        // adj[b][a] = min(adj[a][b], c); Unweighted
    }

    floyd_warshall();
    print_graph();
}