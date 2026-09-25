// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);
static size_t SIZE = sizeof(TELEM) * 8;

TBitField::TBitField(int len)
{
    BitLen = len;

    if (len < SIZE)
        MemLen = 1;
    else
        MemLen = (len - 1) / SIZE + 1;

    //MemLen = len / SIZE + (len % SIZE > 0); ???????????????

    pMem = new TELEM[BitLen];

    std::memset(pMem, 0, sizeof(TELEM) * MemLen);

}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    this->BitLen = bf.BitLen;
    this->pMem = new TELEM[bf.BitLen];
    this->MemLen = bf.MemLen;

    for (int i = 0; i < this->MemLen; i++)
        this->pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
    delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    return (n / SIZE) + ((n % SIZE) != 0);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if (n < 0 || n >= BitLen)
        throw n;

    return (1 << (n & (SIZE - 1)));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
    return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n < 0 || n >= BitLen)
        throw n;
    if (n >= 0 && n < BitLen)
    {
        TELEM mask = GetMemMask(n);
        pMem[GetMemIndex(n)] |= mask;
    }
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n < 0 || n >= BitLen)
        throw n;
    if (n >= 0 && n < BitLen)
    {
        TELEM mask = GetMemMask(n);
        pMem[GetMemIndex(n)] &= ~mask;
    }
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0 || n >= BitLen)
        throw n;
    if (n >= 0 && n < BitLen)
    {
        TELEM mask = GetMemMask(n);
        return pMem[GetMemIndex(n)] & mask;
    }
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this == &bf)
        return *this;

    this->BitLen = bf.BitLen;
    this->MemLen = bf.MemLen;

    delete[] this->pMem;

    this->pMem = new TELEM[bf.BitLen];
    for (int i = 0; i < bf.BitLen; i++)
        this->pMem[i] = bf.pMem[i];


    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    int res = 1;
    if (BitLen != bf.BitLen)
        res = 0;
    else
    {
        for (int i = 0; i < BitLen; i++)
        {
            TELEM memMask = 0;
            if (i < memMask - 1)
                memMask = 0xffffffff;
            else
                memMask = (1 << (BitLen % SIZE)) - 1;

            if ((memMask & pMem[i]) != (memMask & bf.pMem[i]))
            {
                res = 0;
                break;
            }
        }
    }

    return res;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int len = BitLen;
    if (bf.BitLen > len)
        len = bf.BitLen;

    TBitField tmp(len);
    for (int i = 0; i < MemLen; i++)
    {
        tmp.pMem[i] = pMem[i];
    }

    for (int i = 0; i < MemLen; i++)
    {
        tmp.pMem[i] |= bf.pMem[i];
    }

    return tmp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    int len = BitLen;
    if (bf.BitLen > len)
        len = bf.BitLen;

    TBitField tmp(len);
    for (int i = 0; i < MemLen; i++)
    {
        tmp.pMem[i] = pMem[i];
    }

    for (int i = 0; i < bf.MemLen; i++)
    {
        tmp.pMem[i] &= bf.pMem[i];
    }

    return tmp;
}

TBitField TBitField::operator~(void) // отрицание
{
    int len = BitLen;

    TBitField tmp(len);
    for (int i = 0; i < MemLen; i++)
    {
        tmp.pMem[i] = ~pMem[i];
    }

    return tmp;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    int i = 0;
    char ch;

    while (true)
    {
        istr >> ch;
        if (ch == '0')
            bf.ClrBit(i++);
        else
        {
            if (ch == '1')
                bf.SetBit(i++);
            else
                break;
        }
    }

    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    int len = bf.BitLen;
    for (int i = 0; i < len; i++)
    {
        ostr << bf.GetBit(i);
    }

    return ostr;
}
