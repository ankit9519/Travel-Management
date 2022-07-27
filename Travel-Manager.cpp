#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;
void menu();
class ManageMenu{
	protected:
		string userName;
	public:
		ManageMenu(){
			cout<<"\n\n\n\\n\n\n\n\tEnter Your Name to Continue as an Admin:";
			cin>>userName;
			system("CLS");
			menu();
		}
		~ManageMenu(){}
			
};
class Customers
{
public:
    string name, gender, address;
    int age, mobileNo;
    static int cusID;
    char all[999];

    void getDetails()
    {
        ofstream out("old-customers.txt", ios::app);
        {
            cout << "Enter Customer ID: ";
            cin >> cusID;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Mobile Number: ";
            cin >> mobileNo;
            cout << "Enter Address: ";
            cin >> address;
            cout << "Enter Gender: ";
            cin >> gender;
        }
        out << "\n Customer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();
        cout << "\nSaved \nNOTE: We save your details for future purposes\n"
             << endl;
    }

    void showDetails()
    {
        ifstream in("old-cutomers.txt");
        {
            if(!in)
            {
                cout<<"File Error!"<<endl;
            }
            while(!(in.eof()))
            {
                in.getline(all,999);
                cout<<all<<endl;
            }
            in.close();
        }
    }
};

int Customers::cusID;

class Cabs
{
    public:
        int cabChoice;
        int kilometers;
        float cabCost;
        static float lastCabcost;

        void cabDetails()
        {
            cout<<"We collaborated with fastest,safest, and smartest cab service around the country"<<endl;
            cout<<"----------ABC CABS----------\n"<<endl;
            cout<<"1. Rent a Standard Cab -Rs.15 for 1KM"<<endl;
            cout<<"2. Rent a Luxury Cab -Rs.25 for 1KM"<<endl;

            cout<<"\nTo calculate the cost for your journey:"<<endl;
            cout<<"Enter which kind of cab you need: ";
            cin>>cabChoice;
            cout<<"Enter Kilometers you have to travel:";
            cin>>kilometers;

            int hireCab;
            if(cabChoice ==1)
            {
                cabCost =kilometers*15;
                cout<<"\nYour tour cost"<<cabCost<<"Rupees for Standard Cab"<<endl;
                cout<<"Press 1 to hire this cab: or";
                cout<<"Press 2 to select another cab: ";
                cin>>hireCab;

                system("CLS");
                if(hireCab ==1){
                    lastCabcost=cabCost;
                    cout<<"\nYou have successfully hired a Standard Cab"<<endl;
                    cout<<"\nGoto Menu and take the receipt"<<endl;
                }
                else if(hireCab ==2)
                {
                    cabDetails();
                }
                else
                {
                    cout<<"\n Invalid Input! Redirecting to previous menu \nPlease Wait!"<<endl;
                    Sleep(999);
                    system("CLS ");
                    cabDetails(); 
                }
            }
            else if(cabChoice ==2)
            {
                cabCost=kilometers*25;
                cout<<"\nYour tour cost"<<cabCost<<"Rupees for Luxury Cab"<<endl;
                cout<<"Press 1 to hire this cab: or";
                cout<<"Press 2 to select another cab: ";
                cin>>hireCab;

                system("CLS");
                if(hireCab ==1){
                    lastCabcost=cabCost;
                    cout<<"\nYou have successfully hired a Luxury Cab"<<endl;
                    cout<<"\nGoto Menu and take the receipt"<<endl;
                }
                else if(hireCab ==2)
                {
                    cabDetails();
                }
                else{
                    cout<<"\n Invalid Input! Redirecting to previous menu \nPlease Wait!"<<endl;
                    Sleep(1100);
                    system("CLS ");
                    cabDetails(); 
                }
            }
            else{
                cout<<"\n Invalid Input! Redirecting to Main menu \nPlease Wait!"<<endl;
                    Sleep(1100);
                    system("CLS ");
                    menu();
            }
            cout<<"\nPress 1 to Redirect to Main Menu";
            cin>>hireCab;
            system("CLS");
            if(hireCab ==1)
            {
                menu();
            }
            else{
                menu();
            }
        }
};

float Cabs::lastCabcost;

class Booking
{
    public:
        int choiceHotel;
        int packChoice;
        static float hotelCost;

