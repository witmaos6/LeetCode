class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());
        
        vector<vector<int>> Answer(2);
        size_t i = 0, j = 0;
        
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
            {
                Answer[0].push_back(nums1[i]);
                i++;
            }
            else
            {
                Answer[1].push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < nums1.size())
        {
            Answer[0].push_back(nums1[i]);
            i++;
        }
        
        while(j < nums2.size())
        {
            Answer[1].push_back(nums2[j]);
            j++;
        }
                
        return Answer;
    }
};