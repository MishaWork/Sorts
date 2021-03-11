void Division (int Numb [], int Size, int Left, int Right)
    {
    int OldLeft = Left, OldRight = Right;

    int MiddlePos = (Right + Left) / 2;

    int Middle = Numb [MiddlePos];

    //$e printf ("\n<< Division (Numb, Size = %d, Left = %d, Right = %d): OldLeft = %d, OldRight = %d, MiddlePos = %d, Middle = %d \n", Size, Left, Right, OldLeft, OldRight, MiddlePos, Middle); $d

    //Control (Numb, Size, OldLeft, OldRight, Left, Right, (Right + Left) / 2, "Start");

    if (Left >= Right) {/*Control (Numb, Size, OldLeft, OldRight, Left, Right, (Right + Left) / 2, "Too small, return"); */ return;}

    if (Right - Left == 1)
        {
        if (Numb [Left] > Numb [Right])
            {
            Replacer (Numb, Left, Right);
            }

        //Control (Numb, Size, OldLeft, OldRight, Left, Right, (Right + Left) / 2, "Replaced 2 elements, return");

        return;
        };

    while (Left < Right)
        {
        while (Left < Right)
            {
            Compare = Compare + 1;

            if (Numb [Left] >= Middle) break;

            Left ++;
            }

        while (Right > Left)
            {
            Compare = Compare + 1;

            if (Numb [Right] <= Middle) break;

            Right --;
            }

        //Control (Numb, Size, OldLeft, OldRight, Left, Right, -1, "Found bad elements");

        Replacer (Numb, Left, Right);

        //Control (Numb, Size, OldLeft, OldRight, Left, Right, -1, "Replaced two elements");

        Left ++;
        Right --;
        }

    //Control (Numb, Size, OldLeft, OldRight, Left, Right, -1, "End");

    if (Left > Right)
        {
        int L = Left, R = Right;
        Right = L, Left = R;

        //Control (Numb, Size, OldLeft, OldRight, Left, Right, -1, "Left and Right corrected");
        }

    //getch ();

    Division (Numb, Size, OldLeft, Left);

    Division (Numb, Size, Right, OldRight);
    }
