#include <iostream>
using namespace std;

const int N = 1e6 + 6;
int fenwick[N], n;
int A[N];

void update(int x)
{
  int val = (A[x]) ? -1 : 1;
  A[x] = !A[x];
  while (x <= n)
  {
    fenwick[x] += val;
    x += (x & (-x));
  }
}

int query(int x)
{
  int sum = 0;
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

  int k, l, r, pos;
  char ident;

  cin >> n >> k;

  for (int i = 0; i < n + 1; i++)
  {
    fenwick[i] = 0;
    A[i] = 0;
  }

  for (int i = 0; i < k; i++)
  {
    cin >> ident;
    switch (ident)
    {
    case 'F':
      cin >> pos;
      update(pos);
      break;
    case 'C':
      cin >> l >> r;
      cout << query(r) - query(l - 1) << "\n";
      break;
    }
  }

  return 0;
}