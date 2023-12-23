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

int N, S, A[69];
bool dp[69][10009];
VI ans;

int main(){
    FAST;
    // input
    cin >> N >> S;
    REP3(i,1,N+1) cin >> A[i];

    // dp
    dp[0][0] = true;
    REP3(i,1,S+1) dp[0][i] = false;

    REP3(i,1,N+1){
        REP(j,S+1){
            if(j < A[i]){
                if(dp[i-1][j] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
            if(j >= A[i]){
                if(dp[i-1][j] == true || dp[i-1][j-A[i]] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }
    REP(i,N+1) {
        REP(j,S+1){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // 合計がSとなる組み合わせがない場合
    if(dp[N][S] == false) {
        cout << -1 << endl;
        return 0;
    }
    
    // restore root
    int Place = S;
    REP3_R(i,1,N+1){
        if(dp[i-1][Place] == true){
            continue;
        }else{
            Place -= A[i];
            ans.push_back(i);
        }
    }
    reverse(ALL(ans));

    // output
    cout << ans.size() << endl;
    printVec(ans);
    return 0;
}