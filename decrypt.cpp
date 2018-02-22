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
#define ll li
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


ll key[10],k1[10],k2[10],pt[8],temp[10],temp2[10],l[10],r[10],invip[10];
ll  p10[] = {2,4,1,6,3,9,0,8,7,5},
    p8[] = {5,2,6,3,7,4,9,8},
    p4[] = {1,3,2,0},
    ip[] = {1,5,2,0,3,7,4,6},
    ep[] = {3,0,1,2,1,2,3,0};
pii s0[4][4]={{mp(0,1),mp(0,0),mp(1,1),mp(1,0)},{mp(1,1),mp(1,0),mp(0,1),mp(0,0)},{mp(0,0),mp(1,0),mp(0,1),mp(1,1)},{mp(1,1),mp(0,1),mp(1,1),mp(1,0)}};
pii s1[4][4]={{mp(0,0),mp(0,1),mp(1,0),mp(1,1)},{mp(1,0),mp(0,0),mp(0,1),mp(1,1)},{mp(1,1),mp(0,0),mp(0,1),mp(0,0)},{mp(1,0),mp(0,1),mp(0,0),mp(1,1)}};

void leftshift( ll* ar , ll st , ll en )
{
    ll val = ar[st];
    for ( ll i = st ; i < en ; i ++ )
        ar[i] = ar[i+1];
    ar[en] = val;
}


void keygen( )
{
    
    for ( ll i = 0 ; i < 10 ; i ++)
        temp[i] = key[p10[i]];
    
    leftshift(temp,0,4);
    leftshift(temp,5,9);

    for ( ll i = 0 ; i < 8 ; i ++)
        k1[i] = temp[p8[i]];

    leftshift(temp,0,4);
    leftshift(temp,5,9);
    leftshift(temp,0,4);
    leftshift(temp,5,9);

    for ( ll i = 0 ; i < 8 ; i ++)
        k2[i] = temp[p8[i]];
   
}

void encrypt(ll* temp,ll* with)
{
    for ( ll i = 0 ; i < 4 ; i ++ )
        r[i] = temp[i+4];
    for ( ll i = 0 ; i < 8 ; i ++)
        temp2[i] = r[ep[i]];
    for ( ll i = 0 ; i < 8 ; i ++)
        temp2[i] ^= with[i];

    ll row = temp2[0]*2 + temp2[3];
    ll col = temp2[1]*2 + temp2[2];
    ll box[4];
    box[0] = s0[row][col].fi;
    box[1] = s0[row][col].sec;

    row = temp2[4]*2 + temp2[7];
    col = temp2[5]*2 + temp2[6];

    box[2] = s1[row][col].fi;
    box[3] = s1[row][col].sec;
    
    ll fbox[4];
    for ( ll i = 0 ; i < 4 ; i ++)
        fbox[i] = box[p4[i]];
    for ( ll i = 0 ; i < 4 ; i ++)
        fbox[i] = ( fbox[i] ^ temp[i]);

    for ( ll i = 0 ; i < 4 ; i ++)
        temp[i] = fbox[i];

    
    
}

void sdes( )
{
    for ( ll i = 0 ; i < 8 ; i ++)
        temp[i] = pt[ip[i]];

    encrypt(temp,k2);
    
    for ( ll i = 0 ; i < 4 ; i ++)
        swap(temp[i],temp[i+4]);
    
    encrypt(temp,k1);

    for ( ll i = 0 ; i < 8 ; i ++)
        invip[ip[i]] = i;

    for ( ll i = 0 ; i < 8 ; i ++)
        cout << temp[invip[i]];



}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin >> s1 >> s2;


    for ( ll i = 0 ; i < s1.size() ; i ++ )
        key[i] = s1[i] - '0';
    for ( ll i = 0 ; i < s2.size() ; i ++ )
        pt[i] = s2[i] - '0';

    keygen();

    sdes();




    





}