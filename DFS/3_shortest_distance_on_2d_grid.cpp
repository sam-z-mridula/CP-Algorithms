/* IN THE NAME OF ALMIGHTY ALLAH */

#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

char grid[105][105];
bool vis[105][105];
int lvl[105][105];              // level array
vector<pair<int, int> > vp = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int r, c;

bool valid(int i, int j)
{
    if(i<0 || i>=r || j<0 || j>=c) return false;
    return true;
}

/*-----------------BFS on 2D Grid-----------------*/
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    lvl[si][sj] = 1;

    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int pRow = p.first;
        int pCol = p.second;

        for(int i=0; i<4; i++)
        {
            int ci = pRow + vp[i].first;
            int cj = pCol + vp[i].second;
            if(valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                lvl[ci][cj] = lvl[pRow][pCol] + 1;
            }
        }
    }
}

int main()
{
    cin >> r >> c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> grid[r][c];

    int si, sj; cin >> si >> sj;
    int di, dj; cin >> di >> dj;        // input row and col idx of destination
    memset(vis, false, sizeof(vis));
    memset(lvl, -1, sizeof(lvl));       // initialize level array with -1
    bfs(si, sj);

    cout << lvl[di][dj];
}