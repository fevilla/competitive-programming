#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;
const int d = 1e5 + 5;
const int N = 2 * d;
int fenwick[N];
int ubication[d];
int pos = 200009;

void update(int x, int val)
{
  while (x < N)
  {
    fenwick[x] += val;
    x += (x & (-x));
  }
}

int query(int x)
{
  int sum = 0;
  while (x > pos)
  {
    sum += fenwick[x];
    x -= (x & (-x));
  }
  return sum;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--)
  {
    int m, r;
    cin >> m >> r;

    memset(fenwick, 0, sizeof fenwick);

    pos = 200009;
    for (int i = m; i >= 1; i--)
    {
      update(pos, 1);
      ubication[i] = pos--;
    }

    int a;
    for (int i = 0; i < r; i++)
    {
      cin >> a;
      cout << query(ubication[a] - 1) << " ";
      update(ubication[a], -1);
      ubication[a] = pos--;
      update(ubication[a], 1);
    }

    cout << "\n";
  }
  return 0;
}
