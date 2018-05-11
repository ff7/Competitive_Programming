#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

#define MAX 300001
#define MK make_pair 
#define Set(v,x) memset(  v , x , sizeof(v))
#define COST first
#define V1 second.first
#define V2 second.second
typedef pair<int,int> PII;

int nv = 0;

struct elGraph{  // Edge List
  int ne, n;
  pair < int, PII > edge[MAX];
  elGraph (int s) { n = s; ne = 0; }
  void createGraph(int nv){
    this->n = nv;
    this->ne = 0;
  }
  void addEdge(int src, int dst, int c) { edge[ne++]= MK(c, PII(src, dst)); }
};

elGraph g(nv);

struct uf{
  int p[MAX], rank[MAX], number[MAX];
  int size, sets;

  uf(int s){
    size = sets = s;
    for (int i = 0; i < size; i++) 
      { p[i]=i; rank[i]=0; number[i]=1; }
  }

  void link(int x, int y) {
    if(x == y) return;
    if (rank[x] <= rank[y]) {
        p[x] = y;
        --sets;
        number[y] += number[x];
        if (rank[x] == rank[y])
          rank[y]++;
    } else link(y, x);
  }

  int find_set(int x) {
    if (x != p[x]) p[x] = find_set(p[x]);
    return p[x];
  }

  int find_length(int x) {
    return number[ find_set(p[x]) ];
  }

  void union_set(int x, int y) {
    link(find_set(x), find_set(y));
  }
};

int kruskal(elGraph & g, int mst[]){
  for(int i=0; i < g.ne; i++) mst[i] = false;
  uf s(g.n);
  int i , minimum = 0;
  
  sort(g.edge, g.edge + g.ne);
  for( i=0; i < g.ne; i++)
    if(s.find_set(g.edge[i].V1) != s.find_set(g.edge[i].V2)) {
      s.union_set(g.edge[i].V1, g.edge[i].V2);
      mst[i] = true;
      minimum += g.edge[i].COST;
    }
  return minimum;
}

int main()
{
  int t, p, nv, ne;
  cin >> t >> p >> nv >> ne;
  g.createGraph(nv);

  int mst[MAX];
  for (int i = 0; i < ne; i++)
  {
    int a, b, weight;
    cin >> a >> b >> weight;
    g.addEdge(a,b,weight);
  }

  cout << kruskal(g, mst) * p << endl;
  return 0;
}