#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int P[1000000];
int R[1000000];

void unionFind(int tam)
{
  f(i, 0, tam)
      P[i] = i;
  f(i, 0, tam)
      R[i] = 0;
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
  int x = findSet(i), y = findSet(j);
  if (x != y)
  {
    if (R[x] < R[y])
      P[x] = y;
    else
    {
      P[y] = x;
      if (R[x] == R[y])
        R[x]++;
    }
  }
}

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, p, q;
  char op;
  while (cin >> n >> m)
  {
    unionFind(n);
    f(i, 0, m)
    {
      cin >> op;
      switch (op)
      {
      case '?':
        cin >> p >> q;
        if (isSameSet(p, q))
          cout << "yes\n";
        else
          cout << "no\n";
        break;
      case '=':
        cin >> p >> q;
        UnionSet(p, q);
        break;
      }
    }
  }
}