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
#define pb 				emplace_back
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
class trieNode{
public:
	bool isEnd;
	trieNode* children[26];
};
trieNode* getNode(){
	trieNode* node=new trieNode();
	for(int i=0;i<26;i++)
	{
		node->children[i]=NULL;
	}
	node->isEnd=false;
	return node;
}
void insert(trieNode* root,string word)
{
	trieNode* head=root;
	int n=word.length();
	for(int i=0;i<n;i++)
	{
		int idx=word[i]-'a';
		if(head->children[idx]==NULL)
		{
			head->children[idx]=getNode();
		}
		head=head->children[idx];
	}
	head->isEnd=true;
}
bool search(trieNode* root,string word)
{
	trieNode* head=root;
	int n=word.length();
	for(int i=0;i<n;i++)
	{
		int idx=word[i]-'a';
		if(head->children[idx]==NULL) return false;
		head=head->children[idx];
	}
	return head->isEnd;
}
bool prefix(trieNode* root,string word)
{
	trieNode* head=root;
	int n=word.length();
	for(int i=0;i<n;i++)
	{
		int idx=word[i]-'a';
		if(head->children[idx]==NULL) return false;
		head=head->children[idx];
	}
	return true;
}
int main(int argc, char const *argv[]) {
	file_i_o();
	trieNode* root=getNode();
	insert(root,"man");
	insert(root,"mango");
	insert(root,"banana");
	insert(root,"bang");
	insert(root,"mann");

	bool ans=search(root,"banana");
	if(ans==true)
	{
		cout<<"Found"<<endl;
	}
	else{
		cout<<"Not Found"<<endl;
	}
	ans=prefix(root,"bang");
	if(ans==true)
	{
		cout<<"Prefix Found"<<endl;
	}
	else{
		cout<<"Prefix Not Found"<<endl;
	}
	return 0;
}
