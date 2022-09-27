#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)
using namespace std;

void L(int *x) { (*x)--; }
void R(int *x) { (*x)++; }

int main()
{
  int t, n, x, p, pos, memor[101];
  string ins, aux;
  cin >> t;
  while (t--)
  {
    cin >> n;
    x = 0;
    pos = 0;
    f(i, 0, n)
    {
      cin >> ins;
      if (ins[0] == 'L')
      {
        L(&x);
        memor[++pos] = -1;
      }
      else if (ins[0] == 'R')
      {
        R(&x);
        memor[++pos] = 0;
      }
      else
      {
        cin >> aux >> p;
        memor[++pos] = memor[p];
        (!memor[p]) ? R(&x) : L(&x);
      }
    }
    printf("%d \n", x);
  }
}