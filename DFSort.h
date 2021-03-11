
#include "TXLib.h"

void ReplacerDF (int Mass [], int Size, int Slot1, int Slot2);

int BinaryFinder (int Mass [], int SortSize, int SortElem);

void DFSort (int Mass [], int Size);


void ReplacerDF (int Mass [], int Size, int Slot1, int Slot2)
    {

    //GJM_printf (Mass, Size);

    assert (0 <= Slot1 && Slot1 < Size);

    if (Slot1 == Slot2) return;

    int Temp = Mass [Slot1];

    Change = Change + 1;

    int Mag = Slot2;

    for (int I = Slot1 - 1; I >= Slot2; I--)
        {
        assert (0 <= Slot1 && Slot1 < Size);
        assert (0 <= Slot2 && Slot2 < Size);

        Mass [I+1] = Mass [I];

        Change = Change + 1;

        //GJM_printf (Mass, Size);

        Mag++;
        }

    assert (0 <= Slot2 && Slot2 < Size);

    Mass [Slot2] = Temp;

    Change = Change + 1;

    }

int BinaryFinder (int Mass [], int SortSize, int SortElem)
    {
    int Left = 0;
    int Right = SortSize - 1;

    while (Right-Left != 1)
        {
        Compare = Compare + 1;

        int Middle = (Left + Right)/2;

        //printf ("��� %d ", Left);
        //printf ("����� %d ", Right);
        //printf ("������� �������� %d\n", Middle);

        //Control (Mass, SortSize, Left, Right, Middle, "�� ���");

        if (SortElem > Mass [Middle])
            {
            Left = Middle;
            }
        else if (SortElem < Mass [Middle])
            {
            Right = Middle;
            }
        else break;

        //Control (Mass, SortSize, Left, Right, Middle, "����� ���");

        //printf ("��� %d ", Left);
        //printf ("����� %d ", Right);
        //printf ("������� �������� %d\n", Middle);

        _getch;
        }

    if (SortElem <= Mass [Left])
        {
        return Left;
        }

    if (SortElem >= Mass [Right])
        {
        return Left+2;
        }

    return Left + 1;
    }

void DFSort (int Mass [], int Size)
    {

    if (Size < 2)
        {
        printf ("�� ��������� ������ \n");

        return;
        }

    if (Mass [0] > Mass [1])
        {
        Replacer (Mass, 0, 1);
        }

    //GJM_printf (Mass, Size);

    for (int SortSize = 2; SortSize < Size; SortSize++)
        {
        //GJM_printf (Mass, Size);

        int RetVal = BinaryFinder (Mass, SortSize, Mass [SortSize]);

        $c

        //printf (" SortSize = > %d <\n", SortSize);

        $d

        $m

        //printf (" RetVal = > %d <\n", RetVal);

        $d

        ReplacerDF (Mass, Size, SortSize, RetVal);

        //GJM_printf (Mass, Size);

        //printf ("---------------------------------------------\n");
        }

    //printf ("<<Compare = %d>> <<Change = %d>>\n", Compare, Change);
    //printf ("<<Compare = %d>> <<Change = %d>>\n", Compare, Change);
    }

