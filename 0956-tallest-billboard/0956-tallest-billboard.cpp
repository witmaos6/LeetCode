class Solution {
    vector<int> Memo;
    int Sum = 0;
public:
    int tallestBillboard(vector<int>& rods)
    {
        for(int& Rod : rods)
        {
            Sum += Rod;
        }
        
        Memo.resize(Sum + 1, -1);
        Memo[0] = 0;
        
        for(int& Rod : rods)
        {
            DP(Memo, Rod);
        }
        
        return Memo[0];
    }
    
private:
    void DP(vector<int> Temp, int Rod)
    {
        for(int i = 0; i <= Sum - Rod; i++)
        {
            if(Temp[i] < 0)
                continue;
            
            Memo[i + Rod] = max(Memo[i + Rod], Temp[i]);
            
            Memo[abs(i - Rod)] = max(Memo[abs(i - Rod)], Temp[i] + min(i, Rod));
        }
    }
};