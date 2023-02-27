#include <iostream>
#include <cstdlib>

using namespace std;

void welc_msg();
void main_menu();

class vehicle                                   //Vehicle super class main
{
private:
    string vehicleNr;                           //Vehicle Number plate
    int regYr;                                  //Vehicle Registration Year
    int genInspYr;                              //Vehicle General Inspection Year
public:
    void vehicleData(string typ);               //All public member functions
    string getVehicleNr();
    int getRegYr();
    int getGenInspYr();
    bool getInspStatus();
};

void vehicle::vehicleData(string typ)
{
    cout<<"Enter "<<typ<<" Registration Number : ";
    cin>>vehicleNr;
    cout<<"Enter "<<typ<<" Registration Year : ";
    cin>>regYr;
    cout<<"Enter "<<typ<<" General Inspection Year : ";
    cin>>genInspYr;
}

string vehicle::getVehicleNr(){return vehicleNr;}
int vehicle::getRegYr(){return regYr;}
int vehicle::getGenInspYr(){return genInspYr;}

bool vehicle::getInspStatus()
{
    if(2022-genInspYr>3)
    {
        return true;
    }
    else{
        return false;
    }
}

class car : public vehicle                      //Vehicle sub class car
{
private:
    int horsePower;                             //Horse Power of Car
    int emiClass;                               //Emission Class of Car
public:                                         //All Public class member function
    void entrData();
    void dispData();
    int getHorsePower();
    int getEmiClass();
    float getTaxLiability();
};

void car::entrData()
{
    vehicleData("Car");
    cout<<"Enter Car Horse Power : ";
    cin>>horsePower;
    cout<<"Enter Car Emission Class [0- Low, 1- Normal, 2- Diesel] : ";
    do{
        cin>>emiClass;
    }while(emiClass!=0 && emiClass!=1 && emiClass!=2);
}

void car::dispData()
{
    cout<<"\tRegistration Number - "<<getVehicleNr();
    cout<<", Registration Year - "<<getRegYr();
    cout<<", General Inspection Year - "<<getGenInspYr()<<endl;
    cout<<"\tHorse power - "<<horsePower;
    cout<<", Emission class - "<<emiClass;
    cout<<", Tax Liability - "<<getTaxLiability();
    if(getInspStatus() == true)
    {
        cout<<", Inspection status - Due"<<endl;
    }
    else
    {
        cout<<", Inspection status - Ok"<<endl;
    }
}

int car::getHorsePower(){return horsePower;}
int car::getEmiClass(){return emiClass;}

float car::getTaxLiability()
{
    return (((float)horsePower + 99) / 100 * 10 *((float)emiClass + 1));
}

class bike : public vehicle                     //Vehicle sub class motorbike
{
private:
    int horsePower;                             //Horse Power of motorbike
    int maxSpeed;                               //Maximum speed of motorbike
public:                                         //All public member function
    void entrData();
    void dispData();
    int getHorsePower();
    int getMaxSpeed();
    float getTaxLiability();
};

void bike::entrData()
{
    vehicleData("Motorbike");
    cout<<"Enter Motorbike Horse Power : ";
    cin>>horsePower;
    cout<<"Enter Motorbike Maximum Speed : ";
    cin>>maxSpeed;
}

void bike::dispData()
{
    cout<<"\tRegistration Number - "<<getVehicleNr();
    cout<<", Registration Year - "<<getRegYr();
    cout<<", General Inspection Year - "<<getGenInspYr()<<endl;
    cout<<"\tHorse power - "<<horsePower;
    cout<<", Maximum Speed - "<<maxSpeed;
    cout<<", Tax Liability - "<<getTaxLiability();
    if(getInspStatus() == true)
    {
        cout<<", Inspection status - Due"<<endl;
    }
    else
    {
        cout<<", Inspection status - Ok"<<endl;
    }
}

int bike::getHorsePower(){return horsePower;}
int bike::getMaxSpeed(){return maxSpeed;}

float bike::getTaxLiability()
{
    return (((float)horsePower + 59)/100 * 20 * (((float)maxSpeed)/150));
}

