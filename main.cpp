#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
//all logic+file handling here..
//display all accounts data
void displayAllAccountsData()
{
    fstream accountFile,balanceFile,namesFile;
    accountFile.open("accountnum.txt",ios::in);
    namesFile.open("names.txt",ios::in);
    balanceFile.open("balance.txt",ios::in);
    if(accountFile.is_open()&&namesFile.is_open()&&balanceFile.is_open()){
        string account_number,name,balance;
        cout<<"-------------------------------\n";
        cout<<"ACCOUNT NO."<<setw(10)<<"NAME"<<setw(11)<<"BALANCE\n";
        cout<<"-------------------------------\n";
        while(getline(accountFile,account_number)){
            getline(namesFile,name);
            getline(balanceFile,balance);
            cout<<account_number<<setw(10)<<name<<setw(10)<<balance<<"\n";
        }
        cout<<"-------------------------------\n";
        accountFile.close();
        namesFile.close();
        balanceFile.close();
    }
}
//search bank by its name
void showByBankName(string b_name)
{
    int flag=0;
    fstream accountFile,balanceFile,namesFile;
    accountFile.open("accountnum.txt",ios::in);
    namesFile.open("names.txt",ios::in);
    balanceFile.open("balance.txt",ios::in);
    if(accountFile.is_open()&&namesFile.is_open()&&balanceFile.is_open()){
        string account_number,name,balance;
        cout<<"-------------------------------\n";
        cout<<"ACCOUNT NO."<<setw(10)<<"NAME"<<setw(11)<<"BALANCE\n";
        cout<<"-------------------------------\n";
        while(getline(accountFile,account_number)){
            getline(namesFile,name);
            getline(balanceFile,balance);
            string bank_n;
            bank_n=account_number.substr(0,3);
            if(b_name==bank_n){
                cout<<account_number<<setw(10)<<name<<setw(10)<<balance<<"\n";
                flag++;
            }
            else{
                continue;
            }
        }
        if (flag==0)
        {
            cout<<"no record found by this name..\n";
        }
        cout<<"-------------------------------\n";
        accountFile.close();
        namesFile.close();
        balanceFile.close();
    }
}
//search bank branch by its branch code
void showByBranchCode(string b_code)
{
    int flag2=0;
    fstream accountFile,balanceFile,namesFile;
    accountFile.open("accountnum.txt",ios::in);
    namesFile.open("names.txt",ios::in);
    balanceFile.open("balance.txt",ios::in);
    if(accountFile.is_open()&&namesFile.is_open()&&balanceFile.is_open()){
        string account_number,name,balance;
        cout<<"-------------------------------\n";
        cout<<"ACCOUNT NO."<<setw(10)<<"NAME"<<setw(11)<<"BALANCE\n";
        cout<<"-------------------------------\n";
        while(getline(accountFile,account_number)){
            getline(namesFile,name);
            getline(balanceFile,balance);
            string bank_c;
            bank_c=account_number.substr(3,2);
            if(b_code==bank_c){
                cout<<account_number<<setw(10)<<name<<setw(10)<<balance<<"\n";
                flag2++;
            }
            else{
                continue;
            }
        }
        if(flag2==0)
        {
            cout<<"no record found by this branch code\n";
        }
        cout<<"-------------------------------\n";
        accountFile.close();
        namesFile.close();
        balanceFile.close();
    }
}
//show accounts data with credit less than 1000
void showAccountWithLessAmount()
{
    int flag3=0;
    fstream accountFile,balanceFile,namesFile;
    accountFile.open("accountnum.txt",ios::in);
    namesFile.open("names.txt",ios::in);
    balanceFile.open("balance.txt",ios::in);
    if(accountFile.is_open()&&namesFile.is_open()&&balanceFile.is_open()){
        string account_number,name,balance;
        cout<<"-------------------------------\n";
        cout<<"ACCOUNT NO."<<setw(10)<<"NAME"<<setw(11)<<"BALANCE\n";
        cout<<"-------------------------------\n";
        while(getline(balanceFile,balance)){
            getline(accountFile,account_number);
            getline(namesFile,name);
            string bank_c;
            int bal;
            stringstream ss3;
            ss3<<balance;
            ss3>>bal;
            if(bal<1000){
                cout<<account_number<<setw(10)<<name<<setw(10)<<balance<<"\n";
                flag3++;
            }
            else{
                continue;
            }
        }
        if(flag3==0)
        {
            cout<<"no account found..\n";
        }
        cout<<"-------------------------------\n";
        accountFile.close();
        namesFile.close();
        balanceFile.close();
    }
}
//show accounts data with credit greater than 1 lac
void showAccountWithGreaterAmount()
{
    int flag4=0;
    fstream accountFile,balanceFile,namesFile;
    accountFile.open("accountnum.txt",ios::in);
    namesFile.open("names.txt",ios::in);
    balanceFile.open("balance.txt",ios::in);
    if(accountFile.is_open()&&namesFile.is_open()&&balanceFile.is_open()){
        string account_number,name,balance;
        cout<<"-------------------------------\n";
        cout<<"ACCOUNT NO."<<setw(10)<<"NAME"<<setw(11)<<"BALANCE\n";
        cout<<"-------------------------------\n";
        while(getline(balanceFile,balance)){
            getline(namesFile,name);
            getline(accountFile,account_number);
            string bank_c;
            int bal;
            stringstream ss4;
            ss4<<balance;
            ss4>>bal;
            if(bal>100000){
                cout<<account_number<<setw(10)<<name<<setw(10)<<balance<<"\n";
                flag4++;
            }
            else{
                continue;
            }
        }
        if(flag4==0)
        {
            cout<<"no record found..\n";
        }
        cout<<"-------------------------------\n";
        accountFile.close();
        namesFile.close();
        balanceFile.close();
    }
}
//register a new account
void addAccount(string acNo,string nm,string bal)
{
    int flag5=0;
    fstream accountFile,balanceFile,namesFile;
    accountFile.open("accountnum.txt",ios::in);
    namesFile.open("names.txt",ios::app);
    balanceFile.open("balance.txt",ios::app);
    string account_number;
    if(accountFile.is_open()&&namesFile.is_open()&&balanceFile.is_open()){
        while(getline(accountFile,account_number)){
            if(acNo==account_number)
            {
                flag5++;
            }
        }
        accountFile.close();
        if(flag5==0)
        {
            fstream accountFile2;
            accountFile2.open("accountnum.txt",ios::app);
            accountFile2<<"\n"<<acNo;
            namesFile<<"\n"<<nm;
            balanceFile<<"\n"<<bal;
            accountFile2.close();
            namesFile.close();
            balanceFile.close();
            cout<<"Account Added Successfully..\n";
        }
        else
        {
            cout<<"Account number already exist..\n";
        }
    }
}
//delete existing account
void deleteAccount(string ac_no)
{
    int flag6=0;
    fstream accountFile,balanceFile,namesFile,tempAccount,tempName,tempBalance;
    accountFile.open("accountnum.txt",ios::in);
    namesFile.open("names.txt",ios::in);
    balanceFile.open("balance.txt",ios::in);
    tempAccount.open("tempAcc.txt",ios::out);
    tempName.open("tempName.txt",ios::out);
    tempBalance.open("tempBalance.txt",ios::out);
    string account_number,name,balance;
    if(accountFile.is_open()&&namesFile.is_open()&&balanceFile.is_open()){
        while(getline(accountFile,account_number)){
            getline(namesFile,name);
            getline(balanceFile,balance);
            if(account_number!=ac_no){
                tempAccount<<account_number<<"\n";
                tempName<<name<<"\n";
                tempBalance<<balance<<"\n";
            }
            else{
                continue;
                flag6++;
            }
        }
        accountFile.close();
        namesFile.close();
        balanceFile.close();
        tempAccount.close();
        tempName.close();
        tempBalance.close();
        remove("accountnum.txt");
        remove("names.txt");
        remove("balance.txt");
        rename("tempAcc.txt","accountnum.txt");
        rename("tempName.txt","names.txt");
        rename("tempBalance.txt","balance.txt");
        if(flag6!=0)
        {
            cout<<"Account Deleted Successfully..\n";
        }
        else
        {
            cout<<"Account not exist\n";
        }
    }
}
//show anyone's account detail by putting account number
void balanceInquiry(string ac_NO)
{
    int flag7=0;
    fstream accountFile,balanceFile,namesFile;
    accountFile.open("accountnum.txt",ios::in);
    namesFile.open("names.txt",ios::in);
    balanceFile.open("balance.txt",ios::in);
    if(accountFile.is_open()&&namesFile.is_open()&&balanceFile.is_open()){
        string account_number,name,balance;
        cout<<"-------------------------------\n";
        cout<<"[    <<YOUR ACCOUNT INFO>>    ]\n";
        cout<<"-------------------------------\n";
        while(getline(accountFile,account_number)){
            getline(namesFile,name);
            getline(balanceFile,balance);
            if(account_number==ac_NO){
                cout<<"ACCOUNT NO. :"<<account_number<<"\n";
                cout<<"NAME        :"<<name<<"\n";
                cout<<"BALANCE     :"<<balance<<"\n";
                flag7++;
            }
            else{
                continue;
            }
        }
        cout<<"-------------------------------\n";
        accountFile.close();
        namesFile.close();
        balanceFile.close();
        if(flag7>0)
            cout<<"Inquiry completed..\n";
        else
            cout<<"Account number not found..\n";
    }
}
//deposit money
void deposit(string acno,int amnt)
{
    int flag8=0;
    fstream accountFile,balanceFile,tempBalance;
    accountFile.open("accountnum.txt",ios::in);
    balanceFile.open("balance.txt",ios::in);
    tempBalance.open("tempBalance.txt",ios::out);
    string account_number,name,balance;
    if(accountFile.is_open()&&balanceFile.is_open()){
        while(getline(accountFile,account_number)){
            getline(balanceFile,balance);
            if(account_number!=acno){
                tempBalance<<balance<<"\n";
            }
            else{
                stringstream ss1;
                int total_amount;
                ss1<<balance;
                ss1>>total_amount;
                total_amount=total_amount+amnt;
                string new_balance;
                stringstream ss2;
                ss2<<total_amount;
                ss2>>new_balance;
                tempBalance<<new_balance<<"\n";
                flag8++;
            }
        }
        accountFile.close();
        balanceFile.close();
        tempBalance.close();
        remove("balance.txt");
        rename("tempBalance.txt","balance.txt");
        if(flag8>0)
            cout<<"Amount Deposited Successfully..\n";
        else
            cout<<"Account number not found..\n";
    }
}
//withdraw money
void withdraw(string acno,int amnt)
{
    int flag9=0;
    fstream accountFile,balanceFile,tempBalance;
    accountFile.open("accountnum.txt",ios::in);
    balanceFile.open("balance.txt",ios::in);
    tempBalance.open("tempBalance.txt",ios::out);
    string account_number,name,balance;
    if(accountFile.is_open()&&balanceFile.is_open()){
        while(getline(accountFile,account_number)){
            getline(balanceFile,balance);
            if(account_number!=acno){
                tempBalance<<balance<<"\n";
            }
            else{
                stringstream ss1;
                int total_amount;
                ss1<<balance;
                ss1>>total_amount;
                total_amount=total_amount-amnt;
                string new_balance;
                stringstream ss2;
                ss2<<total_amount;
                ss2>>new_balance;
                tempBalance<<new_balance<<"\n";
                flag9++;
            }
        }
        accountFile.close();
        balanceFile.close();
        tempBalance.close();
        remove("balance.txt");
        rename("tempBalance.txt","balance.txt");
        if(flag9>0)
            cout<<"Amount Withdraw Successfully..\n";
        else
            cout<<"Account number not found..\n";
    }
}
//transfer money to any other registered bank account
void transferAmount(string y_accNo,string b_accNo,int money)
{
    int flag10=0;
    int flag11=0;
    fstream accountFile,balanceFile,namesFile,tempBalance;
    accountFile.open("accountnum.txt",ios::in);
    balanceFile.open("balance.txt",ios::in);
    tempBalance.open("tempBalance.txt",ios::out);
    string account_number,name,balance;
    if(accountFile.is_open()&&balanceFile.is_open()){
        while(getline(accountFile,account_number)){
            getline(balanceFile,balance);
            if((account_number!=y_accNo) && (account_number!=b_accNo)){
                tempBalance<<balance<<"\n";
            }
            else if (account_number==y_accNo)
            {
                stringstream ss1;
                int total_amount;
                ss1<<balance;
                ss1>>total_amount;
                total_amount=total_amount-money;
                string new_balance;
                stringstream ss2;
                ss2<<total_amount;
                ss2>>new_balance;
                tempBalance<<new_balance<<"\n";
                flag10++;
            }
            else
            {
                stringstream ss1;
                int total_amount;
                ss1<<balance;
                ss1>>total_amount;
                total_amount=total_amount+money;
                string new_balance;
                stringstream ss2;
                ss2<<total_amount;
                ss2>>new_balance;
                tempBalance<<new_balance<<"\n";
                flag11++;
            }
        }
        accountFile.close();
        balanceFile.close();
        tempBalance.close();
        remove("balance.txt");
        rename("tempBalance.txt","balance.txt");
        if(flag10>0 && flag11>0)
            cout<<"Money Transfered Successfully..\n";
        else if(flag10==0)
            cout<<"Your account number is incorrect..\n";
        else if(flag11==0)
            cout<<"Beneficiary account number is incorrect..\n";
        else
            cout<<"Both entered accounts are not found..\n";
    }
}

