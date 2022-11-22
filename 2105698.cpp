#include <iostream>
using namespace std;

class Car
{
    protected:
    int mileage;
    int seats;
    public:
    virtual void Maintenance() = 0;
    void show()
    {
        cout << "Mileage is " << mileage;
        cout << "Seats  is " << seats;
    }
};

class Sports : public Car
{
    bool servicing;
    int cost;
    public:
    Sports()
    {
        mileage = 15;
    }
    Sports(int m, int s)
    {
        mileage = m;
        seats = s;
        servicing = true;
        cost = 0;
    }
    Sports(Sports &ob1)
    {
        mileage = ob1.mileage;
        seats = ob1.seats;
        servicing = ob1.servicing;
        cost = ob1.cost;
    }
    ~Sports()
    {
        static int c;
        c++;
        cout << "\nThe destructor was called " << c << " times";
    }
    void operator==(Sports &b)
    {
        if(mileage == b.mileage)
            cout << "They have the same mileage";
        else 
            cout << "Their mileages are varying";
    }
    void Maintenance()
    {
        if(servicing == true)
            cost+=1000;
        cout << "\nThe total cost is: " << cost;

    }
    friend void resetCost(Sports &s);
};

void resetCost(Sports &s)
{
    s.cost = 0;
    cout << "All due charges removed";
}

template<class T>
class MaxSpeed : public Sports
{
    T topspeed;
    public:
    void ShowTop(T &x)
    {
        topspeed = x;
        cout << "The top speed is: " << topspeed;
    }
    void ShowTop(int y)
    {
        topspeed = y;
        try
        {
            if(topspeed == 0);
            throw 0;
            cout << "\nThe topspeed is: " << topspeed;
        }
        catch(int z)
        {
            cout << "\nThe car cannot run as topspeed is 0";
        }
    }
};

int main()
{
    int mil, seat;
    cout << "Enter the mileage: ";
    cin >> mil;
    cout << "Enter the seats: ";
    cin >> seat;
    Sports x(mil,seat);
    Sports a;
    x == a;
    x.Maintenance();
    char ch;
    cout << "\nDo you want to pay the outstanding dues? ";
    cin >> ch;
    if(ch == 'y' || ch == 'Y')
    {
        resetCost(x);
    }
    MaxSpeed<float> y;
    float max;
    cout << "\nEnter the top speed of the car: ";
    cin >> max;
    y.ShowTop(max);
    y.ShowTop(0);
}
