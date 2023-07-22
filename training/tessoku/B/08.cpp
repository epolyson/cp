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
    int N, Q;
    cin >> N;
    VI X(100009,0), Y(100009,0), a(100009,0), b(100009,0), c(100009,0), d(100009,0);
    REP3(i,1,N+1) cin >> X[i] >> Y[i];
    cin >> Q;
    REP3(i,1,Q+1) cin >> a[i] >> b[i] >> c[i] >> d[i];

    VVI dot(1501, VI(1501,0));
    REP3(i,1,N+1) dot[X[i]][Y[i]]++;
    VVI ans(1501, VI(1501,0));
    REP3(i,1,1501) REP3(j,1,1501) ans[i][j] = ans[i][j-1] + dot[i][j];
    REP3(i,1,1501) REP3(j,1,1501) ans[i][j] = ans[i-1][j] + ans[i][j];
    REP3(i,1,Q+1) cout << ans[c[i]][d[i]] + ans[a[i]-1][b[i]-1] - ans[c[i]][b[i]-1] -ans[a[i]-1][d[i]] << endl;
    return 0;
}