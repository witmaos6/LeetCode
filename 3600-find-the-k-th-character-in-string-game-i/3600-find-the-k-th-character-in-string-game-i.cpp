class Solution {
public:
    char kthCharacter(int k)
    {
        int Index = k - 1;
        int Add = 0;
        while(Index > 0)
        {
            int P = 1;
            while(P * 2 <= Index)
            {
                P *= 2;
            }
            Add++;
            Index -= P;
        }
        return 'a' + (Add % 26);
    }
};