#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<bitset>
// #include < unordered_map > 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include "boost/algorithm/string.hpp"
#define fio ios_base::sync_with_stdio(false)
#define mod 1000000007
#define mod1 mod
#define mod2 100000009
#define li long long int
#define ll int
#define readi(x) scanf("%d",&x)
#define  reads(x)  scanf("%s", x)
#define readl(x) scanf("%I64d",&x)
#define rep(i,n) for(i=0;i<n;i++)
#define revp(i,n) for(i=(n-1);i>=0;i--)
#define myrep1(i,a,b) for(i=a;i<=b;i++)
#define myrep2(i,a,b) for(i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define MAXN INT_MAX
#define MINN -1000000000000000000
#define pii pair<ll,ll> 
#define pic pair<int,char>
#define N 200010
#define lgn 20
#define ddouble long double
#define minus minu
#define PI 3.1415926535


// #define INTMAX 200000000

// using namespace boost;
// #define si short int

using namespace std;
using namespace __gnu_pbds;             
typedef priority_queue<pair<ll,pii> , vector<pair<ll , pii> > > max_pq;

// typedef priority_queue<pair < ll , pair < pii , ll > >  , vector<pair < ll , pair < pii , ll > >  > ,greater<pair < ll , pair < pii , ll > >  > > min_pq;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> OST;
typedef priority_queue< char , vector<char> > max_pqc;
typedef priority_queue<ll, vector<ll > , greater < ll >  > min_pq;

ll p,q,e,P,n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> p >> q >> e >> P ;
    n = p * q;

    ll c = 1;

    for ( ll i = 1 ; i <= e ; i ++)
    {
        c = ( c * P )%n;
    }

    ll rem = 0,po;
    ll to = ( p - 1 )*( q - 1 );


    for ( ll i = 0; i < n ; i ++)
    {
        if ( ! rem )
            rem = 1;
        else
            rem = ( rem * c )%n;
        if ( rem == P and ((i*e)%to == 1 ))
        {
            po = i;
            break;
        }

    }


    cout << c << " " << po << endl;




    





}