#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// works
// how to run gcc -g -o shopproject.o shopproject.c
// ./shopproject.o
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

        }

    return current;
}

// customer details and order
void printCustomer(struct Customer current)
{
	printf("\n#######\n");
	printf("CUSTOMER NAME: %s \nBUDGET: %.2f\n", current.name, current.budget);

	for (int i = 0; i < current.index; i++)
	{
		printProduct(current.shoppingList[i].product);
		printf("The quantity of the above: %d\n", current.shoppingList[i].quantity);
		
		printf("-------------\n");
	}

}

// searching both and comparing and returning price
double findProductPrice(struct Shop s, struct Customer current)
{
	struct Product productcustomer;
	double amount =0;
	double shortamount;
	// loop through shop 
	printf("\n--------Customer Bill--------\n");
	for (int i = 0; i < s.index; i++)
	{
		// loop through customer order
		for (int j = 0; j < current.index; j++)
		{
			struct Product product = s.stock[i].product;
			struct Product productcustomer = current.shoppingList[j].product;
			// compare shop and order
			if (strcmp(product.name, productcustomer.name) ==0)
			{ 
					printf("%s, Price %.2f * Quantity %d\n", current.shoppingList[j].product.name, product.price, current.shoppingList[j].quantity);
				    // check if in stock in store
					//printf("In stock: Name: %s, Quantity %d\n", current.shoppingList[j].product.name, s.stock[i].quantity);
					// check if the shop has the item quantity
					if(s.stock[i].quantity < current.shoppingList[j].quantity)
					{
						//perror("Not in stock");
						printf("Sorry, We have only %d \n \n", s.stock[i].quantity);
					}
					else{
				     // adding up the bill
					amount = product.price * current.shoppingList[j].quantity + amount;
					//i++;		
					}
			}		
		}
	}
		if(current.budget< amount)
		{
			shortamount = (amount - current.budget);
			printf("----------------------\n");
			printf("Oh No!!!\n" );
			printf("You need more cash, you are short: %.2f \n", shortamount );
			printf("----------------------\n");
							
		}
		else{
			printf("\n");
			printf("Total Customer Bill: %.2f\n", amount);
			// new float in shop
			printf("\n");
			printf("--------Shop Cash--------\n");
			// add to the shop float
			s.cash = s.cash + amount;
			printf("Shop cash has been updated: %.2f\n", s.cash);

		}

	return -1; 
}

struct Customer orderlive()
{

	// what's your name?
	printf("What is your name?\n");
	char *name = malloc(sizeof(char)*50);
    scanf(" %s", name);

	// budget
	printf("What is your budget?\n");
	double budget;
	scanf("%lf", &budget);
	
	printf("What would you like to buy?\n");
	char *p = malloc(sizeof(char)*50);
	scanf(" %s", p);

	printf("How many?\n");
	int quantity;
	scanf(" %d", &quantity);
	

	struct Customer newcurrent ={name, budget};
	printf("\nName : %s, Budget: %.2f",newcurrent.name,newcurrent.budget );

	struct Product product = {p};
	struct ProductStock orderItem = {product, quantity};
	newcurrent.shoppingList[newcurrent.index++]=orderItem;

	printf("\nName : %s, quantity: %d", newcurrent.shoppingList[0].product.name,newcurrent.shoppingList[0].quantity );

	
   return newcurrent;
	

}
int main(void)
{
	struct Shop shop = createAndStockShop();
	printShop(shop);

	struct Customer current = orderAndshop();
	//printf("Name: %s,  budget %f,  \n", current.name, current.budget);	
	

    printCustomer(current);

	// searching for price
	findProductPrice(shop, current);


	struct Customer newcurrent = orderlive();
	findProductPrice(shop, newcurrent );
	

    return 0;
}
