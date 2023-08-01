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
    // 入力
    int H, W, N;
    cin >> H >> W >> N;
    VI A(100009,0), B(100009,0), C(100009,0), D(100009,0);
    REP3(i,1,N+1) cin >> A[i] >> B[i] >> C[i] >> D[i];

    VVI Z(1509,VI(1509,0));
    // 差分の作成
    REP3(i,1,N+1){
        Z[A[i]][B[i]]++;
        Z[C[i]+1][D[i]+1]++;
        Z[A[i]][D[i]+1]--;
        Z[C[i]+1][B[i]]--;
    }
    // 累積和
    // 横
    REP3(i,1,H+1){
        REP3(j,1,W+1){
            Z[i][j] = Z[i-1][j] + Z[i][j];
        }
    }
    // 縦
    REP3(i,1,H+1){
        REP3(j,1,W+1){
            Z[i][j] = Z[i][j-1] + Z[i][j];
        }
    }

    REP3(i,1,H+1) {
        REP3(j,1,W+1){
            cout << Z[i][j] << " ";
        }
        cout << endl;
    } 
    return 0;
}