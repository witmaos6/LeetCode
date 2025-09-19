class Spreadsheet {
    unordered_map<string, int> Sheet;
public:
    Spreadsheet(int rows)
    {
    }
    
    void setCell(string cell, int value)
    {
        Sheet[cell] = value;
    }
    
    void resetCell(string cell)
    {
        Sheet.erase(cell);
    }
    
    int getValue(string formula)
    {
        int Index = formula.find('+');
        string Prev = formula.substr(1, Index - 1);
        string Post = formula.substr(Index + 1);

        int PrevValue = isalpha(Prev[0]) ? (Sheet.count(Prev) ? Sheet[Prev] : 0) : stoi(Prev);
        int PostValue = isalpha(Post[0]) ? (Sheet.count(Post) ? Sheet[Post] : 0) : stoi(Post);

        return PrevValue + PostValue;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */