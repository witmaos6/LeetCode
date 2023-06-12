class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> Ranges;
        const int N = static_cast<int>(nums.size());
        
        for(int Begin = 0; Begin < N; Begin++)
        {
            int End = Begin;
            
            while(End + 1 < N && nums[End + 1] == nums[End] + 1)
            {
                End++;
            }
            
            string Input = to_string(nums[Begin]);
            if(Begin < End)
            {
                Input += ("->" + to_string(nums[End]));
            }
            
            Ranges.push_back(Input);
            
            Begin = End;
        }
        
        return Ranges;
    }
};