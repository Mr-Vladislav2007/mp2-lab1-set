// ннгу, вмк, курс "методы программирования-2", с++, ооп
//
// sample_prime_numbers.cpp - copyright (c) гергель в.п. 20.08.2000
//   переработано для microsoft visual studio 2008 сысоевым а.в. (19.04.2015)
//
// тестирование битового поля и множества

#include <iomanip>

// #define use_set // использовать класс tset,
                // закоментировать, чтобы использовать битовое поле

#ifndef use_set // использовать класс tbitfield

#include "tbitfield.h"

int main()
{
  int n, m, k, count;

  setlocale(LC_ALL, "russian");
  cout << "тестирование программ поддержки битового поля" << endl;
  cout << "             решето эратосфена" << endl;
  cout << "введите верхнюю границу целых значений - ";
  cin  >> n;
  TBitField s(n + 1);
  // заполнение множества
  for (m = 2; m <= n; m++)
    s.SetBit(m);
  // проверка до sqrt(n) и удаление кратных
  for (m = 2; m * m <= n; m++)
    // если m в s, удаление кратных
    if (s.GetBit(m))
      for (k = 2 * m; k <= n; k += m)
        if (s.GetBit(k))
          s.ClrBit(k);
  // оставшиеся в s элементы - простые числа
  cout << endl << "печать множества некратных чисел" << endl << s << endl;
  cout << endl << "печать простых чисел" << endl;
  count = 0;
  k = 1;
  for (m = 2; m <= n; m++)
    if (s.GetBit(m))
    {
      count++;
      cout << setw(3) << m << " ";
      if (k++ % 10 == 0)
        cout << endl;
    }
  cout << endl;
  cout << "в первых " << n << " числах " << count << " простых" << endl;
}
#else

#include "tset.h"

int main()
{
  int n, m, k, count;

  setlocale(lc_all, "russian");
  cout << "тестирование программ поддержки множества" << endl;
  cout << "              решето эратосфена" << endl;
  cout << "введите верхнюю границу целых значений - ";
  cin  >> n;
  tset s(n + 1);
  // заполнение множества
  for (m = 2; m <= n; m++)
    s.inselem(m);
  // проверка до sqrt(n) и удаление кратных
  for (m = 2; m * m <= n; m++)
    // если м в s, удаление кратных
    if (s.ismember(m))
      for (k = 2 * m; k <= n; k += m)
       if (s.ismember(k))
         s.delelem(k);
  // оставшиеся в s элементы - простые числа
  cout << endl << "печать множества некратных чисел" << endl << s << endl;
  cout << endl << "печать простых чисел" << endl;
  count = 0;
  k = 1;
  for (m = 2; m <= n; m++)
    if (s.ismember(m))
    {
      count++;
      cout << setw(3) << m << " ";
      if (k++ % 10 == 0)
        cout << endl;
    }
  cout << endl;
  cout << "в первых " << n << " числах " << count << " простых" << endl;
}

#endif