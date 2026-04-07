class Robot {
    using Point = pair<int, int>;
    Point P = {0, 0};
    string Dir = "East";
    int Width = 0;
    int Height = 0;
    int Per = 0;
public:
    Robot(int width, int height)
    {
        P = {0, 0};
        Dir = "East";
        Width = width;
        Height = height;
        Per = 2 * (Width + Height) - 4;
    }
    
    void step(int num)
    {
        if(Per == 0)
            return;

        num %= Per;
        if(num == 0 && (P.first != 0 || P.second != 0))
            return;
        if(num == 0 && P.first == 0 && P.second == 0)
        {
            Dir = "South";
            return;
        }

        while(num > 0)
        {
            if(Dir == "East")
            {
                int Move = min(num, Width - 1 - P.first);
                P.first += Move;
                num -= Move;
                if(num > 0)
                    Dir = "North";
            }
            else if(Dir == "North")
            {
                int Move = min(num, Height - 1 - P.second);
                P.second += Move;
                num -= Move;
                if(num > 0)
                    Dir = "West";
            }
            else if(Dir == "West")
            {
                int Move = min(num, P.first);
                P.first -= Move;
                num -= Move;
                if(num > 0)
                    Dir = "South";
            }
            else if(Dir == "South")
            {
                int Move = min(num, P.second);
                P.second -= Move;
                num -= Move;
                if(num > 0)
                    Dir = "East";
            }
        }
    }
    
    vector<int> getPos()
    {
        return {P.first, P.second};
    }
    
    string getDir()
    {
        return Dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */