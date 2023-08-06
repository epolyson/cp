#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REP3(i, s, n) for(int i = (s); i < (int)(n); i++)
#define REP_R(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define REP3_R(i, s, n) for(int i = (int)(n) - 1; i >= (int)(s); i--)
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

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
   FAST
   int N;
   cin >> N;
   VI A(100009,0), B(100009,0), C(100009,0), D(100009,0); 
   REP3(i,1,N+1) cin >> A[i] >> B[i] >> C[i] >> D[i];

   VVI c_sum(1509,VI(1509,0));
   REP3(i,1,N+1){
      c_sum[A[i]][B[i]]++;
      c_sum[C[i]][D[i]]++;
      c_sum[A[i]][D[i]]--;
      c_sum[C[i]][B[i]]--;
   }

   // cout << endl;
   REP(h,1501) REP3(w,1,1501){
         c_sum[h][w] = c_sum[h][w] + c_sum[h][w-1];
   }
   REP3(h,1,1501) REP(w,1501){
         c_sum[h][w] = c_sum[h][w] + c_sum[h-1][w];
   }
   // REP3(h,0,15) {
   //    REP3(w,0,15){
   //       cout << c_sum[h][w] << " ";
   //    }cout << endl;
   // }
   // cout << endl;
   int ans = 0;
   REP(h,1501){
      REP(w,1501){
         if(c_sum[h][w] >= 1) ans++;
      }
   }
   cout << ans << endl;
   return 0;
}