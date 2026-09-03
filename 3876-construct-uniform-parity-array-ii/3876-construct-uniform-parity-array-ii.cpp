class Solution {
    vector<int> Odds;
public:
    bool uniformArray(vector<int>& nums1)
    {
        for(int& Num : nums1)
        {
            if(Num & 1)
            {
                Odds.push_back(Num);
            }
        }

        ranges::sort(Odds);

        return AllOdd(nums1) || AllEven(nums1);
    }
private:
    bool AllOdd(vector<int>& Nums1)
    {
        const int N = Nums1.size();

        for(int i = 0; i < N; i++)
        {
            if((Nums1[i] & 1) == 0 && !IsExistOdd(Nums1[i]))
            {
                return false;
            }
        }
        return true;
    }

    bool AllEven(vector<int>& Nums1)
    {
        const int N = Nums1.size();

        for(int i = 0; i < N; i++)
        {
            if((Nums1[i] & 1) == 1 && !IsExistOdd(Nums1[i]))
            {
                return false;
            }
        }
        return true;
    }

    bool IsExistOdd(const int Num)
    {
        for(int& Odd : Odds)
        {
            if(Num > Odd)
            {
                return true;
            }
            else
            {
                break;
            }
        }
        return false;
    }
};