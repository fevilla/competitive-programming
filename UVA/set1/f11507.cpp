#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;

string check(string a, string b)
{
  if (a[1] == 'x')
  {
    if (a[0] == '-')
      return (b[0] == '+') ? "-" + b[1] : "+" + b[1];
    else
      return b;
  }
  else if (a[1] == b[1])
    return (a[0] == b[0]) ? "-x" : "x";
  else
    return a;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  string act, next;
  while (cin >> t)
  {

    cin >> act;
    f(i, 1, t)
    {
      cin >> next;
      act = check(act, next);
      act = next;
    }
  }
  return 0;
}