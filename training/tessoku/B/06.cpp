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
    VI A(N);
    REP(i,N) cin >> A[i];
    cin >> Q;
    VI L(Q), R(Q);
    REP(i,Q) {
        cin >> L[i] >> R[i];
        L[i]--, R[i]--;
    }
    VI sum(N);
    REP(i,N){   
        if(i == 0) sum[i] = A[i];
        else sum[i] = A[i] + sum[i-1];
    }
    int atari, hazure;
    REP(i,Q){
        if(L[i]-1 < 0) atari = sum[R[i]];
        else atari = sum[R[i]] - sum[L[i] - 1];
        hazure = R[i] - L[i] + 1 - atari;
        // cout << "atari: " << atari << " " << "hazure: " << hazure << endl;
        if(atari > hazure) cout << "win" << endl;
        else if( atari < hazure) cout << "lose" << endl;
        else cout << "draw" << endl;
    }
    return 0;
}