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
    cin >> N >> Q;
    VI sum(N);
    int a;
    REP(i,N){
        cin >> a;
        if(i == 0) sum[i] = a;
        else sum[i] = sum[i-1] + a;
    }

    int L, R; 
    VI ans;
    REP(i,Q){
        cin >> L >> R;
        L--, R--;
        if(L-1 < 0) ans.push_back(sum[R]);
        else ans.push_back(sum[R] - sum[L-1]);
    }
    for(auto x: ans) cout << x << endl;
    return 0;

}