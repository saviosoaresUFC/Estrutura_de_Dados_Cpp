#include <queue>
#include <iostream>
using namespace std;

#define atividade "06"
#define nome "Savio de Carvalho Soares"
#define matricula "552882"

void alternativeRadixsort(int u[], int n, int d)
{
  queue<int> buckets[2];
  /* implementar ordenação por raiz, utilizando apenas dois buckets
  int u[]:vetor de entrada
  int n: comprimento de u
  int d: numero maximo de digitos
  observação: as entradas sao formadas por numeros inteiros positivos
  */

  int qntBits = d * 4;

  for (int i = 0; i < qntBits; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int bit = (u[j] >> i) & 1;
      buckets[bit].push(u[j]);
    }

    int index = 0;
    for (int b = 0; b < 2; b++)
    {
      while (!buckets[b].empty())
      {
        u[index++] = buckets[b].front();
        buckets[b].pop();
      }
    }
  }
}
