
//#include <iostream>
//#include "tbitfield.h"
//#include <locale>
//
//void testtbitfield()
//{
//    setlocale(lc_all, "russian");
//    {
//        tbitfield bf(8);
//        cout << "the length of the bit field: " << bf.getlength() << endl;
//
//        for (int i = 0; i < 8; i++)
//            bf.setbit(i);
//
//        cout << "the bit field after setting all bits: ";
//        cout << bf << endl;
//    }
//
//    {
//        tbitfield bf(8);
//
//        bf.setbit(3);
//        cout << "the bit field after setting the 4th bit: " << bf << endl;
//
//        bf.clrbit(3);
//        cout << "the bit field after clearing the 4th bit: " << bf << endl;
//    }
//
//    {
//        tbitfield bf1(8), bf2(8);
//        bf1.setbit(0);
//        bf1.setbit(1);
//        bf2.setbit(2);
//        bf2.setbit(3);
//
//        cout << "the first beaten field: " << bf1 << endl;
//        cout << "the second beaten field: " << bf2 << endl;
//
//        tbitfield bfor = bf1 | bf2;
//        cout << "bitwise or: " << bfor << endl;
//
//        tbitfield bfand = bf1 & bf2;
//        cout << "bitwise and: " << bfand << endl;
//
//        tbitfield bfnot = ~bf1;
//        cout << "negation of the first field: " << bfnot << endl;
//    }
//
//    {
//        tbitfield bf(8);
//        cout << "enter the bit sting: ";
//        cin >> bf;
//
//        cout << "the entered bit field: " << bf << endl;
//    }
//}
//
//int main()
//{
//    setlocale(lc_all, "russian");
//    cout << "class testing tbitfield" << endl;
//
//    testtbitfield();
//    cout << endl << "the testing has been completed successfully!" << endl;
//
//    return 0;
//}







//#include <iostream>
//#include <locale>
//#include "tset.h"
//
//using namespace std;
//
//void testtset()
//{
//    setlocale(LC_ALL, "Russian");
//    {
//        TSet s(8);
//        cout << "Maximum power of the set: " << s.GetMaxPower() << endl;
//
//        for (int i = 0; i < 8; i++)
//            s.InsElem(i);
//
//        cout << "The set after inserting all elements: ";
//        cout << s << endl;
//    }
//
//    {
//        TSet s(8);
//
//        s.InsElem(3);
//        cout << "The set after inserting the 4th element: " << s << endl;
//
//        s.DelElem(3);
//        cout << "The set after deleting the 4th element: " << s << endl;
//    }
//
//    {
//        TSet s1(8), s2(8);
//        s1.InsElem(0);
//        s1.InsElem(1);
//        s2.InsElem(2);
//        s2.InsElem(3);
//
//        cout << "The first set: " << s1 << endl;
//        cout << "The second set: " << s2 << endl;
//
//        TSet sUnion = s1 + s2;
//        cout << "union: " << sUnion << endl;
//
//        TSet sIntersect = s1 * s2;
//        cout << "intersection: " << sIntersect << endl;
//
//        TSet sComplement = ~s1;
//        cout << "complement of the first set: " << sComplement << endl;
//    }
//
//    {
//        TSet s1(8), s2(8);
//        s1.InsElem(0);
//        s1.InsElem(1);
//        s2.InsElem(0);
//        s2.InsElem(1);
//
//        cout << "Comparison of equal sets s1 and s2: " << (s1 == s2) << endl;
//        cout << "Comparison of sets s1 and ~s1: " << (s1 == ~s1) << endl;
//    }
//
//    {
//        TSet s(8);
//        s.InsElem(2);
//        s.InsElem(5);
//
//        cout << "Membership check: is 2 in set? " << s.IsMember(2) << endl;
//        cout << "Membership check: is 4 in set? " << s.IsMember(4) << endl;
//
//        TSet s2 = s + 7;
//        cout << "The set after adding element 7: " << s2 << endl;
//
//        TSet s3 = s - 2;
//        cout << "The set after removing element 2: " << s3 << endl;
//    }
//
//    {
//        TSet s(8);
//        cout << "Enter the set (MaxPower, count, then elements): ";
//        cin >> s;
//
//        cout << "The entered set: " << s << endl;
//    }
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    cout << "Class testing TSet" << endl;
//
//    testtset();
//    cout << endl << "The testing has been completed successfully!" << endl;
//
//    return 0;
//}




//
//#include <iostream>
//#include "set.h"
//using namespace std;
//
//void Sieve(int N)
//{
//    TSet primes(N + 1);
//
//    for (int i = 2; i <= N; ++i)
//        primes.InsElem(i);
//
//    for (int i = 2; i * i <= N; ++i)
//    {
//        if (primes.IsMember(i))
//        {
//            for (int j = i * i; j <= N; j += i)
//                primes.DelElem(j);
//        }
//    }
//
//    cout << "Prime numbers up to " << N << ": ";
//    cout << primes << endl;
//}
//
//int main()
//{
//    int N;
//    cout << "Enter the upper bound N: ";
//    cin >> N;
//
//    if (N < 2)
//    {
//        cout << "There are no prime numbers in the range." << endl;
//        return 0;
//    }
//
//    Sieve(N);
//
//    return 0;
//}