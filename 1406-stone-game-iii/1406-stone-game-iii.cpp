class Solution {
    const string Alice = "Alice";
    const string Bob = "Bob";
    const string Draw = "Tie";
    
    vector<int> Memo;
    int N = 0;
public:
    string stoneGameIII(vector<int>& stoneValue)
    {
        N = static_cast<int>(stoneValue.size());
        
        Memo.resize(3);
        
        for(int i = N - 1; i >= 0; i--)
        {
            int TakeOne = GetTakeStone(stoneValue, i, i);
            
            int TakeTwo = GetTakeStone(stoneValue, i, i + 1);

            int TakeThree = GetTakeStone(stoneValue, i, i + 2);
            
            Memo[i % 3] = max({TakeOne, TakeTwo, TakeThree});
        }
        
        int Value = Memo[0];
        if(Value > 0)
        {
            return Alice;
        }
        else if(Value < 0)
        {
            return Bob;
        }
        return Draw;
    }
    
private:
    int GetTakeStone(vector<int>& StoneValue, int Index, int Range)
    {
        if(Range >= N)
        {
            return INT_MIN;
        }
        
        int TakeStone = 0;
        for(int i = Index; i <= Range; i++)
        {
            TakeStone += StoneValue[i];
        }
        
        TakeStone -= Memo[(Range + 1) % 3];
        return TakeStone;
    }
};