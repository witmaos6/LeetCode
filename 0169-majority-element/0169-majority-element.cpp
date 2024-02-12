class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        int Element = 0;
        int Count = 0;
        
        for(int i = 0; i < N; i++)
        {
            if(Count == 0)
            {
                Element = nums[i];
                Count = 1;
            }
            else if(Element == nums[i])
            {
                Count++;
            }
            else
            {
                Count--;
            }
        }
        return Element;
    }
};