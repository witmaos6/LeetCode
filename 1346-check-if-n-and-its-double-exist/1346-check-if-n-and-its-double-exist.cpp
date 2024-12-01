class Solution {
public:
    bool checkIfExist(vector<int>& arr)
    {
        unordered_set<int> Table;
        for(int& Num : arr)
        {
            int Multiple = Num * 2;
            if(Table.find(Multiple) != Table.end())
            {
                return true;
            }
            
            if((Num & 1) == 0)
            {
                int Divide = Num / 2;
                if(Table.find(Divide) != Table.end())
                {
                    return true;
                }
            }
            Table.insert(Num);
        }
        
        return false;
    }
};