#include<bits/stdc++.h>
using namespace std;

class Restaurant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];

protected:
    int total_tax;

public:
    Restaurant()
    {
        total_tax = 0;
    }

    string getName(int code)
    {
        for(int i=0; i<12; i++)
        {
            if(this->food_item_codes[i] == code)
                return this->food_item_names[i];
        }
    }

    int getPrice(int code)
    {
        for(int i=0; i<12; i++)
        {
            if(this->food_item_codes[i] == code)
                return this->food_item_prices[i];
        }
    }

    void setTax(double tax)
    {
        this->total_tax += tax;
    }

    bool checkCode(int code)
    {
        for(int i=0; i<12; i++)
        {
            if(this->food_item_codes[i] == code)
                return true;
        }
        return false;
    }

};

int main()
{
    Restaurant *restaurant = new Restaurant();

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> restaurant->food_item_codes[i];
        getchar();
        getline(cin, restaurant->food_item_names[i]);
        cin >> restaurant->food_item_prices[i];
    }

    while(true)
    {
        cout << endl;
        cout << "\t\t    Make Bill" << endl;
        cout << "\t\t-----------------" << endl;
        cout << endl;

        cout << " Item Code\t     Item Name\t\t\t Item Price" << endl;
        for(int i=0; i<n; i++)
        {
            cout << "   " << restaurant->food_item_codes[i] << "\t\t";
            cout << " " << restaurant->food_item_names[i] << "\t\t";
            cout << "   " << restaurant->food_item_prices[i] << endl;
        }
        cout << endl << endl;

        int tableNumber, items;
        cout << " Enter Table No: ";
        cin >> tableNumber;
        cout << " Number of Items: ";
        cin >> items;

        int code[items], quantity[items];
        for(int i=1; i<=items; i++)
        {
            cout << " Enter Item " << i << " Code: ";
            Again:
                cin >> code[i];

            if(!restaurant->checkCode(code[i]))
            {
                cout << " Invalid Code! Enter again...\n ";
                goto Again;
            }

            cout << " Enter Item " << i << " Quantity: ";
            cin >> quantity[i];
        }

        cout << endl << endl;
        cout << "\t\t\t\t\t\t    Bill SUMMARY" << endl;
        cout << "\t\t\t\t\t\t--------------------" << endl;

        double total = 0;
        cout << " Table No.: " << tableNumber << endl;
        cout << " Item Code\t     Item Name\t\t\t Item Price\t\t Item Quantity\t\t Total Price" << endl;
        for(int i=1; i<=items; i++)
        {
            cout << "   " << code[i] << "\t\t";
            cout << " " << restaurant->getName(code[i]) << "\t\t";
            cout << "   " << restaurant->getPrice(code[i]) << "\t\t\t";
            cout << "   " << quantity[i] << "\t\t\t";
            cout << "   " << restaurant->getPrice(code[i])*quantity[i] << endl;
            total += restaurant->getPrice(code[i])*quantity[i];
        }

        /// Calculate tax
        double tax = total*(5.0/100.0);
        cout << "   TAX\t\t\t\t\t\t\t\t\t\t\t\t   " << tax << endl;
        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
        total += tax;
        cout << "  Net Total\t\t\t\t\t\t\t\t\t\t\t = " << total << " Taka" << endl;

        cout << endl << endl;

        /// Add tax to total_tax
        restaurant->setTax(tax);
    }

    return 0;
}
