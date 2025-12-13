class Solution {
    unordered_map<string, int> BusinessLineSortOrder = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive)
    {
        const int N = static_cast<int>(code.size());

        vector<pair<pair<int, string>, string>> SortableCoupons;
        for(int i = 0; i < N; i++)
        {
            if(code[i].empty())
                continue;
            
            if(!isActive[i])
                continue;

            if(!ValidCode(code[i]))
                continue;

            if(!ValidBusiness(businessLine[i]))
                continue;

            int SortIndex = BusinessLineSortOrder[businessLine[i]];

            SortableCoupons.push_back({{SortIndex, code[i]}, code[i]});
        }
        sort(SortableCoupons.begin(), SortableCoupons.end());

        vector<string> Result;
        for(auto& Entry : SortableCoupons)
        {
            Result.push_back(Entry.second);
        }

        return Result;
    }

private:
    bool ValidCode(string& Code)
    {
        for(char& C : Code)
        {
            if(!(C >= '0' && C <= '9') && !(C >= 'a' && C <= 'z') && !(C >= 'A' && C <= 'Z') && !(C == '_'))
                return false;
        }
        return true;
    }

    bool ValidBusiness(string& Business)
    {
        return (BusinessLineSortOrder.count(Business) == 1) ? true : false;
    }
};