        void hotels()
        {
            string hotelNo[]={"Five Star","Ashiyana","Kashyap"};
            for(int a=0;a<3;a++)
            {
                cout<<(a+1)<<". Hotel"<<hotelNo[a]<<endl;
            }

            cout<<"\nCurrently we collaborated with above hotels!"<<endl;
            cout<<"Press any key to go back or \nEnter the number of the Hotel you want to book:"<<endl;
            cin>>choiceHotel;

            system("CLS");

            if(choiceHotel ==1){
                cout<<"------Welcome to Hotel Five Star------\n"<<endl;
                cout<<"Packages offered by Five Star:\n"<<endl;
                cout<<"1. Standard Pack"<<endl;
                cout<<"\tAll basic facilities you need just for: Rs.5000.00"<<endl;
                cout<<"2. Premium Pack"<<endl;
                cout<<"\tEnjoy Premium: Rs.10000.00"<<endl;
                cout<<"3. Luxury Pack"<<endl;
                cout<<"\tLive in luxury at Five Star at Rs.15000.00"<<endl;

                cout<<"\nPress another key to go back or \nSelect the package number you want to book:";
                cin>>packChoice;

                if(packChoice ==1){
                    hotelCost=5000.00;
                    cout<<"\nYou have successfully booked Standard Pack at Five Star"<<endl;
                    cout<<"Goto menu and take the receipt"<<endl;
                }
                else if(packChoice ==2){
                    hotelCost=10000.00;
                    cout<<"\nYou have successfully booked Premium Pack at Five Star"<<endl;
                    cout<<"Goto menu and take the receipt"<<endl;
                }
                else if(packChoice ==3){
                    hotelCost=15000.00;
                    cout<<"\nYou have successfully booked Luxury Pack at Five Star"<<endl;
                    cout<<"Goto menu and take the receipt"<<endl;
                }
                else{
                    cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait....."<<endl;
                    Sleep(1100);
                    system("CLS");
                    hotels();
                }   
                int gotoMenu;
                cout<<"\nPress 1 to redirect to main menu";
                cin>>gotoMenu;
                if(gotoMenu ==1){
                    menu();
                }          
                else{
                    menu();
                }   
            }

            else if(choiceHotel ==2){
                cout<<"------Welcome to Ashiyana------\n"<<endl;
                cout<<"Packages offered by Ashiyana:\n"<<endl;
                cout<<"1. Standard Pack"<<endl;
                cout<<"\tAll basic facilities you need just for: Rs.8000.00"<<endl;
                cout<<"2. Premium Pack"<<endl;
                cout<<"\tEnjoy Premium: Rs.15000.00"<<endl;
                cout<<"3. Luxury Pack"<<endl;
                cout<<"\tLive in luxury at Five Star at Rs.20000.00"<<endl;

                cout<<"\nPress another key to go back or \nSelect the package number you want to book:";
                cin>>packChoice;

                if(packChoice ==1){
                    hotelCost=8000.00;
                    cout<<"\nYou have successfully booked Standard Pack at Five Star"<<endl;
                    cout<<"Goto menu and take the receipt"<<endl;
                }
                else if(packChoice ==2){
                    hotelCost=17600.00;
                    cout<<"\nYou have successfully booked Premium Pack at Five Star"<<endl;
                    cout<<"Goto menu and take the receipt"<<endl;
                }
                else if(packChoice ==3){
                    hotelCost=24000.00;
                    cout<<"\nYou have successfully booked Luxury Pack at Five Star"<<endl;
                    cout<<"Goto menu and take the receipt"<<endl;
                }
                else{
                    cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait....."<<endl;
                    Sleep(1100);
                    system("CLS");
                    hotels();
                }   
                int gotoMenu;
                cout<<"\nPress 1 to redirect to main menu";
                cin>>gotoMenu;
                if(gotoMenu ==1){
                    menu();
                }          
                else{
                    menu();
                }   
            }

            else if(choiceHotel ==3){
                cout<<"------Welcome to Hotel Kashyap------\n"<<endl;
                cout<<"Packages offered by Hotel Kashyap:\n"<<endl;
                cout<<"1. Standard Pack"<<endl;
                cout<<"\tAll basic facilities you need just for: Rs.10000.00"<<endl;
                cout<<"2. Premium Pack"<<endl;
                cout<<"\tEnjoy Premium: Rs.20000.00"<<endl;
                cout<<"3. Luxury Pack"<<endl;
                cout<<"\tLive in luxury at Five Star at Rs.30000.00"<<endl;

                cout<<"\nPress another key to go back or \nSelect the package number you want to book:";
                cin>>packChoice;

                if(packChoice ==1){
                    hotelCost=10000.00;
                    cout<<"\nYou have successfully booked Standard Pack at Five Star"<<endl;
                    cout<<"Goto menu and take the receipt"<<endl;
                }
                else if(packChoice ==2){
                    hotelCost=20000.00;
                    cout<<"\nYou have successfully booked Premium Pack at Five Star"<<endl;
                    cout<<"Goto menu and take the receipt"<<endl;
                }
                else if(packChoice ==3){
                    hotelCost=30000.00;
                    cout<<"\nYou have successfully booked Luxury Pack at Five Star"<<endl;
                    cout<<"Goto menu and take the receipt"<<endl;
                }
                else{
                    cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait....."<<endl;
                    Sleep(1100);
                    system("CLS");
                    hotels();
                }   
                int gotoMenu;
                cout<<"\nPress 1 to redirect to main menu";
                cin>>gotoMenu;
                if(gotoMenu ==1){
                    menu();
                }          
                else{
                    menu();
                }   
            }
            else{
                cout<<"Invalid Input! Redirecting to Previous Menu \nPlease Wait....."<<endl;
                    Sleep(1100);
                    system("CLS");
                    menu();
            }
        }
};

