class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size() > nums2.size())
        {
            return GetMedianNumber(nums2, nums1);
        }
        return GetMedianNumber(nums1, nums2);
    }
    
private:
    double GetMedianNumber(vector<int>& Nums1, vector<int>& Nums2)
    {
        int Nums1Size = static_cast<int>(Nums1.size());
        int Nums2Size = static_cast<int>(Nums2.size());
        int PartitionYCache = (Nums1Size + Nums2Size + 1) / 2;
        
        int Left = 0, Right = Nums1Size;
        while(Left <= Right)
        {
            int PartitionX = (Right + Left) / 2;
            int PartitionY = PartitionYCache - PartitionX;
            
            int MinRightX = (PartitionX == Nums1Size) ? INT_MAX : Nums1[PartitionX];
            int MinRightY = (PartitionY == Nums2Size) ? INT_MAX : Nums2[PartitionY];
            
            int MaxLeftX = (PartitionX == 0) ? INT_MIN : Nums1[PartitionX - 1];
            int MaxLeftY = (PartitionY == 0) ? INT_MIN : Nums2[PartitionY - 1];
            
            if (MaxLeftX <= MinRightY && MaxLeftY <= MinRightX)
            {
                if ((Nums1Size + Nums2Size) % 2 == 0)
                {
                    return (double)(max(MaxLeftX, MaxLeftY) + min(MinRightX, MinRightY)) / 2;
                }
                else
                {
                    return (double)(max(MaxLeftX, MaxLeftY));
                }
            }
            else if (MaxLeftX > MinRightY)
            {
                Right = PartitionX - 1;
            }
            else
            {
                Left = PartitionX + 1;
            }
        }
        
        return -1.0;
    }
};