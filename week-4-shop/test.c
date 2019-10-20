#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Product {
	char* name;
	double price;
};

struct ProductStock {
	struct Product product;
	int quantity;
};

struct Shop {
	double cash;
	struct ProductStock stock[20];
	int index;
};

struct Customer {
	char* name;
	double budget;
	struct ProductStock shoppingList[10];
	int index;
};

void printProduct(struct Product p)
{
	printf("PRODUCT NAME: %s \nPRODUCT PRICE: %.2f\n", p.name, p.price);
	printf("-------------\n");
}



struct Shop createAndStockShop()
{
	struct Shop shop = { 200 };
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
	int i = 0;

    fp = fopen("stock.csv", "r");
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

// print shop details
void printShop(struct Shop s)
{
	printf("Shop has %.2f in cash\n", s.cash);
	for (int i = 0; i < s.index; i++)
	{
		printProduct(s.stock[i].product);
		printf("The shop has %d of the above\n", s.stock[i].quantity);
	}
}

// reading in customers from csv
struct Customer orderAndshop(){
	struct Customer customer;
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	int i = 0;


	fp = fopen("orders.csv", "r");
	// if file doesn't exist exit program
	if (fp == NULL)
		exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1)
    {

            char *n = strtok(line, ",");
            char *b = strtok(NULL, ",");
            char *p = strtok(NULL, ",");
			char *q = strtok(NULL, ",");

            double budget = atoi(b);
			int quantity = atoi(q);
            char *name = malloc(sizeof(char)*50);
            strcpy(name, n);

            customer.name = name;
			customer.budget = budget;

			struct Product product = {p};
			struct ProductStock orderItem = {product, quantity};
			customer.shoppingList[customer.index++]=orderItem;
            printf("Rita test, NAME: %s \nBUDGET: %.2f product %s quantity %d \n", customer.name, customer.budget, product.name, orderItem.quantity);
        }

    return customer;
}

void printCustomer(struct Customer c)
{
	printf("-------------\n");

	for(int z = 0; z < c.index; z++)
	{
        for(int i = 0; i < c.index; z++)
    	{

		printf("z %d\n", z);
        printf("i %d\n", i);
		printf("CUSTOMER NAME: %s \n", c[i].name);

		printf("CUSTOMER NAME: %s \nBUDGET: %.2f\n", c.name, c.budget);
		printProduct(c.shoppingList[z].product);
		printf("%s ORDERS %d OF ABOVE PRODUCT %s \n", c.name, c.shoppingList[z].quantity, c.shoppingList[z].product.name);
		double cost = c.shoppingList[z].quantity * c.shoppingList[z].product.price;
		printf("Price %f\n", c.shoppingList[z].product.price);
		printf("The cost to %s will be €%.2f\n", c.name, cost);
    }

	}
}

int main(void)
{

	struct Shop shop = createAndStockShop();
	printShop(shop);

	struct Customer customer = orderAndshop();
    printCustomer(customer);

    return 0;
}
