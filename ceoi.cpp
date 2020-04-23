/*
 * https://github.com/MohamedAhmed04/Competitive-programming/blob/master/CEOI/18-cloudcomputing.cpp
*/
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
ll N , MX , n , m , ans ;
ll dp[2][200009] ;
struct xxx {
	ll cores , freq , price , id ;
} a[4009] ;
bool cmp ( xxx x , xxx y ) {
	if ( x .freq == y.freq ) {
		return x.id < y.id ;
	}
	return x .freq > y.freq ;
}
int main () {
	cin >> n ;
	for ( int i = 0 ; i < n ; i ++ ) {
		cin >> a[i].cores >> a[i].freq >> a[i].price ;
		a[i] .id = i ;
	}
	cin >> m  ;
	N = n + m ;
	MX= 50 * N + 1 ;
	for ( int i = n ; i < N ; i ++ ) {
		cin >> a[i].cores >> a[i].freq >> a[i].price ;
		a[i] .id = i ;
	}
	sort ( a ,a + N , cmp ) ;
	for ( int j = 1 ; j < MX ; j ++ ) {
		dp[1][j] = - inf ; 
	}
	for ( int i = 0 ; i < N ; i ++ ) {
		int it = i%2 ;
		int last = 1-it ;
		for ( int j = 0 ; j < MX ; j ++ ) {
			dp [it][j] = dp[last][j] ;
			if ( a[i].id < n ) {
				if ( j - a[i].cores >=0 ) {
					dp [it][j] = max ( dp [it][j] , dp [last][j-a[i].cores] - a[i].price ) ;
				}
			}
			else {
				if ( j + a[i].cores <MX ) {
					dp [it][j] = max ( dp [it][j] , dp [last][j+a[i].cores] + a[i].price ) ;
				}
			}
			ans = max ( ans , dp[it][j] ) ;
		}
	}
	cout << ans << endl ; 
}
