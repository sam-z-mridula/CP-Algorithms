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

#define nl '\n'
#define ll long long
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vll vector<ll>

const int num = 1005;
int ldr[num];
int grp_sz[num];

void dsu_init(int n)
{
    for(int i=1; i<=n; i++)
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

    if(ldrA == ldrB) return;

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
    int n; cin >> n;
    dsu_init(n);
    
    vpi rmv, create;
    for(int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;

        int ldrA = dsu_find(a);
        int ldrB = dsu_find(b);

        if(ldrA == ldrB) rmv.push_back({a, b});
        else dsu_union(a, b);
    }

    for(int i = 2; i <= n; i++)
    {
        int ldr1 = dsu_find(1);
        int ldr2 = dsu_find(i);

        if(ldr1 != ldr2)
        {
            create.push_back({1, i});
            dsu_union(1, i);
        }
    }

    cout << rmv.size() << nl;
    for(int i = 0; i < rmv.size(); i++)
        cout << rmv[i].first << ' ' << rmv[i].second << ' ' << create[i].first << ' ' << create[i].second << nl;
}
