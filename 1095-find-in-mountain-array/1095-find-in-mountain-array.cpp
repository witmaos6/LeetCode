/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int N = 0;
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        N = mountainArr.length();
        int MaxIndex = FindMaxIndex(mountainArr);
        
        int LeftIndex = FindLeftSide(target, mountainArr, 0, MaxIndex);
        int RightIndex = FindRightSide(target, mountainArr, MaxIndex, N - 1);
        
        if(LeftIndex == -1 && RightIndex == -1)
        {
            return -1;
        }
        else if(LeftIndex == -1 || RightIndex == -1)
        {
            return max(LeftIndex, RightIndex);
        }
        return min(LeftIndex, RightIndex);
    }
    
private:
    int FindMaxIndex(MountainArray& mountainArr)
    {
        int Left = 0, Right = N - 1;
        while(Left < Right)
        {
            int Middle = (Left + Right) / 2;
            int MiddleNum = mountainArr.get(Middle);
            int RightNum = mountainArr.get(Middle + 1);
            
            if(MiddleNum < RightNum)
            {
                Left = Middle + 1;
            }
            else
            {
                Right = Middle;
            }
        }
        
        return Left;
    }
    
    int FindLeftSide(int Target, MountainArray& mountainArr, int Left, int Right)
    {
        while(Left <= Right)
        {
            int Middle = (Right + Left) / 2;
            int Num = mountainArr.get(Middle);
            
            if(Num == Target)
            {
                return Middle;
            }
            else if(Num < Target)
            {
                Left = Middle + 1;
            }
            else
            {
                Right = Middle - 1;
            }
        }
        
        return -1;
    }
    
    int FindRightSide(int Target, MountainArray& mountainArr, int Left, int Right)
    {
        while(Left <= Right)
        {
            int Middle = (Right + Left) / 2;
            int Num = mountainArr.get(Middle);
            
            if(Num == Target)
            {
                return Middle;
            }
            else if(Num > Target)
            {
                Left = Middle + 1;
            }
            else
            {
                Right = Middle - 1;
            }
        }
        
        return -1;
    }
};