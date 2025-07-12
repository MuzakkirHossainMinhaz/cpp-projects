#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
public:
    string accountHolder;
    string address;
    int age;
    int accountNumber;

protected:
    int balance;

private:
    string password;

public:
    BankAccount(string accountHolder, string address, int age, string password)
    {
        srand(time(0));
        this->accountHolder = accountHolder;
        this->address = address;
        this->age = age;
        this->password = password;
        this->balance = 0;
        this->accountNumber = rand()%1000000000;
        cout << "Your Account No. is :  " << this->accountNumber << endl;
    }

    string givePassword()
    {
        return password;
    }

    int showBalance(string password)
    {
        if(this->password==password)
            return this->balance;
        else
            return -1;
    }

    void addMoney(string password, int amount)
    {
        if(amount < 0)
        {
            cout << "Invalid Amount" << endl;
            return;
        }

        if(this->password == password)
        {
            this->balance += amount;
            cout << "Successfully Money Added" << endl;
        }
        else
            cout << "Password Incorrect" << endl;
    }

    void depositMoney(string password, int amount)
    {
        if(amount < 0)
        {
            cout << "Invalid Amount" << endl;
            return;
        }

        if(this->balance < amount)
        {
            cout << "Insufficient Balance" << endl;
            return;
        }

        if(this->password == password)
        {
            this->balance -= amount;
            cout << "Successfully Money Deposit" << endl;
        }
        else
            cout << "Password Incorrect" << endl;
    }

    friend class MyCash;
};

class MyCash
{
protected:
    int balance;

public:
    MyCash()
    {
        this->balance = 0;
    }
    void addMoneyFromBank(BankAccount *myAccount, string password, int amount)
    {
        if(amount < 0)
        {
            cout << "Invalid Amount" << endl;
            return;
        }

        if(myAccount->balance < amount)
        {
            cout << "Insufficient Balance" << endl;
            return;
        }

        if(myAccount->password == password)
        {
            this->balance += amount;
            myAccount->balance -= amount;
            cout << "Successfully Money Added from Bank Account" << endl;
        }
        else
            cout << "Password Incorrect" << endl;
    }

    int showBalance()
    {
        return this->balance;
    }
};

BankAccount* createAccount();

void add_money(BankAccount *myAccount);

void deposit_money(BankAccount *myAccount);

void add_money_from_bank(MyCash *myCash, BankAccount *myAccount);

int main()
{
    BankAccount *myAccount = createAccount();
    MyCash *myCash = new MyCash();

    while(true)
    {
        cout << endl;
        cout << "Select Option:" << endl;
        cout << "  1. ADD Money to Bank." << endl;
        cout << "  2. DEPOSIT Money from Bank." << endl;
        cout << "  3. ADD Money to MyCash from Bank." << endl;
        cout << "  4. Exit." << endl;
        cout << endl;

        bool isExit = false;
        int option;
        cin >> option;
        switch(option)
        {
        case 1:
            add_money(myAccount);
            break;
        case 2:
            deposit_money(myAccount);
            break;
        case 3:
            add_money_from_bank(myCash, myAccount);
            break;
        case 4:
            isExit = true;
            break;
        default:
            cout << "Invalid Option Entered..!\n\n" << endl;
        }

        if(isExit)
        {
            delete myAccount;
            break;
        }
    }

    return 0;
}

BankAccount* createAccount()
{
    string accountHolder, password, address;
    int age;

    cout << "CREATE NEW ACCOUNT:" << endl;
    cout << "Your Name: ";
    cin >> accountHolder;
    cout << "Your Address: ";
    cin >> address;
    cout << "Your Age: ";
    cin >> age;
    cout << "Password: ";
    cin >> password;

    BankAccount *myAccount = new BankAccount(accountHolder, address, age, password);

    return myAccount;
}

void add_money(BankAccount *myAccount)
{
    string password;
    int amount;

    cout << "ADD MONEY:" << endl;
    cout << "Password: ";
    cin >> password;
    cout << "Amount: ";
    cin >> amount;

    myAccount->addMoney(password, amount);

    cout << "Your Balance: " << myAccount->showBalance(myAccount->givePassword()) << endl;
}

void deposit_money(BankAccount *myAccount)
{
    string password;
    int amount;

    cout << "DEPOSIT MONEY:" << endl;
    cout << "Password: ";
    cin >> password;
    cout << "Amount: ";
    cin >> amount;

    myAccount->depositMoney(password, amount);

    cout << "Your Balance: " << myAccount->showBalance(myAccount->givePassword()) << endl;
}

void add_money_from_bank(MyCash *myCash, BankAccount *myAccount)
{
    string password;
    int amount;
    cout << "ADD MONEY FROM BANK" << endl;
    cout << "Password: ";
    cin >> password;
    cout << "Amount: ";
    cin >> amount;

    myCash->addMoneyFromBank(myAccount, password, amount);

    cout << "Your Bank Balance is: " << myAccount->showBalance(myAccount->givePassword()) << endl;
    cout << "MyCash Balance is: " << myCash->showBalance() << endl;
}
