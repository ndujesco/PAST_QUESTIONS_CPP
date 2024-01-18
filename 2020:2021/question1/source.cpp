
#include <iostream>
#include <fstream>

#include <string>
#include <iomanip>

#include "header.h" 

using namespace std;



void FillShoppingInfo(Person &person)
{
    cout << "Enter Product Info.\n";

    cout << "\tProduct Name: ";
    cin.getline(person.product.ProductName, 50);

    cout << "\tUnit Price: ";
    cin >> person.product.UnitPrice;
    cin.ignore();

    cout << "\tQuantity: ";
    cin >> person.product.Quantity;
    cin.ignore();

    person.product.TotalPrice = person.product.UnitPrice * person.product.Quantity;

    cout << "\nEnter Shop Info.\n";

    cout << "\tShop Name: ";
    cin.getline(person.shop.ShopName, 50);

    cout << "\tShop Address: ";
    cin.getline(person.shop.Address, 50);

    cout << "\nEnter Customer Info.\n";

    cout << "\tCustomer Name: ";
    cin.getline(person.customer.CustomerName, 50);

    cout << "\tCustomer PhoneNumber: ";
    cin.getline(person.customer.PhoneNumber, 15);
}

void WriteReceipt(Person person)
{
    ofstream receiptFile;

    string asterisk = "*****************************************************************************************";
    string address = person.shop.Address;
    string thanks = "Thanks for your patronage";
    string shopName = person.shop.ShopName;
    int total_width = asterisk.length();
    int width = total_width / 4;

    receiptFile.open("receipt.txt");

    if (receiptFile.is_open())
    {
        receiptFile << asterisk << endl

                    << left << setw((total_width - shopName.length()) / 2) << " " << shopName << endl
                    << setw((total_width - address.length()) / 2) << " " << address << endl
                    << endl

                    << setw(width) << "Customer" << person.customer.CustomerName << endl
                    << setw(width) << "PhoneNumber" << person.customer.PhoneNumber << endl
                    << endl

                    << "Your Order" << endl
                    << endl

                    << setw(width) << "ProductName" << setw(width) << "Unit Price"
                    << "Quantity Ordered" << endl
                    << setw(width) << person.product.ProductName << setw(width) << person.product.UnitPrice << person.product.Quantity << endl

                    << setw(width) << " " << setw(width) << " "
                    << "********" << endl
                    << setw(width) << " " << setw(width) << "Total Price" << person.product.TotalPrice << endl
                    << setw(width) << " " << setw(width) << " "
                    << "********" << endl
                    << endl

                    << setw((total_width - thanks.length()) / 2) << "" << thanks << endl
                    << asterisk << endl;
    }
    else
    {
        cerr << "Could not create file. Try again.";
    }
    receiptFile.close();
}
