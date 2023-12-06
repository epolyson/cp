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
    int n;
    cin >> n;
    VI A(100009,0), B(100009,0);
    REP3(i,2,n+1) cin >> A[i];
    REP3(i,3,n+1) cin >> B[i];

    // dp
    VI dp(100009,0);
    dp[1] = 0;
    dp[2] = A[2];
    REP3(i,3,n+1) dp[i] = min(dp[i-1] + A[i], dp[i-2] + B[i]);

    // 復元
    VI root;
    int crr_room = n;
    while(true){
        root.push_back(crr_room);
        if(crr_room == 1) break;

        if(dp[crr_room-1] + A[crr_room] == dp[crr_room]) crr_room -= 1;
        else crr_room -= 2;
    }
    reverse(ALL(root));

    // 出力
    cout << root.size() << endl;
    printVec(root);
    return 0;
}