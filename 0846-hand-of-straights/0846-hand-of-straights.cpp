class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
        const int N = static_cast<int>(hand.size());
        
        if(N % groupSize != 0)
            return false;
        
        sort(hand.begin(), hand.end());
        
        for(int i = 0; i < N; i++)
        {
            if(hand[i] >= 0)
            {
                if(FindSuccess(hand, groupSize, i, N) == false)
                    return false;
            }
        }
        
        return true;
    }
    
private:
    bool FindSuccess(vector<int>& Hand, int GroupSize, int i, int N)
    {
        int Next = Hand[i] + 1;
        Hand[i] = -1;
        int Count = 1;
        i++;
        
        while(i < N && Count < GroupSize)
        {
            if(Hand[i] == Next)
            {
                Next = Hand[i] + 1;
                Hand[i] = -1;
                Count++;
            }
            i++;
        }
        
        return (Count == GroupSize);
    }
};