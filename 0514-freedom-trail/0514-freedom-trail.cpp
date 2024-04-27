class Solution {
    int N;
    unordered_map<char, vector<int>> Table;
    vector<vector<int>> Memo;
public:
    int findRotateSteps(string ring, string key)
    {
        N = static_cast<int>(ring.size());
        for(int i = 0; i < N; i++)
        {
            Table[ring[i]].push_back(i);
        }
        
        Memo.resize(key.size(), vector<int>(N, - 1));
        return DP(key, 0, 0);
    }    
private:
    int DP(const string& Key, const int Index, const int Pos)
    {
        if(Index == Key.size())
        {
            return 0;
        }
        if(Memo[Index][Pos] != -1)
        {
            return Memo[Index][Pos];
        }
        
        int Steps = INT_MAX;
        int KeyValue = Key[Index];
        
        for(int i = 0; i < Table[KeyValue].size(); i++)
        {
            int NextPos = Table[KeyValue][i];
            int Taken = DP(Key, Index + 1, NextPos);
            
            int ClockwiseValue = 1 + Clockwise(Pos, NextPos) + Taken;
            Steps = min(Steps, ClockwiseValue);
            
            int AntiClockwiseValue = 1 + AntiClockwise(Pos, NextPos) + Taken;
            Steps = min(Steps, AntiClockwiseValue);
        }
        
        Memo[Index][Pos] = Steps;
        return Memo[Index][Pos];
    }
    
    int Clockwise(const int Curr, const int NextPos)
    {
        if(NextPos >= Curr)
        {
            return NextPos - Curr;
        }
        return N - (Curr - NextPos);
    }
    
    int AntiClockwise(const int Curr, const int NextPos)
    {
        if(Curr >= NextPos)
        {
            return Curr - NextPos;
        }
        return N - (NextPos - Curr);
    }
};