class Solution {
public:
    int maxSelectedElements(vector<int>& nums)
    {
        ranges::sort(nums);

        int Best = 1;
        int Keep = 1;
        int Bump = 1;
        int Last = -10;

        for(int& Num : nums)
        {
            switch(Num - Last)
            {
                case 0:
                    Bump = Keep + 1;
                    break;
                case 1:
                    ++Keep;
                    ++Bump;
                    break;
                case 2:
                    Keep = Bump + 1;
                    Bump = 1;
                    break;
                default:
                    Keep = Bump = 1;
            }
            Best = max({Best, Keep, Bump});
            Last = Num;
        }
        return Best;
    }
};