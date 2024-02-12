class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        
        unordered_map<int, int> Table;
        int MajorElement = 0;
        for(int Num : nums)
        {
            Table[Num]++;
            if(Table[Num] > (N / 2))
            {
                MajorElement = Num;
                break;
            }
        }
        return MajorElement;
    }
};