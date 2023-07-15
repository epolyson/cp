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
    int N, M;
    cin >> N >> M;

    VI P(N), C(N);
    vector<set<int>> F(N);
    REP(i,N) {
        cin >> P[i] >> C[i];
        for(int j = 0; j < C[i]; j++){
            int x;
            cin >> x;
            F[i].insert(x);
        }
    }

    REP(i,N){
        REP(j,N){
            if(i == j) continue;
            // cout << "P" << i << " >= " << "P" << j << "?" << endl; 
            // cout << P[i] << " " << P[j] << endl;
            if(P[i] >= P[j]){
                // cout << "F" << i << ": ";
                // for(auto x: F[i]){
                //     cout << x << " ";
                // }cout << endl;
                // cout << "F" << j << ": ";
                // for(auto x: F[j]){
                //     cout << x << " ";
                // }cout << endl;
                bool allIn = true;
                for (auto iter = F[i].begin(); iter != F[i].end(); ++iter) {
                    if(F[j].find(*iter) == F[j].end()) {
                        allIn = false;
                    }
                }
                if(allIn){
                    if(P[i] > P[j] || F[j].size() > F[i].size()) {
                        // cout << i << endl;
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}