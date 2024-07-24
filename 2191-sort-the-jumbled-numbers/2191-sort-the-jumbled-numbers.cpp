class Solution {
    using Jumble = pair<int, int>;
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        vector<Jumble> SortedJumble(N);
        
        for(int i = 0; i < N; i++)
        {
            int Value = nums[i];
            int MappedValue = (Value == 0) ? mapping[0] : 0;
            int Decimal = 1;
            
            while(Value > 0)
            {
                int Digit = Value % 10;
                MappedValue += (mapping[Digit] * Decimal);
                Value /= 10;
                Decimal *= 10;
            }
            
            SortedJumble[i] = {MappedValue, i};
        }
        
        sort(SortedJumble.begin(), SortedJumble.end());
        
        vector<int> Result(N);
        for(int i = 0; i < N; i++)
        {
            int Index = SortedJumble[i].second;
            Result[i] = nums[Index];
        }
        
        return Result;
    }
};