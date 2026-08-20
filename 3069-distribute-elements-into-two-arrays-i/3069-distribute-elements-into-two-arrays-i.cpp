class Solution {
public:
    vector<int> resultArray(vector<int>& nums)
    {
        vector<int> Arr1;
        vector<int> Arr2;

        Arr1.push_back(nums[0]);
        Arr2.push_back(nums[1]);

        const int N = nums.size();
        for(int i = 2; i < N; i++)
        {
            if(Arr1.back() > Arr2.back())
            {
                Arr1.push_back(nums[i]);
            }
            else
            {
                Arr2.push_back(nums[i]);
            }
        }

        Arr1.reserve(N);
        for(int& Num : Arr2)
        {
            Arr1.push_back(Num);
        }
        return Arr1;
    }
};