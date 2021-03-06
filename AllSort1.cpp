
#include "TXLib.h"

class CooSystem
    {
    public:

    double x0, y0;
    double x1, y1;

    double Xmin, Ymin;
    double Xmax, Ymax;

    double ReCounterX (double x);

    double ReCounterY (double y);

    void Pixelating (double x, double y, COLORREF Color);
    };

class Button
    {
    public:

    int x, y;
    int width, height;
    const char* text;
    int id;

    COLORREF Color1, Color2;

    HDC Image;

    void Load ();
    void Draw () const;
    int Checker () const;
    };

      //Button B = {400, 400, 230, 90, "B.bmp"}

int Compare = 0;
int Change  = 0;

void Randomizer (int Mass [], int Size);

void Control (int Mass [], int Size, int Left, int Right, int Middle, const char* Name);

void Checker (int Mass [], int Size);

void GJM_printf (int Mass [], int Size);

void Replacer (int Mass [], int Slot1, int Slot2);

int  MinPos (int Mass [], int Size);

void RunSort (const Button* Button);

const Button* BttnsChkr (const Button Buttons []);

#include "DFSort.h"

#include "BubbleSort.h"

#include "Sort.h"

#include "QSort.h"

int main2 ()
    {
    txCreateWindow (1000, 1000);

    CooSystem Coord = {100, 100, 900, 500, -10, 0, 10, 100};

    txSetFillColor (TX_NULL);

    txRectangle (100, 100, 900, 500);

    for (double x = -10; x < 10; x+= 0.1)
        {
        txCircle (Coord.ReCounterX (x  ),
                  Coord.ReCounterY (x*x), 1);
        }
    }

int main()
    {
    txCreateWindow (1000, 1000);

    /*HDC BinInsert = txLoadImage ("BinaryInsert.bmp");
    if (BinInsert == NULL) txMessageBox ("???? ?? ?????");
    HDC BubSort   = txLoadImage ("BubbleSort.bmp");
    HDC SelSort   = txLoadImage ("SelectSort.bmp");
    HDC QSort     = txLoadImage ("QuickSort.bmp");*/

    const int Empty = 0;
    const int BinaryInsert = 1;
    const int BubbleSort = 2;
    const int SelectSort = 3;
    const int QuickSort = 4;

    //enum {}

    Button Buttons [] = {Button { 50, 860, 130, 90, "BinaryInsert.bmp", BinaryInsert, TX_LIGHTCYAN, TX_LIGHTBLUE},
                         Button {275, 860, 130, 90,   "BubbleSort.bmp", BubbleSort,    TX_LIGHTRED,   TX_MAGENTA},
                         Button {600, 860, 130, 90,   "SelectSort.bmp", SelectSort,  TX_LIGHTGREEN,     TX_GREEN},
                         Button {820, 860, 130, 90,    "QuickSort.bmp", QuickSort,       TX_YELLOW,     TX_WHITE},
                         Button                                                                { -1,  -1, Empty}};

    for (int Count = 0; Buttons [Count].x != -1 && Buttons [Count].y != -1; Count++)
        {
        Buttons [Count].Load ();
        }

    for (int Count = 0; Buttons [Count].x != -1 && Buttons [Count].y != -1; Count++)
        {
        Buttons [Count].Draw ();
        }

    while (1 < 2)
        {

    //const int Size = 10;

    /*while (1 < 2)
        {

        txBitBlt (txDC(),  50, 860, 0, 0, BinInsert);

        txBitBlt (txDC(), 275, 860, 0, 0,   BubSort);

        txBitBlt (txDC(), 600, 860, 0, 0,   SelSort);

        txBitBlt (txDC(), 820, 860, 0, 0,     QSort);

        //txRectangle (50, 860, 180, 950);

        //txRectangle (275, 860, 405, 950);

        //txRectangle (600, 860, 730, 950);

        //txRectangle (820, 860, 950, 950);

        if (txMouseButtons () == 1 && 50 < txMouseX () && txMouseX () < 180 && 860 < txMouseY () && txMouseY () < 950)
            {
            DedNEDead ();
            }
        }*/

         const Button* Check = BttnsChkr (Buttons);

         if (Check != NULL)
            {
            RunSort (Check);
            }

         }

    return 0;
    }

void CooSystem::Pixelating (double x, double y, COLORREF Color)
     {
     txSetColor (Color);

     txSetFillColor (Color);

     txCircle (ReCounterX (x),
               ReCounterY (y), 2);
     }

void Randomizer (int Mass [], int Size)
    {
    for (; Size >= 0; Size--)
        {
        Mass [Size] = rand ()%10 * 10 + Size;
        }
    }

