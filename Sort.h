void Sort (int Numb [], int Size)
    {

    int Changer = 0;

    while (Changer < Size-1)
        {

        int Minimum = MinPos (Numb, Size - Changer);
        Replacer (Numb, Minimum, Size - Changer - 1);

        Changer ++;
        }
    }
