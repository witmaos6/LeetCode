class Solution {
public:
    bool judgeCircle(string moves)
    {
        int Right = 0;
        int Up = 0;
        for(char& C : moves)
        {
            if(C == 'R')
            {
                Right++;
            }
            else if(C == 'L')
            {
                Right--;
            }
            else if(C == 'U')
            {
                Up++;
            }
            else if(C == 'D')
            {
                Up--;
            }
        }
        return (Right == 0 && Up == 0);
    }
};