void Control    (int Mass [], int Size,
                 int Left,    int Right,
                 int Middle,  const char* Name)
    {
    printf ("\n");

    for (int Count = 0; Count < Size; Count ++)
        {
        $G

        if (Count == Left) $C;

        if (Count == Middle) $Y;

        if (Count == Right) $R;

        if (Count == Left && Count == Right) $M;

        printf ("%03d ", Count);
        }

    $d

    printf ("   %s\n", Name);

    for (int Count = 0; Count < Size; Count ++)
        {
        $g

        if (Count == Left) $c;

        if (Count == Middle) $y;

        if (Count == Right) $r;

        if (Count == Left && Count == Right) $m;

        printf ("%03d ", Mass [Count]);
        }

    printf ("\n");

    $d

    }

/*void Checker    (int Mass [], int Size)
    {
    for (int Count = 0; Count < Size - 1; Count ++)
        {
        if (Mass [Count] > Mass [Count + 1])
            {
            $m printf ("?? ?????? ?????? \n");

            return;
            }
        }

    $g printf ("?? ????????????????? \n");

    }*/

void GJM_printf (int Mass [], int Size)
    {
    for (int Count = 0; Count < Size; Count++)
        {
        $g printf ("[%d] = ", Count);

        $y printf ("%02d ", Mass [Count]); $d
        }
    printf ("\n");
    }

void Replacer (int Mass [], int Slot1, int Slot2)
    {

    Change = Change + 1;

    int Temp1 = Mass [Slot1];

    int Temp2 = Mass [Slot2];

    Mass [Slot1] = Temp2;

    Mass [Slot2] = Temp1;
    }

int MinPos      (int Mass [], int Size)
    {

    int Min = Mass [0];

    int Slot = 0;

    for (int Count = 0; Count < Size; Count ++)
        {
        Compare++;

        if (Min > Mass [Count])
            {

            Min = Mass [Count];

            Slot = Count;

            }
        }
    return Slot;
    }

void RunSort (const Button* Button)
    {
    printf ("%d\n", Button->id);

    CooSystem Coord = {50, 100, 950, 800, 10, 0, 100, 3000};

    int Mass [100] = {};

    for (int Size = 10; Size < 100; Size++)
        {
        Compare = 0;
        Change  = 0;

        Randomizer (Mass, Size);
        //GJM_printf (Mass, Size);
        //Checker    (Mass, Size);
        if (Button->id == 1)
            {
            DFSort     (Mass, Size);
            Coord.Pixelating (Size, Compare, TX_LIGHTCYAN);
            Coord.Pixelating (Size, Change,  TX_LIGHTBLUE);
            }
        //Control    (Mass, Size, Left, Right, Middle, "");

        Compare = 0;
        Change  = 0;

        Randomizer (Mass, Size);
        //GJM_printf (Mass, Size);
        //Checker    (Mass, Size);
        if (Button->id == 2)
            {
            BubbleSort (Mass, Size);
            Coord.Pixelating (Size, Compare, TX_LIGHTRED);
            Coord.Pixelating (Size, Change,  TX_MAGENTA);
            }

        Compare = 0;
        Change  = 0;

        Randomizer (Mass, Size);
        if (Button->id == 3)
            {
            Sort       (Mass, Size);
            Coord.Pixelating (Size, Compare, TX_LIGHTGREEN);
            Coord.Pixelating (Size, Change,  TX_GREEN);
            }
        //MinPos     (Mass, Size);

        Compare = 0;
        Change  = 0;

        Randomizer (Mass, Size);
        if (Button->id == 4)
            {
            Division   (Mass, Size, 0, Size-1);
            Coord.Pixelating (Size, Compare, TX_YELLOW);
            Coord.Pixelating (Size, Change,  TX_WHITE);
            }
        }
    }

double CooSystem::ReCounterX (double x)
    {
    return (x0 - x1) / (Xmin - Xmax) * (x - Xmin) + x0;
    }

double CooSystem::ReCounterY (double y)
    {
    return (y0 - y1) / (Ymin - Ymax) * (-y + (Ymax - Ymin) - Ymin) + y0;
    }

void Button::Load ()
    {
    Image = txLoadImage (text);
    if (Image == NULL) txMessageBox ("ImageNotFound");
    }

void Button::Draw () const
    {
    txBitBlt (txDC(), x, y, 0, 0, Image);
    }

int Button::Checker () const
    {
    if (txMouseButtons () == 1 && x < txMouseX () && txMouseX () < x + width && y < txMouseY () && txMouseY () < y + height) return id;

    else return 0;
    }

const Button* BttnsChkr (const Button Buttons [])
    {
    const Button* Check = NULL;

    for (int Count = 0; Buttons [Count].x != -1 && Buttons [Count].y != -1; Count++)
        {

        if (Buttons [Count].Checker () > 0)
            {
            Check = &Buttons [Count];

            break;
            }

        Sleep (10);
        }

    return Check;
    }

    /*int Sum = 0;

    for (int i = 0; i < strlen (str); i++)
        {
        Sum = Sum + str [i];
        }*/



