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

ll surplusF(ll x){
    ll sum = 1;
    REP3_R(i,1,x+1) {
        sum *= i;
        sum = sum % 998244353;
    }
    return sum;
} 

ll calcPathNum(ll x, ll y){
    return surplusF(x+y) / (surplusF(x) * surplusF(y));
} 

int main(){
    FAST;
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    ll allPath = calcPathNum(n, m);
    ll subPath = calcPathNum(a, b);
    if(a > n || b > m) cout << allPath << endl;
    else cout << allPath - subPath << endl;
    return 0;
}