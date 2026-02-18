/* IN THE NAME OF ALMIGHTY ALLAH */

#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

char grid[105][105];            // if a grid of characters is given
bool vis[105][105];
vector<pair<int, int> > vp = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int r, c;

bool valid(int i, int j)
{
    if(i<0 || i>=r || j<0 || j>=c) return false;
    return true;
}

void dfs(int si, int sj)
{
    cout << si << " " << sj << nl;    // কাজ ⭐⭐⭐
    vis[si][sj] = true;         // source is visited
    for(int i=0; i<4; i++)      // loop runs strictly 4 time (কতদিকে যেতে হবে)
    {
        int ci = si + vp[i].first;
        int cj = sj + vp[i].second;

        if(!vis[ci][cj] && valid(ci, cj)) dfs(ci, cj);  // recursion call
    }
}

int main()
{
    cin >> r >> c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> grid[r][c];

    int si, sj;                 // si = x of source, sj = y of source
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    dfs(si, sj);
}