class Solution {
    const string R = "Radiant";
    const string D = "Dire";
public:
    string predictPartyVictory(string senate)
    {
        queue<int> Rq;
        queue<int> Dq;
        int N = static_cast<int>(senate.size());
        
        for(int i = 0; i < N; i++)
        {
            if(senate[i] == 'R')
            {
                Rq.push(i);
            }
            else
            {
                Dq.push(i);
            }
        }
        
        while(!Rq.empty() && !Dq.empty())
        {
            int RIndex = Rq.front();
            Rq.pop();
            int DIndex = Dq.front();
            Dq.pop();
            
            if(RIndex < DIndex)
            {
                Rq.push(RIndex + N);
            }
            else
            {
                Dq.push(DIndex + N);
            }
        }
        
        if(!Rq.empty())
        {
            return R;
        }
        else
        {
            return D;
        }
    }
};