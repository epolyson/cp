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

int main() {
  fast;
  int n;
  cin >> n;
  rep3(i, 1, n + 1) {
    if (i % 3 == 0)
      cout << "x";
    else
      cout << "o";
  }
  cout << endl;
  return 0;
}