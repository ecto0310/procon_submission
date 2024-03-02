// Date: Sat, 02 Mar 2024 13:56:24 +0000
// Language: C++ 23 (gcc 12.2)
#include<bits/stdc++.h>
#include <atcoder/all>
using namespace std; 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define length size()
#define __STDCPP_FLOAT128_T__
#define Real1024 float128_t
#define int unsigned long long
#define ll long long
constexpr ll inf = 1001001001001001001ll;
constexpr ll mod = /* 1000000007*/ 998244353;
constexpr double pi = 3.141592653589793;
template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;
//小数出力
//cout << setprecision(12);
//imos
void to_ruiseki(vector<int> &vec){
    for(int i=1;i<(int)vec.size();i++){
        vec[i] += vec[i-1];
    }
}
void to_2druiseki(vector<vector<int>> &vec){
    rep(i,vec.size()){
        rep(j,vec[0].size()){
            int s = 0;
            if(i!=0) s += vec[i-1][j];
            if(j!=0) s += vec[i][j-1];
            if(i!=0 && j!=0) s -= vec[i-1][j-1];
            s += vec[i][j];
            vec[i][j] = s;
        }
    }
}
//modpow(a,n,mod)
int modpow(int a, int n, int mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
//素因数分解
vector<pair<int,int>> p_fact(int N) {
    vector<pair<int,int>> res;
    for (int a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        int ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}
//ctoi
int ctoi(const char c){
  switch(c){
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    default :  throw runtime_error("hoge");
  }
}
//max
template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
//min
template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }
//print
void print() { cout << '\n'; }
template<typename T>
void print(const T &t) { cout << t << '\n'; }
template<typename Head, typename... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}
//join
template<typename T> string join(vector<T> &vec ,const string &sp){
    int si = vec.length;
    if(si==0){
        return "";
    }else{
        stringstream ss;
        rep(i,si-1){
            ss << vec[i] << sp;
        }
        ss << vec[si - 1];
        return ss.str();
    }
}
vector<pair<long long, long long> > prime_factorize(long long N) {
    // 答えを表す可変長配列
    vector<pair<long long, long long> > res;

    // √N まで試し割っていく
    for (long long p = 2; p * p <= N; ++p) {
        // N が p で割り切れないならばスキップ
        if (N % p != 0) {
            continue;
        }

        // N の素因数 p に対する指数を求める
        int e = 0;
        while (N % p == 0) {
            // 指数を 1 増やす
            ++e;

            // N を p で割る
            N /= p;
        }

        // 答えに追加
        res.emplace_back(p, e);
    }

    // 素数が最後に残ることがありうる
    if (N != 1) {
        res.emplace_back(N, 1);
    }
    return res;
}
/* lazySegtree Template
using S = int;
using F = int;
S op(S a,S b){return min(a,b);}
S e(){return inf;}
S mapping(F f,S x){return x+f;}
F composition(F f, F g){ return f+g; }
F id(){ return 0; }
*/
bool is_kaibun(int n){
  string s = to_string(n);
  //cout << s << endl;
  bool f = true;
  rep(i,s.size()){
    if(s[i]!=s[s.size()-1-i]) f = false;
  }
  return f;
}
signed main(void){
  int n;
  cin >> n;
  int ans = 1;
  rep(i,cbrtl(n)+1){
    //cout << i << endl;
    if(is_kaibun(i*i*i) && i*i*i <= n ) ans = i*i*i;
  }
  cout << ans << endl;
}