//all menus here..
//main menu
void mainMenu()
{
    cout<<"------------------------\n";
    cout<<"|BANK MANAGEMENT SYSTEM|\n";
    cout<<"|----------------------|\n";
    cout<<"|1. Account Management |\n";
    cout<<"|2. ATM                |\n";
    cout<<"|3. Policies           |\n";
    cout<<"|   For Exit Enter 0   |\n";
    cout<<"------------------------\n";
}
//account management menu
void accountManagementMenu()
{
    cout<<"------------------------\n";
    cout<<"|  ACCOUNT MANAGEMENT  |\n";
    cout<<"|----------------------|\n";
    cout<<"|1. Display All Account|\n";
    cout<<"|2. Add Account        |\n";
    cout<<"|3. Delete Account     |\n";
    cout<<"------------------------\n";
}
//display accounts menu
void dislayAccountMenu()
{
    cout<<"---------------------------------------------------------------\n";
    cout<<"|                        DISPLAY MENU                         |\n";
    cout<<"|-------------------------------------------------------------|\n";
    cout<<"|1. Display all accounts                                      |\n";
    cout<<"|2. Display all account of particular bank                    |\n";
    cout<<"|3. Display all account in same branch of particular bank     |\n";
    cout<<"|4. Display account with balance less than 1000               |\n";
    cout<<"|5. Display account with balance greater than 1 lac           |\n";
    cout<<"---------------------------------------------------------------\n";
}
//ATM menu
void ATM_DisplayMenu()
{
    cout<<"----------------------\n";
    cout<<"|      ATM MENU      |\n";
    cout<<"|--------------------|\n";
    cout<<"|1. Balance Inquiry  |\n";
    cout<<"|2. Deposit          |\n";
    cout<<"|3. Withdraw         |\n";
    cout<<"|4. Transfer         |\n";
    cout<<"----------------------\n";
}
//bank policies list..
void bankPolicy()
{
    cout<<"------------------------------------------------------\n";
    cout<<"|                     BANK POLICIES                  |\n";
    cout<<"|----------------------------------------------------|\n";
    cout<<"|1. Access to Information.                           |\n";
    cout<<"|2. Progress report of a CAS.                        |\n";
    cout<<"|3. See definition of Country Assistance Strategy.   |\n";
    cout<<"|4. Country Policy and Institutional Assessment.     |\n";
    cout<<"|5. International Monetary Fund provided.            |\n";
    cout<<"|  -->This policy is effective as of Dec 30,2023<--  |\n";
    cout<<"------------------------------------------------------\n";

}
int main()
{
    char option,account_manage_op,display_op,atm_op;
    while(1)
    {
    mainMenu();
    cout<<"Enter the option:\n";
    cin>>option;
    switch(option)
    {
    case '1':
        accountManagementMenu();
        cout<<"Enter the option:\n";
        cin>>account_manage_op;
        switch(account_manage_op)
        {
        case '1':
            dislayAccountMenu();
            cout<<"Enter the option:\n";
            cin>>display_op;
            switch(display_op)
            {
            case '1':
                displayAllAccountsData();
                break;
            case '2':
                {
                    string bank_name;
                    cout<<"Enter the Bank Name:\n";
                    cin>>bank_name;
                    showByBankName(bank_name);
                }
                break;
            case '3':
                {
                    string branch_code;
                    cout<<"Enter the Branch Code:\n";
                    cin>>branch_code;
                    showByBranchCode(branch_code);
                }
                break;
            case '4':
                showAccountWithLessAmount();
                break;
            case '5':
                showAccountWithGreaterAmount();
                break;
            default:
                cout<<"wrong input..\n";

            }
            break;
        case '2':
            {
                string account_n,name,balance;
                cout<<"Enter Account Number:\n";
                cin>>account_n;
                cout<<"Enter Name:\n";
                cin>>name;
                cout<<"Enter Balance:\n";
                cin>>balance;
                addAccount(account_n,name,balance);
            }
            break;
        case '3':
            {
                string account_no;
                cout<<"Enter Account Number:\n";
                cin>>account_no;
                deleteAccount(account_no);
            }
            break;
        default:
            cout<<"wrong input..\n";
        }
        break;
    case '2':
        ATM_DisplayMenu();
        cout<<"Enter the option:\n";
        cin>>atm_op;
        switch(atm_op)
        {
        case '1':
            {
                string accNO;
                cout<<"Enter your account number:\n";
                cin>>accNO;
                balanceInquiry(accNO);
            }
            break;
        case '2':
            {
                string accNO;
                int amount;
                cout<<"Enter the account number:\n";
                cin>>accNO;
                cout<<"Enter the amount you want to deposit:\n";
                cin>>amount;
                deposit(accNO,amount);
            }
            break;
        case '3':
            {
                string accNO;
                int amount;
                cout<<"Enter the account number:\n";
                cin>>accNO;
                cout<<"Enter the amount you want to withdraw:\n";
                cin>>amount;
                withdraw(accNO,amount);
            }
            break;
        case '4':
            {
                string your_accNo,beneficiary_accNo;
                int amount;
                cout<<"Enter your account number:\n";
                cin>>your_accNo;
                cout<<"Enter beneficiary account number:\n";
                cin>>beneficiary_accNo;
                cout<<"Enter amount you want to transfer:\n";
                cin>>amount;
                transferAmount(your_accNo,beneficiary_accNo,amount);
            }
            break;
        default:
            cout<<"wrong input..\n";
        }
        break;
    case '3':
        bankPolicy();
        break;
    case '0':
        cout<<"[[SYSTEM EXIT SUCCESSFULLY]]\n";
        return 0;
    default:
        cout<<"Wrong Input..\nPlease enter correct one..\n";
    }
    }
}
