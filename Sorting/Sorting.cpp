#include "stdafx.h"
#include "time.h"
#include <iostream>
using namespace std;

unsigned long int const n = 200000;

void bubbleSort(unsigned long int n, float *a) {
  unsigned long int l, k;
  float p;
  l = n;
  do {
    k = 0;
    l--;
    for (unsigned long i = 1; i <= l; i++) {
      if (a[i] > a[i + 1]) {
        p = a[i];
        a[i] = a[i + 1];
        a[i + 1] = p;
        k++;
      }
    }
  } while (k != 0);
}

void insert_sort(unsigned  long int n, float * a)
{
  unsigned  long int l, p, k, s;
  float w = 0;
  a[0] = w;
  for (unsigned long int i = 2; i <= n; i++)
  {
    float y = a[i];
    l = 0;
    p = i - 1;
    do
    {
      s = (l + p + 1) / 2;
      if (a[s] <= y) l = s; else p = s - 1;
    } while (l != p);
    k = l;
    for (unsigned long int j = i - 1; j >= k + 1; j--) a[j + 1] = a[j];
    a[k + 1] = y;
  }
}

void chooseSortMethod(int k, long int m, float *a) {
  clock_t tp, tk;
  double tc;
  switch (k)
  {
  case 1:
  {
    cout << "Babelkowa" << endl;
    tp = clock();
    bubbleSort(m, a);
    tk = clock();
    tc = (tk - tp) / double(CLOCKS_PER_SEC);
    cout << "czas sortowania" << tc << endl;
    break;
  }
  case 2:
  {
    cout << "Przez wstawianie" << endl;
    tp = clock();
    insert_sort(m, a);
    tk = clock();
    tc = (tk - tp) / double(CLOCKS_PER_SEC);
    cout << "czas sortowania" << tc << endl;
    break;
  }
  case 0: break;
  }
}

int main()
{
  unsigned long int m;
  int k;
  float *a = new float[n];
  time_t t;
  srand((unsigned)time(&t));
  do {
    cout << "Podaj liczbe liczb w ciagu" << endl;
    cin >> m;
    cout << "Podaj nr procedury" << "\n";
    cin >> k;
    cout << "Ciag wylosowany" << endl;
    for (unsigned long int i = 1; i <= m; i++) {
      a[i] = rand() % 10000;
      cout << a[i] << "\t";
    }
    cout << endl;

    chooseSortMethod(k, m, a);

    cout << "ciag posortowany" << endl;
    for (unsigned long int i = 1; i <= m; i++) {
      cout << a[i] << endl;
    }
  } while (k != 0);
}

