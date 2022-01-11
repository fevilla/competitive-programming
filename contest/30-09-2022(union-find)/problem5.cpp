#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int P[1000000];
int R[1000000];
int sum[1000000];
int size[1000000];

void unionFind(int tam)
{
  f(i, 0, tam)
      P[i] = i;
  f(i, 0, tam)
      R[i] = 0;
  f(i, 0, tam)
      sum[i] = i;
  f(i, 0, tam)
      size[i] = 1;
}

int findSet(int i)
{
  return (P[i] == i) ? i : findSet(P[i]);
}

bool isSameSet(int i, int j)
{
  return (findSet(i) == findSet(j));
}

void UnionSet(int i, int j)
{

  if (!isSameSet(i, j))
  {
    int x = findSet(i), y = findSet(j);
    if (R[x] < R[y])
    {
      P[x] = y;
      sum[y] += x;
      size[y] += size[x];
    }
    else
    {
      P[y] = x;
      sum[x] += y;
      size[x] += size[y];
      if (R[x] == R[y])
      {
        R[x]++;
      }
    }
  }
}

void moveSet(int i, int j, int tam)
{
  int x = findSet(i);
  int y = findSet(j);
  if (x == y)
    return;
  P[i] = y;
  size[x]--;
  sum[x] -= i;
  size[y]++;
  sum[y] += i;
}

int main()
{

  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, op, p, q;
  while (cin >> n >> m)
  {
    n++;
    unionFind(n);
    f(i, 0, m)
    {
      cin >> op;
      switch (op)
      {
      case 1:
        cin >> p >> q;
        UnionSet(p, q);
        break;
      case 2:
        cin >> p >> q;
        moveSet(p, q, n);
        break;
      case 3:
        cin >> p;
        int x = findSet(p);
        cout << size[x] << " " << sum[x];
        cout << endl;
        break;
      }
    }
  }
}