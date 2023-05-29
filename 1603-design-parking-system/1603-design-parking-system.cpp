class ParkingSystem {
    int BigParkSize = 0;
    int BigIndex = 0;
    int MediumParkSize = 0;
    int MediumIndex = 0;
    int SmallParkSize = 0;
    int SmallIndex = 0;
public:
    ParkingSystem(int big, int medium, int small)
    {
        BigParkSize = big;
        MediumParkSize = medium;
        SmallParkSize = small;
    }
    
    bool addCar(int carType)
    {
        switch(carType)
        {
            case 1:
                return bPossibleParking(BigParkSize, BigIndex);
            case 2:
                return bPossibleParking(MediumParkSize, MediumIndex);
            case 3:
                return bPossibleParking(SmallParkSize, SmallIndex);
            default :
                break;
        }
        return false;
    }
    
private:
    bool bPossibleParking(int ParkSize, int& ParkIndex)
    {
        if(ParkIndex < ParkSize)
        {
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