#include <iostream>
using namespace std;


class A1
{
public:
    int Sum(int x, int y)
    {
        int z = 0;
        _asm
        {
            mov eax, x
            add eax, y
            mov z, eax
        }
        return z;
    }
    int Des(int x, int y)
    {
        int z = 0;
        _asm
        {
            mov eax, x
            Sub eax, y
            mov z, eax
        }
        return z;
    }
    int Multi(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mul y
            mov z, eax
        }
        return z;
    }
    int Dele(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov edx, 0
            mov ebx, y
            idiv ebx
            mov z, eax
        }
        return z;
    }

    int More(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ebx, y
            mov edx, 1
            cmp eax, ebx
            ja re
            mov edx, 0
         re:mov z, edx
        }
        return z;
    }
    int moreOrEqual(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ebx, y
            mov edx, 1
            cmp eax, ebx
            jae mOr
            mov edx, 0
        mOr:mov z, edx
        }
        return z;
    }
    int downThen(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ebx, y
            mov edx, 1
            cmp eax, ebx
            jb dt
            mov edx, 0
         dt:mov z, edx
        }
        return z;
    }
    int downThenEqual(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ebx, y
            mov edx, 1
            cmp eax, ebx
            jbe dte
            mov edx, 0
        dte:mov z, edx
        }
        return z;
    }
    int equality(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ebx, y
            mov edx, 1
            cmp eax, ebx
            je eql
            mov edx, 0
        eql: mov z, edx   
        }
        return z;
    }
    int notEquality(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ebx, y
            mov edx, 1
            cmp eax, ebx
            jne nq
            mov edx, 0
         nq:mov z, edx
        }
        return z;
    }

    int positionOperations(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ebx, y
            mov ecx, 1
            mov edx, 0
            cmp eax, ebx
            ja re
            jb dt
            je eql
         re:mov z, 1
            cmp ecx, edx
            ja close   
         dt:mov z, 0
            cmp ecx, edx
            ja close
         eql:mov z, 2
      close: mov z, -1
        }
        return z;
    }

    int Not(int x)
    {
        int z;
        _asm
        {
            mov eax, x
            not eax
            mov z, eax
        }
        return z;
    }
    int And(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ebx, y
            and eax, ebx
            mov z, eax
        }
        return z;
    }
    int Or(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ebx, y
            or eax, ebx
            mov z, eax
        }
        return z;
    }
    int Xor(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ebx, y
            xor eax, ebx
            mov z, eax
        }
        return z;
    }

    int arrayIndex(int* x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ebx, y
            mov ebx, [eax + 4 * ebx]
            mov z, ebx
        }
        return z;
    }

    int logicShiftRight(int x, int y)
    {
        int z;
        _asm
        {
            mov eax, x
            mov ecx, y
            shr eax, cl
            mov z, eax
        }
        return z;
    }
    int logicShiftLeft(unsigned char x, unsigned char y)
    {
        unsigned char z;

        _asm
        {
            mov al, x
            mov cl, y
            shl al, cl
            mov z, al
        }
        return z;
    }

    int loopRight(unsigned char x, unsigned char y)
    {
        unsigned char z;

        _asm
        {
            mov al, x
            mov cl, y
            ror al, cl
            mov z, al
        }
        return z;
    }
    int loopLeft(unsigned char x, unsigned char y)
    {
        unsigned char z;

        _asm
        {
            mov al, x
            mov cl, y
            rol al, cl
            mov z, al
        }
        return z;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    A1 obj;
    cout << " 34 + 25 = " << obj.Sum(34, 25) << "\n";                               // ��������
    cout << " 54 - 40 = " << obj.Des(54, 40) << "\n";                               // ���������
    cout << " 12 * 15 = " << obj.Multi(12, 15) << "\n";                             // ���������
    cout << " 375 / 3 = " << obj.Dele(375, 3) << "\n\n";                            // �������

    cout << "��������� ���������� �� �� ��������,\n true(1), false(0)\n";
    cout << " 15 > 5     : " << obj.More(15, 5) << "\n";                            // ������
    cout << " 123 >= 123 : " << obj.moreOrEqual(123, 123) << "\n";                  // ������ ��� �����
    cout << " 17 < 7     : " << obj.downThen(17, 7) << "\n";                        // ������
    cout << " 35 <= 35   : " << obj.downThenEqual(35, 35) << "\n";                  // ������ ��� �����
    cout << " 56 = 56    : " << obj.equality(56, 56) << "\n";                       // �����
    cout << " 56 != 56   : " << obj.notEquality(56, 56) << "\n\n";                  // �� �����

    cout << "�������� 100 � 20: " << obj.positionOperations(100, 100) << endl << endl; // ������(1), ������(0) ��� �����(2). ������ ��������(-1)

    cout << "�� 35 ��� -36    ? " << obj.Not(35) << endl;                           // ��
    cout << "32 � 25 ��� 32   : " << obj.And(35, 52) << endl;                       // �
    cout << "35 ��� 52 ��� 55 : " << obj.Or(35, 52) << endl;                        // ���
    cout << "35 xor 52 is 23  : " << obj.Xor(35, 52) << endl << endl;               // ����������� ���

    int x[] = { 0, 5, 10, 15, 20, 25, 30 };
    // ���������� ������� �������� (������, ������ �������� ��������)


    cout << "2 ������ �������� � ������� { 0, 5, 10, 15, 20, 25, 30 } ��� �����: " << obj.arrayIndex(x, 2) << endl << endl;

    // ����������� ������� ��� ��� ��
    cout << "���������� ����� ������ : " << obj.logicShiftRight(31, 3) << endl;    // ���������� ����� ������
    cout << "���������� ����� �����  : " << obj.logicShiftLeft(146, 3) << endl;    // ���������� ����� �����

    cout << "���������� ����� ������ : " << obj.loopRight(123, 3) << endl;         // ����������� ����� ������
    cout << "���������� ����� �����  : " << obj.loopLeft(142, 3) << endl;          // ����������� ����� �����
}