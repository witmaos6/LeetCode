class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> Next;
        stack<int> St;

        int M = nums2.size();

        for(int i = M - 1; i >= 0; i--)
        {
            while(!St.empty() && St.top() <= nums2[i])
            {
                St.pop();
            }

            Next[nums2[i]] = St.empty() ? -1 : St.top();
            St.push(nums2[i]);
        }

        vector<int> Result;
        Result.reserve(nums1.size());
        for(int& Num : nums1)
        {
            Result.push_back(Next[Num]);
        }
        return Result;
    }
};