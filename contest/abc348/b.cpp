#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define fast            ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define rep(i, n)       for (int i = 0; i < (int)(n); i++)
#define rep3(i, s, n)   for (int i = (s); i < (int)(n); i++)
#define rep_R(i, n)     for (int i = (int)(n) - 1; i >= 0; i--)
#define rep3_R(i, s, n) for (int i = (int)(n) - 1; i >= (int)(s); i--)

#define ALL(x) x.begin(), x.end()

#define INF   (int)1e9
#define LLINF (long long)1e18
#define PI    3.141592653589

#define VI  vector<int>
#define VL  vector<ll>
#define VVI vector<vector<int>>
#define VVL vector<vector<ll>>

double calc_dist(pair<int, int> p1, pair<int, int> p2) {
  return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
  fast;
  int n, x, y;
  cin >> n;
  vector<pair<int, int>> p;
  rep(i, n) {
    cin >> x >> y;
    p.push_back(make_pair(x, y));
  }

  vector<int> ans;
  double      dist;
  rep(i, n) {
    double max_val = -1;
    double max_pos;
    rep(j, n) {
      if (i == j)
        continue;
      dist = calc_dist(p[i], p[j]);
      if (dist > max_val) {
        max_val = dist;
        max_pos = j + 1;
      }
    }
    ans.push_back(max_pos);
  }

  rep(i, ans.size()) cout << ans[i] << endl;
  return 0;
}