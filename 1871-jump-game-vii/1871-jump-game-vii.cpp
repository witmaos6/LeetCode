class Solution {
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int N = static_cast<int>(s.size());

        if(s.back() & 1)
            return false;
        
        s[0] = 'v';
        int Reach = 0;
        int MaxR = maxJump;

        for(int i = minJump; i < N; i++)
        {
            if(i > MaxR)
                return false;
            
            Reach += (s[i - minJump] == 'v');
            Reach -= ((i > maxJump) && s[i - maxJump - 1] == 'v');

            if(Reach && (~s[i] & 1))
            {
                s[i] = 'v';
                MaxR = i + maxJump;
            }
        }
        
        return Reach;
    }
};