float Booking::hotelCost; 

class Charges: public Booking,Cabs,Customers
{
public:
        void printBill()
        {
            ofstream outf("receipt.txt");
            {
                outf<<"--------ABC Travel Agency---------"<<endl;
                outf<<"-------------Receipt--------------"<<endl;
                outf<<"__________________________________"<<endl;

                outf<<"Customer ID: "<<Customers::cusID<<endl<<endl;
                outf<<"Description\t\t Total"<<endl;
                outf<<"Hotel Cost:\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost<<endl;
                outf<<"Travel (cab) cost:\t"<<fixed<<setprecision(2)<<Cabs::lastCabcost<<endl;

                outf<<"__________________________________"<<endl;
                outf<<"Total Charge:\t\t"<<fixed<<setprecision(2)<<Booking::hotelCost+Cabs::lastCabcost<<endl;
                outf<<"__________________________________"<<endl;
                outf<<"-------------THANK YOU------------"<<endl; 
            }
        outf.close();
        }
    
        void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if(!inf)
            {
                cout<<"File does not exists!!"<<endl;
            }
            while(!(inf.eof()))
            {
                inf.getline(all,999);
                cout<<all<<endl;
            }
        }
        inf.close();
    }
};

void menu()
{
    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout<<"\t\t       *ABC Travels*\n"<<endl;
    cout<<"-------------------Main Menu-------------------"<<endl;

    cout<<"\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
    cout<<"\t|\t\t\t\t\t"<<endl;
    cout<<"\t|\tCustomer Management ->1\t"<<endl;
    cout<<"\t|\tCabs Management     ->2\t"<<endl;
    cout<<"\t|\tBookings Management ->3\t"<<endl;
    cout<<"\t|\tCharges and Bills   ->4\t"<<endl;
    cout<<"\t|\tExit                ->5\t"<<endl;
    cout<<"\t|\t\t\t\t\t"<<endl;
    cout<<"\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;

    cout<<"\nEnter Your Choice: ";
    cin>>mainChoice;
    system("CLS");
    Customers a2;
    Cabs a3;
    Booking a4;
    Charges a5;

    if(mainChoice ==1)
    {
        cout<<"-----Customers-----\n"<<endl;
        cout<<"1. Enter new Customer"<<endl;
        cout<<"2. See Old Customers"<<endl;

        cout<<"\nEnter Choice: ";
        cin>>inChoice;
        system("CLS");
        if(inChoice ==1)
        {
            a2.getDetails();
        }
        else if(inChoice ==2)
        {
            a2.showDetails();
        }
        else{
            cout<< "Invalid Input! Redirectiong to Previous Menu \nPlease Wait!" <<endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout<<"\nPress 1 to Redirect to main menu!";
        cin>>gotoMenu;
        system("CLS");
        if(gotoMenu==1){
            menu();
        }
        else
            menu();
    }
    else if(mainChoice==2){
        a3.cabDetails();
    }
    else if(mainChoice==3){
        cout<<"--> Book a luxury Hotel using the system <--"<<endl;
        a4.hotels();
    }
    else if(mainChoice==4){
        cout<<"-->Get your receipt <--"<<endl;
        a5.printBill();

        cout<<"Your Receipt is already in the file path\n"<<endl;
        cout<<"To display your receipt in your screen, Enter 1: or Enter another key to go back to main menu";

        cin>>gotoMenu;
        if(gotoMenu==1){
            system("CLS");
            a5.showBill();
            cout<<"\n Press 1 to redirect to main menu";
            cin>>gotoMenu;
            system("CLS");
            if(gotoMenu==1){
                menu();
            }
            else 
                menu();
        }
        else{
        system("CLS");
        menu();
        }
    }
    else if(mainChoice==5){
        cout<<"\n--Good Bye--";
        Sleep(999);
        system("CLS");
        menu();
    }
    else
       cout<< "Invalid Input! Redirectiong to Previous Menu \nPlease Wait!" <<endl;
            Sleep(1100);
            system("CLS");
            menu();    
}

int main(){
	ManageMenu startObj;
	return 0;
}

