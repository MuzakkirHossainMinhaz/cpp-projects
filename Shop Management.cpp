#include <bits/stdc++.h>
using namespace std;

class Shop
{
public:
    string product_name[10];
    int product_price[10];
    int product_quantity[10];

protected:
    int total_income;

public:
    int getTotal()
    {
        return total_income;
    }
    void setTotal(int total_income)
    {
        this->total_income+=total_income;
    }
};

int main()
{
    Shop *myShop = new Shop;
    cout << "Number of products : ";
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout << "Product " << i << " Name: ";
        cin >> myShop->product_name[i];
        cout << "Product " << i << " Price: ";
        cin >> myShop->product_price[i];
        cout << "Product " << i << " Quantity: ";
        cin >> myShop->product_quantity[i];
    }

    while(true)
    {
        cout << endl;
        cout << "\t\t BUY PRODUCT" << endl;
        cout << "\t\t_____________" << endl;

        cout << "Product Index\t\t";
        for(int i=1; i<=n; i++)
        {
            cout << i << "\t";
        }
        cout << endl;

        cout << "Product Name\t\t";
        for(int i=1; i<=n; i++)
        {
            cout << myShop->product_name[i] << "\t";
        }
        cout << endl;

        cout << "Product Price\t\t";
        for(int i=1; i<=n; i++)
        {
            cout << myShop->product_price[i] << "\t";
        }
        cout << endl;

        cout << "Product Quantity\t";
        for(int i=1; i<=n; i++)
        {
            cout << myShop->product_quantity[i] << "\t";
        }
        cout << endl << endl;

        cout << "Which product do you want? From 1 to " << n << ": ";
        int index, quantity;
        cin >> index;
        cout << "What is the quantity that you want of " << myShop->product_name[index] << " : ";
        cin >> quantity;
        if(myShop->product_quantity[index] < quantity)
        {
            cout << "This quantity is not available." << endl;
        }
        else
        {
            myShop->setTotal(quantity * myShop->product_price[index]);
            myShop->product_quantity[index] -= quantity;
            cout << endl;

            cout << myShop->product_name[index] << " bought " << quantity << "pcs successfully" << endl;
            cout << "Your total income : " << myShop->getTotal() << endl;
        }
    }

    return 0;
}
