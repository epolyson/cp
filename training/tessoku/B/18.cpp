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
   int n, s;
   cin >> n >> s;
   VI a(69,0);
   REP3(i,1,n+1) cin >> a[i];


   // dp
   vector<vector<bool>> dp(69,vector<bool>(s+1,false));
   dp[0][0] = true;
   REP3(i,1,n+1){
      REP(j,s+1){
         if(dp[i-1][j] == true) dp[i][j] = true;
         if(dp[i-1][j-a[i]] == true) dp[i][j] = true;
      }
   }
   // REP(i,n+1) printVec(dp[i]);
   if(dp[n][s] == false) {
      cout << -1 << endl;
      return 0;
   }

   // restore selected card
   VI root;
   int crr = s;
   REP3_R(i,1,n+1){
      if(dp[i-1][crr-a[i]] == true) {
         root.push_back(i); 
         crr -= a[i];
      }
   }
   reverse(ALL(root));

   // output
   cout << root.size() << endl;
   printVec(root);
   return 0;
}