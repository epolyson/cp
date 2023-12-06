#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REP3(i, s, n) for(int i = (s); i < (int)(n); i++)
#define REP_R(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define REP3_R(i, s, n) for(int i = (int)(n) - 1; i >= (int)(s); i--)
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

#define ALL(x) x.begin(),x.end()

#define INF (int)1e9
#define LLINF (long long)1e18
#define PI 3.141592653589

#define VI vector<int>
#define VL vector<ll>
#define VVI vector<vector<int> >
#define VVL vector<vector<ll> >

template <class T>
inline bool chmin(T &a, T b) {
   if(a > b){ a = b; return true;}
   return false;
}
template <class T>
inline bool chmax(T &a, T b) {
   if(a < b){ a = b; return true;}
   return false;
}
template <class T>
inline void printVec(vector<T> v) {
   REP(i,v.size()){
      if(i) cout << " ";
      cout << v[i];
      } cout << endl;
}

int main(){
    FAST;
    // input
    int n;
    cin >> n;
    VI h(100009,0);
    REP3(i,1,n+1) cin >> h[i];

    // dp
    VI dp(100009,0);
    dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);
    REP3(i,3,n+1) dp[i] = min(dp[i-1] + abs(h[i-1] - h[i]), dp[i-2] + abs(h[i-2] - h[i]));

    // restoration
    VI root;
    int pos = n;
    while(true){
        root.push_back(pos);
        if(pos == 1) break;

        if(dp[pos-1] + abs(h[pos-1] - h[pos]) == dp[pos]) pos--;
        else pos -= 2;
    }
    reverse(ALL(root));

    // output
    cout << root.size() << endl;
    printVec(root);
    return 0;
}