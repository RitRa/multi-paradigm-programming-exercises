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
	
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
	int i = 0;

    fp = fopen("stock.csv", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

	getline(&line, &len, fp);
	// read cash in 
	double cashInshop = atof(line);
	struct Shop shop = { cashInshop };


	while ((read = getline(&line, &len, fp)) != -1)
	{
            char *n = strtok(line, ",");
            char *p = strtok(NULL, ",");
            char *q = strtok(NULL, ",");
            // convert to datatypes
            double price = atof(p);
            int quantity = atoi(q);
            char *name = malloc(sizeof(char)*50);
            strcpy(name, n);

			
            struct Product product = {name, price};
            struct ProductStock stockItem = {product, quantity};
            shop.stock[shop.index++]=stockItem;
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
	
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	int i = 0;

	fp = fopen("orders.csv", "r");
	// if file doesn't exist exit program
	if (fp == NULL)
		exit(EXIT_FAILURE);

	getline(&line, &len, fp);
	// read customer name and budget
	char *n = strtok(line, ",");
    char *b = strtok(NULL, ",");
	
	char *name = malloc(sizeof(char)*50);
    strcpy(name, n);
	double budget = atoi(b);
	struct Customer current ={ name, budget };
	//struct Shop shop = { cashInshop };
	//printf("CUSTOMER NAME: %s \nBUDGET: %.2f\n", current.name, current.budget);
	
    while ((read = getline(&line, &len, fp)) != -1)
    {
		   
            char *p = strtok(line, ",");
			char *q = strtok(NULL, ",");
			int quantity = atoi(q);
			char *productname = malloc(sizeof(char)*50);
			strcpy(productname, p);
			struct Product product = {productname};
			struct ProductStock orderItem = {product, quantity};
			current.shoppingList[current.index++]=orderItem;
			//printf("Product: %s \nQuantity: %d\n", orderItem.product.name, orderItem.quantity);
		
        }

    return current;
}

void printCustomer(struct Customer current)
{
	printf("\n#######\n");

	printf("CUSTOMER NAME: %s \nBUDGET: %.2f\n", current.name, current.budget);

	for (int i = 0; i < current.index; i++)
	{
		printProduct(current.shoppingList[i].product);
		printf("The quantity of the above: %d\n", current.shoppingList[i].quantity);
		//struct Shop s;
		//struct Product product = s.stock[i].product;
		
		//printProduct(product);
		printf("-------------\n");
	}

}



// searching for price
double findProductPrice(struct Shop s, struct Customer current)
{
	for (int i = 0; i < s.index; i++)
	{
		for (int j = 0; j < current.index; j++)
		{
			struct Product product = s.stock[i].product;
			//printf("------------- %s", product.name);
			struct Product productcustomer = current.shoppingList[i].product;
			printf("------------- %s", productcustomer.name);

			char *products = product.name;
			char *productc = productcustomer.name;

			if (strcmp(products, productc) ==0)
			{
					printf("Hello world");
			}
			//current.shoppingList[i].product
			//char *name = product.name;
			//return name;
			// if they are equal it will return a zero
			//if (strcmp(name, n) ==0)
			//{
			//	return product.price;
			//}
		}
	}
	return -1;
}

double findProductPrice2(struct Shop s, char *n)
{
	for (int i = 0; i < s.index; i++)
	{
		struct Product product = s.stock[i].product;
		char *name = product.name;
		// if they are equal it will return a zero
		if (strcmp(name, n) ==0)
		{
			return product.price;
		}
	}
	return -1;
}

int main(void)
{

	struct Shop shop = createAndStockShop();
	printShop(shop);

	struct Customer current = orderAndshop();
	//printf("Name: %s,  budget %f,  \n", current.name, current.budget);		   
    printCustomer(current);

	// searching for price
	double price = findProductPrice2(shop, "Coke can");
	printf("%.2f\n", price);

	//char nameproduct = 
	findProductPrice(shop, current);
	//printf("%c\n", nameproduct);


    return 0;
}
