#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define fast            ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define rep(i, n)       for (int i = 0; i < (int)(n); i++)
#define rep3(i, s, n)   for (int i = (s); i < (int)(n); i++)
#define rep_r(i, n)     for (int i = (int)(n) - 1; i >= 0; i--)
#define rep3_r(i, s, n) for (int i = (int)(n) - 1; i >= (int)(s); i--)

#define ALL(x) x.begin(), x.end()

#define INF   (int)1e9
#define LLINF (long long)1e18
#define PI    3.141592653589

#define VI  vector<int>
#define VL  vector<ll>
#define VVI vector<vector<int>>
#define VVL vector<vector<ll>>

int main() {
    fast;
    int n, x;
    cin >> n;
    vector<int> a(n + 1, 0), pos(n + 1, 0);
    rep3(i, 1, n + 1) {
        cin >> x;
        a[i]   = x;
        pos[x] = i;
    }

    vector<pair<int, int>> ans;
    rep3(i, 1, n + 1) {
        if (a[i] == i) {
            continue;
        }
        int j = pos[i];
        ans.push_back(make_pair(i, j));
        swap(a[i], a[j]);
        pos[a[j]] = j;
    }

    cout << ans.size() << endl;
    for (auto &[i, j] : ans) {
        cout << i << " " << j << endl;
    }
    return 0;
}