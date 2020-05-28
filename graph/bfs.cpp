#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,a,n) for(ll i=a;i<n;i++)
#define FoR(i,a,n) for(ll i=a;i<=n;i++)
#define rFor(i,n,a) for(ll i=n-1;i>=a;i--)
#define INF LLONG_MAX
#define NINF LLONG_MIN
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(),a.end()
#define print(a) cout<<a<<"\n";
vector<vector<ll>>adjList;
vector<bool>visited;
void solve(){
    ll n;
    cin>>n;
    ll m;
    cin>>m;
    adjList.resize(n+1);
    visited.resize(n+1,false);
    For(i,0,m){
        ll a,b;
        cin>>a>>b;
        // a is connected to b 
        // a---b considering graph to be undirected
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    ll root;
    cin>>root;
    queue<ll>q;
    q.push(root);
    visited[root]=true;
    while(!q.empty()){
        ll v=q.front();
        cout<<v<<" ";
        q.pop();
        for(auto &x:adjList[v]){
            if(visited[x]!=true){
                q.push(x);
                visited[x]=true;
            }
        }
    }
    print("");   
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    solve();
    return 0;
}