class truck : public vehicle                    //Vehicle sub class truck
{
private:
    int nrOfAxle;                               //Number of Axle of truck
    int payLoad;                                //Payload of truck in ton
public:                                         //All public member functions
    void entrData();
    void dispData();
    int getNrOfAxle();
    int getPayLoad();
    float getTaxLiability();
};

void truck::entrData()
{
    vehicleData("Truck");
    cout<<"Enter Number of Axles Truck : ";
    cin>>nrOfAxle;
    cout<<"Enter Payload (in ton) of Truck : ";
    cin>>payLoad;
}

void truck::dispData()
{
    cout<<"\tRegistration Number - "<<getVehicleNr();
    cout<<", Registration Year - "<<getRegYr();
    cout<<", General Inspection Year - "<<getGenInspYr()<<endl;
    cout<<"\tNumber of Axles - "<<nrOfAxle;
    cout<<", Payload - "<<payLoad;
    cout<<", Tax Liability - "<<getTaxLiability();
    if(getInspStatus() == true)
    {
        cout<<", Inspection status - Due"<<endl;
    }
    else
    {
        cout<<", Inspection status - Ok"<<endl;
    }
}

int truck::getNrOfAxle(){return nrOfAxle;}
int truck::getPayLoad(){return payLoad;}

float truck::getTaxLiability()
{
    return (payLoad*50);
}                                                                //End of classes definitions

void welc_msg()
{
    cout<<"Welcome to the Federal Motor sport authority"<<endl;
    cout<<"This the management console application for vehicles"<<endl<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"----------------------------------------------------"<<endl<<endl;
}

void main_menu()
{
    cout<<"[1] Create the Vehicle"<<endl;
    cout<<"[2] Search Vehicle from Registration Number"<<endl;
    cout<<"[3] List of All Vehicles"<<endl;
    cout<<"[4] List of All Vehicles (Due Inspection)"<<endl;
    cout<<"[0] Exit Application"<<endl<<endl;

    cout<<"Select a option from above --> ";

}

void vehicle_menu()
{
    cout<<"[1] Car"<<endl;
    cout<<"[2] Motorbike"<<endl;
    cout<<"[3] Truck"<<endl<<endl;

    cout<<"Select a vehicle type from above --> ";
}

