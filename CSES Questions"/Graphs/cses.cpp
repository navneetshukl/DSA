// Problem Link - 
/* By Navneet Shukla*/
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mpa 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modularExponentiation((x*x)%M,n/2,M);
    else                             //n is odd
        return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;

}
void dijkstra(ll src,ll n,vector<pair<ll,ll>> adj[],ll dist[])
{
	priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;//min heap
	map<int,bool>vis;
	loop(i,1,n)
	{
		dist[i]=inf;
		vis[i]=false;
	}
	pq.push({0,src});
	dist[src]=0;
	while(!pq.empty())
	{
		ll nod=pq.top().ss;
		ll dis=pq.top().ff;
		pq.pop();
		if(vis[nod]) continue;
		vis[nod]=true;
		for(auto j:adj[nod])
		{
			if(dis+j.ss<dist[j.ff])
			{
				dist[j.ff]=dis+j.ss;
				pq.push({dist[j.ff],j.ff});
			}
		}
	}
}
int main(int argc, char const *argv[]) {
	file_i_o();
	ll n,m;
	cin>>n>>m;
	vector<pair<ll,ll>> adj[n+1],radj[n+1];
	vector<vector<ll>> v1(m);
	loop(i,0,m-1)
	{
		ll u,v,w;
		cin>>u>>v>>w;
		adj[u].pb({v,w});
		radj[v].pb({u,w});
		v1[i]={u,v,w};
	}
	ll dist1[n+1]={0};
	ll dist2[n+1]={0};
	//loop(i,1,n) cout<<dist1[i]<<" ";
	dijkstra(1,n,adj,dist1);
	dijkstra(n,n,radj,dist2);
	ll mi=inf;
	loop(i,0,m-1)
	{
		ll u=v1[i][0];
		ll v=v1[i][1];
		ll w=v1[i][2];
		mi=min(mi,dist1[u]+dist2[v]+w/2);
	}
	cout<<mi<<endl;

	return 0;
}