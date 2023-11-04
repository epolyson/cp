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
    int n, w, x;
    cin >> n;
    vector<pair<ll,ll>> base(n);
    REP(i,n) {
        cin >> w >> x;
        base[i] = make_pair(w,x);
    }

    int baseTime;
    ll ans = -1;
    REP(t,24){
        ll sum = 0;
        REP(i,n){
            baseTime = base[i].second + t;
            if((baseTime <= 24)){
                if(baseTime >= 9 && baseTime <= 17) sum += base[i].first; 
            }else{
                baseTime -= 24;
                if(baseTime >= 9 && baseTime <= 17) sum += base[i].first;
            }
        }
        chmax(ans,sum);
    }
    cout << ans << endl;
    return 0;
}