int main()
{
    int selct_option=1, num_vehicle, num_cars=0, num_bikes=0, num_trucks=0;
    car Cars[100];
    bike Bikes[100];
    truck Trucks[100];
    welc_msg();
    system("pause");
    while(selct_option!=0)
    {
        system("cls");
        main_menu();
        cin>>selct_option;
        num_vehicle = num_cars + num_bikes + num_trucks;
        switch(selct_option)
        {
        case 1:
            {
                system("cls");
                int selc_Vehicle;
                vehicle_menu();
                cin>>selc_Vehicle;
                system("cls");
                if(num_vehicle<=100)
                {
                    switch(selc_Vehicle)
                    {
                    case 1:
                        {
                            Cars[num_cars].entrData();
                            cout<<"Car Number "<<num_cars + 1<<" is added sucessfully."<<endl;
                            num_cars++;
                            break;
                        }
                    case 2:
                        {
                            Bikes[num_bikes].entrData();
                            cout<<"Motorbike number "<<num_bikes + 1<<"is added sucessfully."<<endl;
                            num_bikes++;
                            break;
                        }
                    case 3:
                        {
                            Trucks[num_trucks].entrData();
                            cout<<"Truck number "<<num_trucks + 1<<" is added sucessfully."<<endl;
                            num_trucks++;
                            break;
                        }
                    default:
                        {
                            cout<<"You have selected a wrong option!! Try again!!"<<endl;
                            break;
                        }
                    }
                    system("pause");
                }
                else{
                    cout<<"You reached Maximum limit of the Entry!!";
                }
                break;
            }
        case 2:
            {
                system("cls");
                int selc_Vehicle;
                vehicle_menu();
                cin>>selc_Vehicle;
                system("cls");
                switch(selc_Vehicle)
                {
                case 1:
                    {
                        string getVehicalNumber;
                        cout<<"Enter a Car Registration Number --> ";
                        cin>>getVehicalNumber;
                        for(int i=0; i<=num_cars; i++)
                        {
                            if(Cars[i].getVehicleNr()==getVehicalNumber)
                            {
                                Cars[i].dispData();
                            }
                        }
                        break;
                    }
                case 2:
                    {
                        string getVehicalNumber;
                        cout<<"Enter a Bike Registration Number --> ";
                        cin>>getVehicalNumber;
                        for(int i=0; i<=num_bikes; i++)
                        {
                            if(Bikes[i].getVehicleNr()==getVehicalNumber)
                            {
                                Bikes[i].dispData();
                            }
                        }
                        break;
                    }
                case 3:
                    {
                        string getVehicalNumber;
                        cout<<"Enter a Truck Registration Number --> ";
                        cin>>getVehicalNumber;
                        for(int i=0; i<=num_trucks; i++)
                        {
                            if(Trucks[i].getVehicleNr()==getVehicalNumber)
                            {
                                Trucks[i].dispData();
                            }
                        }
                        break;
                    }
                default:
                    {
                        cout<<"You have selected a wrong option!! Try again!!"<<endl;
                        break;
                    }
                }
                system("pause");
                break;
            }
        case 3:
            {
                system("cls");
                cout<<"All Cars : -> "<<endl<<endl;
                for(int i=1; i<=num_cars; i++)
                {
                    cout<<"["<<i<<"] ";
                    Cars[i-1].dispData();
                }
                cout<<endl<<"------------------------------------------------"<<endl;
                cout<<"------------------------------------------------"<<endl;

                cout<<"All Motorbikes : -> "<<endl<<endl;
                for(int j=1; j<=num_bikes; j++)
                {
                    cout<<"["<<j<<"] ";
                    Bikes[j-1].dispData();
                }
                cout<<endl<<"------------------------------------------------"<<endl;
                cout<<"------------------------------------------------"<<endl;

                cout<<"All Trucks : -> "<<endl<<endl;
                for(int k=1; k<=num_trucks; k++)
                {
                    cout<<"["<<k<<"] ";
                    Trucks[k-1].dispData();
                }
                cout<<endl<<"------------------------------------------------"<<endl;
                cout<<"------------------------------------------------"<<endl;
                system("pause");
                break;
            }
        case 4:
            {
                system("cls");
                int t=1;
                cout<<"All Cars with due inspections!! : -> "<<endl<<endl;
                for(int i=1; i<=num_cars; i++)
                {
                    if(Cars[i-1].getInspStatus()==true)
                    {
                        cout<<"["<<t<<"] ";
                        Cars[i-1].dispData();
                        t++;
                    }

                }
                cout<<endl<<"------------------------------------------------"<<endl;
                cout<<"------------------------------------------------"<<endl;

                int s=1;
                cout<<"All Motorbikes with due inspections!! : -> "<<endl<<endl;
                for(int j=1; j<=num_bikes; j++)
                {
                    if(Bikes[j-1].getInspStatus()==true)
                    {
                        cout<<"["<<s<<"] ";
                        Bikes[j-1].dispData();
                        j++;
                    }
                }
                cout<<endl<<"------------------------------------------------"<<endl;
                cout<<"------------------------------------------------"<<endl;

                cout<<"All Trucks with due inspections!! : -> "<<endl<<endl;
                int p=1;
                for(int k=1; k<=num_trucks; k++)
                {
                    if(Trucks[k-1].getInspStatus()==true)
                    {
                        cout<<"["<<p<<"] ";
                        Trucks[k-1].dispData();
                        p++;
                    }
                }
                cout<<endl<<"------------------------------------------------"<<endl;
                cout<<"------------------------------------------------"<<endl;
                system("pause");
                break;
            }
        case 0:
            {
                selct_option=0;
                system("exit");
                break;
            }
        default:
            {
                cout<<"Select an appropriate option!!";
                system("pause");
                break;
            }
        }
    }


}
