#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <cassert>
#include <unordered_map>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <bitset>

using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/* TYPES  */
#define xf first
#define xs second
#define ll long long int
#define dbl double
#define ld long double
#define str string
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define mid(l, r) 	       ((l + r) >> 1)
#define all(a)             a.begin(),a.end()
#define v(t) vector<t>
#define ar(t,sz) array<t,sz>
#define s(t) set<t>
#define ss(a) sort(a.begin(),a.end())
#define ms(t) multiset<t>
#define mipq(t) priority_queue<t,v(t),greater<t>>
#define mapq(t) priority_queue<t>
#define trpl(a,b,c) tuple<a,b,c>
#define m(t, t2) map<t, t2>
#define um(t, t2) unordered_map<t, t2>
#define p(t, t2) pair<t, t2>
#define f(i, s, e) for(long long int i=s;i<e;i++)
#define fc(i, s, e, c) for(long long int i=s;i<e;i+=c)
#define fa(k,in) for(auto k:in)
#define fm(i, s, e) for(long long int i=s;i!=e;i++)
#define cf(i, s, e) for(long long int i=s;i<=e;i++)
#define rf(i, e, s) for(long long int i=e-1;i>=s;i--)
#define wl(c) while(c)
#define pb push_back
#define mpp make_pair
#define cl clear
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()


class ST {
public:
    v(int) tree;
    int n;
    ST(v(int)& hs){
        n=hs.size();
        tree.resize(4*n);
        build(hs,0,0,n-1);
    }
    void build(v(int)& hs,int nd,int s,int e){
        if(s==e){
            tree[nd]=hs[s];
            return;
        }
        int mid=(s+e)/2;
        build(hs,2*nd+1,s,mid);
        build(hs,2*nd+2,mid+1,e);
        tree[nd]=max(tree[2*nd+1],tree[2*nd+2]);
    }
    int que(int l,int r){
        return que(0,0,n-1,l,r);
    }
    int que(int nd, int s, int e,int l,int r){
        if(r<s||e<l){return INT_MIN;}
        if(l<=s&&e<=r){return tree[nd];}
        int mid=(s+e)/2;
        return max(que(2*nd+1,s,mid,l,r),que(2*nd+2,mid+1,e,l,r));
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& hs, vector<vector<int>>& qs) 
    {
        v(int) re(qs.size(),-1);
        ST st(hs);
        f(i,0,qs.size()){
            if(qs[i][0]<qs[i][1]&&hs[qs[i][0]]<hs[qs[i][1]]){re[i]=qs[i][1];}
            if(qs[i][0]>qs[i][1]&&hs[qs[i][0]]>hs[qs[i][1]]){re[i]=qs[i][0];}
            if(qs[i][0]==qs[i][1]){re[i]=qs[i][0];}
            if(re[i]!=-1){continue;}
            int l=max(qs[i][0],qs[i][1]);
            int r=hs.size()+1;
            int th=max(hs[qs[i][0]],hs[qs[i][1]]);
            wl(l<=r){
                int m=(l+r)/2;
                if (st.que(l,m)>th) {
                    re[i]=m;
                    r=m-1;
                } else {
                    l=m+1;
                }
            }
        }
        return re;
    }
};