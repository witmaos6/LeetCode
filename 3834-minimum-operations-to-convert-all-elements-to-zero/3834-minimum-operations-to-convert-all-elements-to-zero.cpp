class Solution {
public:
    int minOperations(vector<int>& nums)
    {
        nums.push_back(0);
        stack<int> St;
        int Count = 0;
        const int N = static_cast<int>(nums.size());

        for(int i = 0; i < N; i++)
        {
            while(!St.empty())
            {
                if(nums[i] > St.top())
                {
                    St.push(nums[i]);
                    break;
                }
                else if(nums[i] < St.top())
                {
                    St.pop();
                    Count++;
                }
                else
                {
                    break;
                }
            }
            if(St.empty() && nums[i] != 0)
            {
                St.push(nums[i]);
            }
        }
        return Count;
    }
};