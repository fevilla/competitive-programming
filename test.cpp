#include <bits/stdc++.h>

using namespace std;

#define f(i, a, b) for (int i = a; i < b; i++)
int main()
{

  int n = 100, cont = 0;
  while (n)
  {
    cont++;
    --n;
  }

  cout << cont;

  return 0;
}