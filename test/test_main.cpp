
#include <iostream>
#include "tbitfield.h"
#include <locale>

void testTBitField()
{
    setlocale(LC_ALL, "Russian");
    {
        TBitField bf(8);
        cout << "The length of the bit field: " << bf.GetLength() << endl;

        for (int i = 0; i < 8; i++)
            bf.SetBit(i);

        cout << "The bit field after setting all bits: ";
        cout << bf << endl;
    }

    {
        TBitField bf(8);

        bf.SetBit(3);
        cout << "The bit field after setting the 4th bit: " << bf << endl;

        bf.ClrBit(3);
        cout << "The bit field after clearing the 4th bit: " << bf << endl;
    }

    {
        TBitField bf1(8), bf2(8);
        bf1.SetBit(0);
        bf1.SetBit(1);
        bf2.SetBit(2);
        bf2.SetBit(3);

        cout << "The first beaten field: " << bf1 << endl;
        cout << "The second beaten field: " << bf2 << endl;

        TBitField bfOr = bf1 | bf2;
        cout << "Bitwise OR: " << bfOr << endl;

        TBitField bfAnd = bf1 & bf2;
        cout << "Bitwise AND: " << bfAnd << endl;

        TBitField bfNot = ~bf1;
        cout << "Negation of the first field: " << bfNot << endl;
    }

    {
        TBitField bf(8);
        cout << "Enter the bit sting: ";
        cin >> bf;

        cout << "The entered bit field: " << bf << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Class testing TBitField" << endl;

    testTBitField();
    cout << endl << "The testing has been completed successfully!" << endl;

    return 0;
}