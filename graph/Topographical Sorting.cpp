#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[100];
bool v[100] = {0};
stack<int> st;

void dfs(int s)
{
    v[s] = true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(!v[adj[s][i]])
            dfs(adj[s][i])
    }
    
    stack.push(s);
}

int main() 
{
    // Nos. of Nodes
    ll n;
    cin >> n;
    
    // Nos. of Edges
    ll m;
    cin >> m;
    
    for(int i=0;i<m;i++)
	{
	    int a,b;
	    cin >> a >> b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}

    for(int i=0;i<n;i++)
    {
        if(!v[i])
            dfs(i);
    }
    
    for(int i=0;i<st.size();i++)
    {
        cout << st.front() << " ";
        st.pop)();
    }
    
	return 0;
}
