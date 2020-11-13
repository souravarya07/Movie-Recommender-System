#include<bits/stdc++.h>
using namespace std;
#define NIL 0
#define INF INT_MAX

class BipGraph
{
    int m, n;
    list<int> *adj;
    int *pairU, *pairV, *dist;
    public:
      BipGraph(int m, int n);
      void addEdge(int u, int v);
      bool bfs();
      bool dfs(int u);
      int hopcroftKarp();
};

int BipGraph::hopcroftKarp()
{
    dist = new int[m+1];
    for (int u=0; u<m; u++)
        pairU[u] = NIL;
    for (int v=0; v<n; v++)
        pairV[v] = NIL;
    int result = 0;
    while (bfs())
    {
        for (int u=1; u<=m; u++)
        if (pairU[u]==NIL && dfs(u))
        result++;
    }
    return result;
}

bool BipGraph::bfs()
{
    queue<int> Q; //an integer queue
    // First layer of vertices (set distance as 0)
    for (int u=1; u<=m; u++)
    {
        // If this is a free vertex, add it to queue
        if (pairU[u]==NIL)
        {
        // u is not matched
        dist[u] = 0;
        Q.push(u);
        }
        // Else set distance as infinite so that this vertex
        // is considered next time
        else dist[u] = INF;
    }
    // Initialize distance to NIL as infinite
    dist[NIL] = INF;
    // Q is going to contain vertices of left side only.
    while (!Q.empty())
    {
        // Dequeue a vertex
        int u = Q.front();
        Q.pop();
        list<int>::iterator i;
        for (i=adj[u].begin(); i!=adj[u].end(); ++i)
        {
            int v = *i;
            // If pair of v is not considered so far
            // (v, pairV[V]) is not yet explored edge.
            if (dist[pairV[v]] == INF)
            {
            // Consider the pair and add it to queue
                dist[pairV[v]] = dist[u] + 1;
                Q.push(pairV[v]);
            }
        }
     }
    // If we could come back to NIL using alternating path of distinct  // vertices then there is an augmenting path
    return (dist[NIL] != INF);

    // Returns true if there is an augmenting path beginning with free vertex u  bool BipGraph::dfs(int u)

    if (u != NIL)
        {
          list<int>::iterator i;
          for (i=adj[u].begin(); i!=adj[u].end(); ++i)
          {
          // Adjacent to u
          int v = *i;
          // Follow the distances set by BFS
          if (dist[pairV[v]] == dist[u]+1)
          {
          // If dfs for pair of v also returns
          // true
              if (dfs(pairV[v]) == true)
              {
                  pairV[v] = u;
                  pairU[u] = v;
                  return true;
             }

    }
    // If there is no augmenting path beginning with u.  dist[u] = INF;
       return false;
    }
       return true;
    }
}
// Constructor
BipGraph::BipGraph(int m, int n)
{
    this->m = m;
    this->n = n;
    adj = new list<int>[m+1];
}
    // To add edge from u to v and v to u
void BipGraph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add u to v’s list.
}
// Driver Program
int main()  
{
    BipGraph g(4, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(3, 2);
    g.addEdge(4, 2);
    g.addEdge(4, 4);
    cout << "Size of maximum matching is " << g.hopcroftKarp();
    return 0;
}
