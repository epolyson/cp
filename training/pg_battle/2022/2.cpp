#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP3(i, s, n) for (int i = (s); i < (int)(n); i++)
#define REP_R(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define REP3_R(i, s, n) for (int i = (int)(n)-1; i >= (int)(s); i--)
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define ALL(x) x.begin(), x.end()

#define INF (int)1e9
#define LLINF (long long)1e18
#define PI 3.141592653589

#define VI vector<int>
#define VL vector<ll>
#define VVI vector<vector<int>>
#define VVL vector<vector<ll>>

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline void printVec(vector<T> v)
{
    REP(i, v.size())
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    FAST;

    int n;
    cin >> n;
    VI a(n + 1);
    vector<char> op(n);
    REP(i, n + 1) {
        if (i != n) cin >> a[i] >> op[i];
        else cin >> a[i];
    }
    // REP(i, a.size())
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // REP(i, op.size())
    // {
    //     cout << op[i] << " ";
    // }
    // cout << endl;

    int sum = 0;
    set<int> sums;
    REP(i, n + 1){
        if (op[i] == '+') sum += a[i];
        else if (op[i] == '=') {
            sum += a[i];
            sums.insert(sum);
            sum = 0;
        }
        else {
            sum += a[i];
            sums.insert(sum);
        }
    }
    // cout << sums.size() << endl;
    // for (auto itr = sums.begin(); itr != sums.end(); ++itr)
    // {
    //     cout << *itr << " ";
    // }
    // cout << endl;
    cout << (sums.size() == 1 ? "Yes" : "No") << endl;
    return 0;
}
