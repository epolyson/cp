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
    int N, D;
    cin >> N ;
    VI A(100009,0), L(100009,0), R(100009,0);
    REP3(i,1,N+1) cin >> A[i];
    cin >> D;
    REP3(i,1,D+1) cin >> L[i] >> R[i];

    // 両端からの累積最大値をとる
    VI P(100009,0), Q(100009,0);
    REP3(i,1,N+1) P[i] = max(P[i-1],A[i]);
    REP3_R(i,1,N+1) Q[i] = max(Q[i+1],A[i]);
    // REP3(i,1,8) cout << P[i] << " "; cout <<endl;
    // REP3(i,1,8) cout << Q[i] << " "; cout <<endl;
     

    REP3(i,1,D+1){
        cout << max(P[L[i]-1], Q[R[i]+1]) << endl;        
    }
    return 0;
} 