class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        queue<int> LeftSide;
        queue<int> RightSide;
        int NrOfPivot = 0;

        for(int& Num : nums)
        {
            if(Num < pivot)
            {
                LeftSide.push(Num);
            }
            else if(Num > pivot)
            {
                RightSide.push(Num);
            }
            else
            {
                NrOfPivot++;
            }
        }

        int i = 0;
        while(!LeftSide.empty())
        {
            nums[i] = LeftSide.front();
            LeftSide.pop();
            i++;
        }
        for(int j = 0; j < NrOfPivot; j++)
        {
            nums[i] = pivot;
            i++;
        }
        while(!RightSide.empty())
        {
            nums[i] = RightSide.front();
            RightSide.pop();
            i++;
        }
        return nums;
    }
};