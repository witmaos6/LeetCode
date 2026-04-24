class Solution {
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int Left = 0;
        int Right = 0;
        int Blank = 0;

        for(char& C : moves)
        {
            if(C == 'L')
            {
                Left++;
            }
            else if(C == 'R')
            {
                Right++;
            }
            else if(C == '_')
            {
                Blank++;
            }
        }
        return abs(Left - Right) + Blank;
    }
};