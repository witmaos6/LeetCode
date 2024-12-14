class Solution {
public:
    long long continuousSubarrays(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        long long Total = 0;
        multiset<int> SortArr;
        
        int Left = 0;
        for(int Right = 0; Right < N; Right++)
        {
            while(!SortArr.empty())
            {
                auto Max = SortArr.rbegin();
                auto Min = SortArr.begin();
                
                if(abs(*Max - nums[Right]) <= 2 && abs(*Min - nums[Right]) <= 2)
                {
                    break;
                }
                
                auto Erase = SortArr.find(nums[Left]);
                SortArr.erase(Erase);
                Left++;
            }
            
            SortArr.insert(nums[Right]);
            Total += Right - Left + 1;
        }
        
        return Total;
    }
};