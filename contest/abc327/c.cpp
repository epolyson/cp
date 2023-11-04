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

bool isNumberPlace(VI v){
    map<int,int> mp;
    REP(i,v.size()) mp[v[i]]++;
    if(mp.size() == 9) return true;
    else return false;
}

int main(){
    FAST;
    VVI row(9,VI(9)), column(9,VI(9)), square(9);
    REP(i,9) REP(j,9){
        int a;
        cin >> a;
        row[i][j] = a;
        column[j][i] = a;
        if(i < 3){
            if(j < 3) square[0].push_back(a);
            else if(j > 5) square[2].push_back(a);
            else square[1].push_back(a);
        }else if(i > 5){
            if(j < 3) square[6].push_back(a);
            else if(j > 5) square[8].push_back(a);
            else square[7].push_back(a);
        }else{
            if(j < 3) square[3].push_back(a);
            else if(j > 5) square[5].push_back(a);
            else square[4].push_back(a);
        }
    } 

    bool flg = true;
    // 行ごと
    REP(i,9) flg &= isNumberPlace(row[i]);
    // 列ごと
    REP(i,9) flg &= isNumberPlace(column[i]);
    // 3*3ごと
    REP(i,9) flg &= isNumberPlace(square[i]);

    cout << (flg ? "Yes" : "No") << endl;
    return 0;
}

