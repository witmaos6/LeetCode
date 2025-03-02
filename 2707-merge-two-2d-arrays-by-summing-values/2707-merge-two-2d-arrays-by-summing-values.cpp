class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2)
    {
        const int Nums1Size = static_cast<int>(nums1.size());
        const int Nums2Size = static_cast<int>(nums2.size());

        vector<vector<int>> Result;
        int i = 0;
        int j = 0;
        while(i < Nums1Size || j < Nums2Size)
        {
            if(i < Nums1Size && j < Nums2Size)
            {
                if(nums1[i][0] == nums2[j][0])
                {
                    Result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                    i++;
                    j++;
                }
                else if(nums1[i][0] < nums2[j][0])
                {
                    Result.push_back(nums1[i]);
                    i++;
                }
                else
                {
                    Result.push_back(nums2[j]);
                    j++;
                }
            }
            else if(i < Nums1Size)
            {
                Result.push_back(nums1[i]);
                i++;
            }
            else if(j < Nums2Size)
            {
                Result.push_back(nums2[j]);
                j++;
            }
        }

        return Result;
    }
};