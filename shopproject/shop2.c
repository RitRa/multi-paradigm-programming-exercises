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

void printProduct(struct Product p)
{
    printf("-------------------------\n" );
    printf("Product Name: %s \nProduct Price: %.2f\n", p.name, p.price);
    printf("-------------------------\n" );
}


// reading in customers from csv
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

            char *n = strtok(line, ",");
            printf("%s\n", line );
            char *b = strtok(NULL, ",");
            char *p = strtok(NULL, ",");
            double budget = atoi(b);
            char *name = malloc(sizeof(char)*50);
            strcpy(name, n);
            struct Customer customer = {name, budget};
            //printf("The shop has %s of the above \n", customer.name);
        }

    return customer;

}

void printCustomer(struct Customer c)
{
    printf("Customer Name: %s \n Customer Budget: %.2f\n", c.name, c.budget);

}

struct Shop createAndStockShop()
{
    struct Shop shop = {400};
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;

    // r = read
    fp = fopen("stock.csv", "r");
// if file doesn't exist exit program
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1)
    {
        i++;
        // reading in the first line of the csv
        if(i == 1 )
        {
            char *n = strtok(line, ",");
            // grabbing the cash amount
            char *c = strtok(NULL, ",");
            double cashn = atoi(c);
            //assigning it to the shop
            shop.cash = cashn;

        }
        else
        {
            char *n = strtok(line, ",");
            char *p = strtok(NULL, ",");
            char *q = strtok(NULL, ",");
            // convert to datatypes
            double price = atoi(p);
            int quantity = atoi(q);
            char *name = malloc(sizeof(char)*50);
            strcpy(name, n);
            struct Product product = {name, price};
            struct ProductStock stockItem = {product, quantity};
            shop.stock[shop.index++]=stockItem;
        }

    }

    return shop;

}

void printShop(struct Shop s)
{
    printf("Shop has %.2f in cash\n", s.cash);
    for(int i=0; i <s.index; i++)
    {
        printProduct(s.stock[i].product);
        printf("The shop has %d of the above \n", s.stock[i].quantity);
    }

}

int main(void)
{

    struct Customer customer = orderAndshop();
    printCustomer(customer);
    struct Shop shop = createAndStockShop();
    printShop(shop);
    printf("helloworld");


    return 0;
}
