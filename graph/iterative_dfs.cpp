//rohanm9
//DA-IICT,Gandhinagar
//output of this and recursive dfs would be different but both are doing the same 
// thing search depth first just the difference would here will process the last 
// neighbour in the adjlist first
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define NINF LLONG_MIN
#define INF LLONG_MAX
#define For(i,a,b) for(ll i=a;i<b;i++)
#define FoR(i,a,b) for(ll i=a;i<=b;i++)
#define rFor(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define print(a) cout<<a<<"\n"
const ll mod=1e9+7;
vector<vector<ll>>adjList;
vector<ll>visited;
void solve(){
    ll n,m;
    cin>>n>>m;
    // assuming that nodes are having value from 1 to n
    adjList.resize(n+1);
    visited.resize(n+1,false);
    For(i,0,m){
        ll a,b;
        cin>>a>>b;
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    ll root;
    cin>>root;
    stack<ll>s;
    s.push(root);
    while(!s.empty()){
        ll v=s.top();
        s.pop();
        if(!visited[v]){
            cout<<v<<" ";
            visited[v]=true;
        }
        for(auto &u:adjList[v]){
            if(!visited[u]){
                s.push(u);
            }
        }
    }
    print("");
}
int main(){
    ios::sync_with_stdio(false),cin.tie(NULL);
    solve();
}
// to stop c++ using scientific notation
// cout.setf(ios::fixed);
// cout<<setprecision(0)<<value;