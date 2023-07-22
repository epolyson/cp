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
    int n;
    cin >> n;
    VI a(n+1);
    REP3(i,1,n+1) cin >> a[i];

    VI fl(n+1,0),s;
    int v = 1;
    while(fl[v] == 0){ // 辿ったことのない頂点なら続ける
        fl[v] = 1;
        s.push_back(v);
        v = a[v];
    }

    VI res;
    for(auto &nx: s){
        if(nx == v) v = -1; // 先頭となる頂点を見つけたら-1にする
        if(v == -1) res.push_back(nx); // その頂点以降の頂点を追加
    }
    cout << res.size() << endl;
    REP(i,res.size()) cout << res[i] << " ";
    cout << endl;
    return 0;
}