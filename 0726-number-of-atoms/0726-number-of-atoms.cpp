class Solution {
public:
    string countOfAtoms(string formula)
    {
        stack<unordered_map<string, int>> St;
        St.push({});
        
        const int N = static_cast<int>(formula.size());
        int i = 0;
        
        while (i < N)
        {
            if (formula[i] == '(')
            {
                St.push({});
                i++;
            }
            else if(formula[i] == ')')
            {
                unordered_map<string, int> Table = St.top();
                St.pop();
                i++;
                int Begin = i;
                
                while (i < N && isdigit(formula[i]))
                {
                    i++;
                }
                int Multiple = Begin < i ? stoi(formula.substr(Begin, i - Begin)) : 1;
                
                for (auto& [Atom, Num] : Table)
                {
                    St.top()[Atom] += Num * Multiple;
                }
            }
            else
            {
                int Begin = i++;
                while (i < N && islower(formula[i]))
                {
                    i++;
                }
                string Element = formula.substr(Begin, i - Begin);
                Begin = i;
                while (i < N && isdigit(formula[i]))
                {
                    i++;
                }
                int Count = Begin < i ? stoi(formula.substr(Begin, i - Begin)) : 1;
                St.top()[Element] += Count;
            }
        }
        
        unordered_map<string, int> ResultTable = St.top();
        vector<string> Elements;
        for (auto& [Atom, Num] : ResultTable)
        {
            Elements.push_back(Atom);
        }
        sort(Elements.begin(), Elements.end());
        
        string Result;
        for (const string& Element : Elements)
        {
            Result += Element;
            if (ResultTable[Element] > 1)
            {
                Result += to_string(ResultTable[Element]);
            }
        }
        
        return Result;
    }
};