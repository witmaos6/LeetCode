class Solution {
public:
    long long minimumSteps(string s)
    {
        const int N = static_cast<int>(s.size());
        
        int Left = 0;
        int Right = N - 1;
        long long Count = 0;
        
        while(Left < Right)
        {
            if(s[Left] == '0')
            {
                Left++;
            }
            else if(s[Right] == '1')
            {
                Right--;
            }
            else
            {
                Count += (Right - Left);
                Left++;
                Right--;
            }
        }
        
        return Count;
    }
};