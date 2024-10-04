class Solution {
public:
    long long dividePlayers(vector<int>& skill)
    {
        const int N = static_cast<int>(skill.size());
        int TotalSum = accumulate(skill.begin(), skill.end(), 0);
        int TeamSkill = TotalSum / (N / 2);
        
        unordered_map<int, int> Table;
        for(int Num : skill)
        {
            Table[Num]++;
        }
        
        long long Result = 0;
        for(auto&[Num, Freq] : Table)
        {
            if(Freq <= 0)
            {
                continue;
            }
            
            int TargetNum = TeamSkill - Num;
            while(Freq > 0)
            {
                if(Table.find(TargetNum) != Table.end())
                {
                    if(Table[TargetNum] > 0)
                    {
                        Table[TargetNum]--;
                        Result += (Num * TargetNum);
                    }
                    else
                    {
                        return -1;
                    }
                }
                else
                {
                    return -1;
                }
                Freq--;
            }
        }
        
        return Result;
    }
};