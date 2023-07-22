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
    int H, W, Q;
    cin >> H >> W;
    VVI X(1509,VI (1509,0));
    REP3(i,1,H+1) REP3(j,1,W+1) cin >> X[i][j];
    cin >> Q;
    VI A(100009,0), B(100009,0), C(100009,0), D(100009,0);
    REP3(i,1,Q+1) cin >> A[i] >> B[i] >> C[i] >> D[i];

    VVI ruiseki_h(1509,VI (1509,0));
    REP3(h,1,H+1) REP3(w,1,W+1){
        ruiseki_h[h][w] = ruiseki_h[h][w-1] + X[h][w];
    }
    // cout << endl;
    // REP3(h,1,H+1) {
    //     REP3(w,1,W+1) cout << ruiseki_h[h][w] << " ";
    //     cout << endl;
    // }cout << endl;
    VVI ruiseki(ruiseki_h);
    REP3(h,1,H+1) REP3(w,1,W+1){
        ruiseki[h][w] = ruiseki[h-1][w] + ruiseki_h[h][w];
    }
    // REP(h,H+1) {
    //     REP(w,W+1) cout << ruiseki[h][w] << " ";
    //     cout << endl;
    // }cout << endl;

    int sum;
    REP3(i,1,Q+1){
        sum = ruiseki[C[i]][D[i]] + ruiseki[A[i]-1][B[i]-1] - ruiseki[C[i]][B[i]-1] - ruiseki[A[i]-1][D[i]];
        cout << sum << endl;
    }
    return 0;
}   