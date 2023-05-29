class ParkingSystem {
    vector<int> BigPark;
    int BigIndex = 0;
    vector<int> MediumPark;
    int MediumIndex = 0;
    vector<int> SmallPark;
    int SmallIndex = 0;
public:
    ParkingSystem(int big, int medium, int small)
    {
        BigPark.resize(big);
        MediumPark.resize(medium);
        SmallPark.resize(small);
    }
    
    bool addCar(int carType)
    {
        switch(carType)
        {
            case 1:
                return bPossibleParking(BigPark, BigIndex);
            case 2:
                return bPossibleParking(MediumPark, MediumIndex);
            case 3:
                return bPossibleParking(SmallPark, SmallIndex);
            default :
                break;
        }
        return false;
    }
    
private:
    bool bPossibleParking(vector<int>& Park, int& ParkIndex)
    {
        if(ParkIndex < Park.size())
        {
            Park[ParkIndex] = 1;
            ParkIndex++;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */