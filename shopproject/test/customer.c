#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// comment out cmd +/

struct Product {
    char* name;
    double price;
};

struct ProductStock {
    struct Product product;
    int quantity;
};

struct Customer {
    char* name;
    double budget;
    struct ProductStock shoppingList[10];
    int index;
};

struct Shop {
    double cash;
    struct ProductStock stock[20];
    int index;
};


struct Customer orderAndshop()
{
    struct Customer customer;
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;


    fp = fopen("customerorders.csv", "r");
    // if file doesn't exist exit program
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1)
    {
            //customer
            char *cname = strtok(line, ",");
            //budget
            char *b = strtok(NULL, ",");
            //printf("Name is %s, Budget is %s \n", cname, b);
            // product
            //char *n = strtok(NULL, ",");
            char *q = strtok(NULL, ",");
            double budget = atof(b);

            int quantity = atoi(q);


            customer.name = cname;
            customer.budget = budget;


            printf("Customer name %s\nbudget %.2f\n", customer.name , customer.budget );

        }
        //printf("name %s\n", customer.name );

    return customer;
}

void printProduct(struct Product p)
{
    printf("-------------------------\n" );
    printf("Product Name: %s \nProduct Price: %.2f\n", p.name, p.price);
    printf("-------------------------\n" );
}

void printCustomer(struct Customer c)
{

    printf("Customer Name: %s \nCustomer Budget: %f\n", c.name, c.budget);
    printf("-------------------------\n" );


}


int main(void)
{
    struct Customer customer = orderAndshop();
    printCustomer(customer);

    return 0;
}
