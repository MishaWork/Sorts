
#include "TXLib.h"

void DrawGraph (double (*Function) (double x), COLORREF Color);

double Parabola (double x);

int main()
    {
    txCreateWindow (800, 600);

    DrawGraph (sin, TX_GREEN);

    DrawGraph (tan, TX_PINK);

    DrawGraph (cos, TX_YELLOW);

    DrawGraph ([] (double x) { return x*x*x; }, TX_CYAN);

    DrawGraph (Parabola , TX_ORANGE);

    return 0;
    }

void DrawGraph (double (*Function) (double x), COLORREF Color)
    {
    double x = -10;

    while (x <= 10)
        {

        double y = Function (x);

        txSetColor (Color);

        txCircle (50 * x + 400, 50 * -y + 300, 1);

        x += 0.01;
        }
    }

double Parabola (double x)
    {
    return x*x;
    }
