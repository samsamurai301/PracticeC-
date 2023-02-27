#include <iostream>

using namespace std;

void selec();

void selec()
{
    cout<<"-----Welcome to shopping list management-----"<<endl;
    cout<<"[1] New Item"<<endl;
    cout<<"[2] Show Items"<<endl;
    cout<<"[3] Sort Items"<<endl;
    cout<<"[0] Exit"<<endl<<endl;
    cout<<"Select an appropriate option => "<<endl;
}

int main()
{
    int s,i=0;
    string N_Items[10];
    float P_Items[10];
    do{
        system("cls");
        selec();
        cin>>s;
        switch(s){
            case 1: {
                system("cls");
                cout<<"Enter Name of the item: ";
                cin>>N_Items[i];
                cout<<"Enter Price of the item: ";
                cin>>P_Items[i];
                i++;
                break;
            }
            case 2:{
                system("cls");
                for(int j=0; j<=i-1; j++){
                    cout<<"["<<j+1<<"] "<<N_Items[j]<<"  ==> "<<P_Items[j]<<"$"<<endl;
                }
                system("pause");
                break;
            }
            case 3: {
                system("cls");
                string temp_N[10];
                float temp_P[10];
                for (int n=0; n<=i-1;n++){
                    temp_N[n]=N_Items[n];
                    temp_P[n]=P_Items[n];
                }
                for(int j=0;j<=i-1;j++){
                    for(int k=0; k<=i-j; k++){
                        if(temp_P[j]>temp_P[j+1])
                        {
                            string temp1=temp_N[j];
                            float temp2=temp_P[j];
                            temp_N[j]=temp_N[j+1];
                            temp_N[j+1]=temp1;
                            temp_P[j]=temp_P[j+1];
                            temp_P[j+1]=temp2;
                        }
                    }
                }
                for(int j=0; j<=i-1; j++){
                    cout<<"["<<j+1<<"] "<<temp_N[j]<<"  ==> "<<temp_P[j]<<"$"<<endl;
                }
                system("pause");
                break;
            }
            case 0: {
                system("exit");
            }
            default:{
                cerr<<"Enter a valid response!!!";
            }
        }
    }while(s!=0);
}

