class Solution {
public:
    bool winnerOfGame(string colors)
    {
        int N = static_cast<int>(colors.size());
        int AliceCount = 0;
        int BobCount = 0;
        int Count = 0;

        for(int i = 1; i < N; i++)
        {
            if(colors[i] == colors[i - 1])
            {
                Count++;
            }
            else
            {
                if(colors[i - 1] == 'A')
                {
                    AliceCount += max(0, Count - 1);
                }
                else
                {
                    BobCount += max(0, Count - 1);
                }
                Count = 0;
            }
        }
        
        if(colors.back() == 'A')
        {
            AliceCount += max(0, Count - 1);
        }
        else
        {
            BobCount += max(0, Count - 1);
        }
        
        return AliceCount > BobCount;
    }
};