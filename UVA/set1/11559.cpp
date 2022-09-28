
#include <bits/stdc++.h>

#define f(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int main()
{
  int N, P, H, W, cost, bed;

  while (scanf("%d %d %d %d", &N, &P, &H, &W) == 4)
  {
    int minCost = 10001, accBed = 0;
    f(i, 0, H)
    {
      scanf("%d", &cost);
      if (accBed < N)
      {
        minCost = 10001;
      }

      f(j, 0, W)
      {
        scanf("%d", &bed);
        accBed = max(accBed, bed);
      }

      if (accBed >= N)
        minCost = min(minCost, cost);
    }

    if (minCost * N > P)
      printf("stay home\n");
    else
      printf("%d\n", minCost * N);
  }

  return 0;
}