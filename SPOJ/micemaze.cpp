#include <iostream>
#include <algorithm>

using namespace std;

// Macros
#define FOR(i,n)        for (int i = 0 ; i < (n) ; i++)
#define MAX             500
#define INF             1000000000

void floyd(int g[MAX][MAX], int n) {
  FOR(i, n) g[i][i] = 0;
  FOR(k, n) FOR(i, n)
    if (g[i][k] != INF) FOR (j, n)
      g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
}

int main(){
  int n, e, t, m;
  cin >> n >> e >> t >> m;
  e--;
  int g[MAX][MAX];

  FOR(i1,MAX)
  FOR(i2,MAX)
  g[i1][i2] = INF;

  FOR(i, m)
  {
    int a, b, weight;
    cin >> a >> b >> weight;
    a--;
    b--;
    g[a][b] = weight;
  }
  
  floyd(g, n);

  int count = 0;
  for (int i = 0; i < n; i++)
  {
      if (g[i][e] <= t)
        count++;
  }
  cout << count << endl;
  return 0;
}