#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
bool v[100] = {0};

int dfs(int s,int parent)
{
    v[s] = true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(!v[adj[s][i]])
        {
            if(dfs(adj[s][i], s))
            return true;
        }
        else if(parent != adj[s][i])
        return true;
    }
    return false;
}

int main() 
{
	// your code goes here
	
	// Nos. of Nodes
	int n;
	cin >> n;
	// Nos of Edges
	int m;
	cin >> m;
	
	for(int i=0;i<m;i++)
	{
	    int a,b;
	    cin >> a >> b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	
	cout << '\n'<< dfs(0,-1);
}
