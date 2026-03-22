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

const int n = 1e2 + 5;
char grid[n][n];
bool vis[n][n];
vector<pair<int, int> > vp = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int r, c;

bool valid(int i, int j)
{
    return (i>=0 || i<r || j>=0 || j<c);
}

/*-----------------Only change from DFS-----------------*/
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int pRow = p.first;
        int pCol = p.second;

        cout << pRow << " " << pCol << nl;

        for(int i=0; i<4; i++)
        {
            int ci = pRow + vp[i].first;
            int cj = pCol + vp[i].second;
            if(valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }
}

int main()
{
    cin >> r >> c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> grid[i][j];

    int si, sj;
    cin >> si >> sj;
    memset(vis, false, sizeof(vis));
    bfs(si, sj);
}