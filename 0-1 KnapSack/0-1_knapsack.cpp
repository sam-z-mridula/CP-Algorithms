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

const int num = 1e3 + 5;
int val[num], w8[num];

int knapsack(int i, int mx_w8)
{
    if(i < 0 || mx_w8 <= 0) return 0;
    if(w8[i] <= mx_w8)
    {
        // 2 Options = 1) take  2) Don't take
        int op1 = knapsack(i-1, mx_w8 - w8[i]) + val[i];
        int op2 = knapsack(i-1, mx_w8);

        return max(op1, op2);
    }
    else return knapsack(i-1, mx_w8);
}

void solve()
{
    int n, mx_w8;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> val[i];
    for(int i = 0; i < n; i++) cin >> w8[i];
    cin >> mx_w8;

    cout << knapsack(n-1, mx_w8);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    while (T--) { solve(); cout << nl; }
}
/*
-------------------------------------
 Coded by : Sameeha Zahan Mridula
-------------------------------------
*/