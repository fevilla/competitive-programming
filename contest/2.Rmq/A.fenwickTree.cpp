#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)
#define ll long long
using namespace std;

const int N = 5e6 + 5;
int n;

ll fenwick[N];

void update(ll valor, int x)
{
  while (x <= n)
  {
    fenwick[x] += valor;
    x += (x & (-x));
  }
}

ll query(int x)
{
  ll sum = 0;
  while (x > 0)
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

  ll t, val, val2;
  char c;
  cin >> n >> t;

  for (int i = 0; i < n; i++)
    fenwick[i] = 0;

  while (t--)
  {
    cin >> c;
    switch (c)
    {
    case '?':
      cin >> val;
      cout << query(val + 1) << "\n";
      break;
    case '+':
      cin >> val >> val2;
      update(val2, val + 1);
      break;
    }
  }

  return 0;
}