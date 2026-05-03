class Solution {
public:
    bool rotateString(string s, string goal)
    {
        if(s.size() != goal.size())
            return false;
        
        const int N = s.size();

        for(int i = 0; i < N; i++)
        {
            bool Flag = true;
            int Index = 0;
            int j = i;
            while(Index < N)
            {
                if(s[Index] != goal[j % N])
                {
                    Flag = false;
                    break;
                }
                Index++;
                j++;
            }

            if(Flag)
                return true;
        }
        return false;
    }
};