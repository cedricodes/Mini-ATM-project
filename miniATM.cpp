// ----------------- Mini ATM project based on oops concepts -----------------

#include <iostream>
#include<conio.h>
#include<string>
using namespace std;

class ATM{
    
    long int account_number;
    string name;
    int PIN;
    double balance;
    string mobile_number;
    
    public:
    // Constructor
    ATM(long int account_number, string name,int PIN, double balance, string mobile_number){
        this->account_number = account_number;
        this->name = name;
        this->PIN = PIN;
        this->balance = balance;
        this->mobile_number = mobile_number;
    }
    // getter functions
    
    long int getAccount_number(){
        return account_number;
    }
    
    string getName(){
        return name;
    }
    
    int getPIN(){
        return PIN;
    }
    
    double getBalance(){
        return balance;
    }
    
    string getMobile_number(){
        return mobile_number;
    }
    
    // setter functions
    
    void setMobile_number(string mob_prev, string mob_new){
        if(mob_prev == mobile_number){
            mobile_number = mob_new;
            cout<<endl<<"Mobile Number updated successfully !";
            _getch(); //---- used for pausing the console screen until user presses a key/button
        }
        else{
            cout<<endl<<"Incorrect old mobile number !"<<endl;
            _getch();
        }
    }
    
    void cashWithdraw(int amount){
        if(amount > 0 && amount < balance){
            balance -= amount;
            cout<<"Please collect your cash"<<endl;
            cout<<"Available balance : "<<balance<<endl;
            _getch();
        }else if(amount < 0 || amount > balance){
            cout<<"Invalid Input !"<<endl;
            _getch();
        }else{
            cout<<"Insufficient Balance !"<<endl;
            _getch();
        }
    }
};

int main() {
    int choice;
    int enterPIN;
    long int enterAccount_number;
    
    system("cls");
    
    ATM user1(1234567, "Cedric", 1111, 41000, "9087654321");
    
    do{
        system("cls");
        cout<<endl<<"---- Welcome to ATM ----"<<endl;
        
        cout<<endl<<"Enter Account Number : ";
        cin>>enterAccount_number;
        
        cout<<endl<<"Enter PIN : ";
        cin>>enterPIN;
        
        if(enterAccount_number == user1.getAccount_number() && enterPIN == user1.getPIN()){
            do{
                int amount = 0;
                string oldMob, newMob;
                
                system("cls");
                
                //user interface
                cout<<endl<<"---- Welcome to ATM ----"<<endl;
                cout<<"Select options - "<<endl;
                cout<<"1. Check Balance"<<endl;
                cout<<"2. Withdraw Cash"<<endl;
                cout<<"3. Show User Details"<<endl;
                cout<<"4. Update Mobile Number"<<endl;
                cout<<"5. Exit"<<endl;
                
                cin>>choice;
                
                switch(choice){
                    case 1:
                        cout<<"Your Bank Balance is : "<<user1.getBalance()<<endl;
                        _getch();
                        break;
                    case 2:
                        cout<<"Enter the amount : "<<endl;
                        cin>>amount;
                        user1.cashWithdraw(amount);
                        break;
                    case 3:
                        cout<<"---- User details are : "<<endl;
                        cout<<"--- Account Number : "<<user1.getAccount_number()<<endl;
                        cout<<"--- Name : "<<user1.getName()<<endl;
                        cout<<"--- Balance : "<<user1.getBalance()<<endl;
                        cout<<"--- Mobile number : "<<user1.getMobile_number()<<endl;
                        _getch();
                        break;
                    case 4:
                        cout<<"Enter old mobile number : "<<endl;
                        cin>>oldMob;
                        cout<<"Enter new mobile number : "<<endl;
                        cin>>newMob;
                        user1.setMobile_number(oldMob, newMob);
                        break;
                    case 5:
                        exit(0);
                    default :
                        cout<<"Enter valid data !!"<<endl;
                    
                }
                
            }while(1);
        }
        
    }while(1);
    

    return 0;
}