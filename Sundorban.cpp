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

#define ll long long
#define vi vector<int>
#define vll vector<ll>;
#define nl '\n'
#define cy cout << "YES"
#define cn cout << "NO"

const int num = 35;
char grid[num][num];
bool vis[num][num];
int lvl[num][num];

vector<pair<int, int> > vp;
int n;

void init()
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            vis[i][j] = false;
            lvl[i][j] = -1;
        }
}

bool valid(int i, int j)
{
    return (i>=0 && i<n && j>=0 && j<n);
}

/*-----------------BFS on 2d graph-----------------*/
void bfs(int si, int sj)
{
    queue<pair<int, int> > q;
    q.push({si, sj});
    vis[si][sj] = true;
    lvl[si][sj] = 0;

    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int pi = p.first;
        int pj = p.second;

        int ans = 0;
        for(int i=0; i<4; i++)
        {
            int ci = pi + vp[i].first;
            int cj = pj + vp[i].second;
            
            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != 'T')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                lvl[ci][cj] = lvl[pi][pj] + 1;
            }
        }
    }
}

void solve()
{
    vp.push_back({1, 0});
    vp.push_back({-1, 0});
    vp.push_back({0, 1});
    vp.push_back({0, -1});

    int si, sj, di, dj;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'S') si = i, sj = j;
            else if(grid[i][j] == 'E') di = i, dj = j;
        }


    init();
    bfs(si, sj);

    cout << lvl[di][dj];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while (cin >> n) { solve(); cout << nl; }
}
/*
-------------------------------------
 Coded by : Sameeha Zahan Mridula
-------------------------------------
*/