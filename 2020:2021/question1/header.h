#ifndef QUESTION1_H
#define QUESTION1_H

struct Product
{
    char ProductName[50];
    float UnitPrice;
    int Quantity;
    float TotalPrice;
};

struct Shop
{
    char ShopName[50];
    char Address[50];
};

struct Customer
{
    char CustomerName[50];
    char PhoneNumber[15];
};

struct Person
{
    Shop shop;
    Customer customer;
    Product product;
};

void FillShoppingInfo(Person &);
void WriteReceipt(Person);

#endif