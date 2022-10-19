#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)
#define ll long long
using namespace std;

const int N = 2e5 + 5;

ll V[7];

string s;

ll fenwick[N][7];
int n, q, inx;
ll val;

void update(int x, int newP)
{
  int oldP = s[x - 1] - '0';
  s[x - 1] = newP + '0';
  while (x <= n)
  {
    fenwick[x][oldP]--;
    fenwick[x][newP]++;
    x += (x & (-x));
  }
}

void updateVal(int x, ll val)
{
  V[x - 1] = val;
}

int query(int x)
{
  ll sum = 0;
  while (x > 0)
  {
    f(i, 1, 7) sum += fenwick[x][i] * V[i - 1];
    x -= (x & (-x));
  }
  return sum;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;

  cin >> n >> q;

  for (int i = 0; i < 6; i++)
    cin >> V[i];

  cin >> s;
  int m;

  f(i, 1, n + 1)
      f(j, 1, 7) fenwick[i][j] = 0;
  f(i, 1, n + 1)
  {
    m = i;
    while (m <= n)
    {
      fenwick[m][(s[i - 1] - '0')]++;
      m += (m & (-m));
    }
  }

  int a, l, r, px;
  f(i, 0, q)
  {
    cin >> a;
    cout << a;
    switch (a)
    {
    case 1:
      cin >> inx >> px;
      update(inx, px);
      break;
    case 2:
      cin >> inx >> val;
      updateVal(inx, val);
      break;
    case 3:
      cin >> l >> r;
      cout << query(r) - query(l - 1) << "\n";
      break;
    }
  }

  return 0;
}