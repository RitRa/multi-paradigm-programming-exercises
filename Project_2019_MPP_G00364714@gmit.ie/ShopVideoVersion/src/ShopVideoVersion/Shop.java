package ShopVideoVersion;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;  // Import the Scanner class

public class Shop {

	private double cash;
	private ArrayList<ProductStock> stock;

	public Shop(String fileName) {
		stock = new ArrayList<>();
		List<String> lines = Collections.emptyList();
		try {
			lines = Files.readAllLines(Paths.get(fileName), StandardCharsets.UTF_8);
			System.out.println(lines.get(0));
			cash = Double.parseDouble(lines.get(0));
			// i am removing at index 0 as it is the only one treated differently
			lines.remove(0);
			for (String line : lines) {
				// System.out.println(line);
				String[] arr = line.split(",");
				String name = arr[0];
				double price = Double.parseDouble(arr[1]);
				int quantity = Integer.parseInt(arr[2].trim());
				Product p = new Product(name, price);
				ProductStock s = new ProductStock(p, quantity);
				//System.out.println(p);
				//System.out.println(s);
				stock.add(s);
				//stock.add(p);
			}
			
		}

		catch (IOException e) {

			// do something
			e.printStackTrace();
		}
	}

	public double getCash() {
		return cash;
	}

	public ArrayList<ProductStock> getStock() {
		return stock;
	}

	@Override
	public String toString() {
		String ret = "\n-----Shop info----\n" +"Cash:" + cash + "\n\n-----In Stock----\n";
		for (ProductStock productStock : stock) {
			//ret+= productStock.getProduct().getName() + productStock.getProduct() + " Quantity: " + productStock.getQuantity() + "\n";
			ret+= productStock.getProduct().getName() + ", Price: " + productStock.getProduct().getPrice()  + ", Quantity: " + productStock.getQuantity() + "\n";
		}
		return ret;
	}



	public static void findprice(Shop shop, Customer james){  
			double amount = 0;
			double shortamount;
			int quantity = 0;

			System.out.println("----------------------\n");
			
			ArrayList<ProductStock> shopList = james.getShoppingList() ;
			ArrayList<ProductStock> shopstock = shop.getStock();
			System.out.println("\n-----Customer Bill-----\n");
			for (ProductStock sname : shopstock ) {
			
				for (ProductStock product : shopList ) {
				
					if(product.getProduct().getName().equals(sname.getProduct().getName())){
						System.out.println(product.getProduct().getName()+ " "+ sname.getProduct().getPrice()+ " * "+ product.getQuantity() );
			
						// if the stock
						if(sname.getQuantity() < product.getQuantity())
						{
							//perror("Not in stock");
						//	printf("Sorry, We have only %d \n \n", sname.getQuantity());
							System.out.println("Sorry, We have only:" + sname.getQuantity() +"\n");
						}
						else{
							//calculating the cost
							amount = sname.getProduct().getPrice() * product.getQuantity() + amount;
							
							// new quantity
							quantity = sname.getQuantity() - product.getQuantity();
							
							sname.setQuantity(quantity);
			
						}
						
				
					}	
				}
			}
			

			if(james.getBudget() < amount)
			{
				shortamount = (amount - james.getBudget());
				System.out.println("----------------------\n");
				System.out.println("Oh No!!!" );
				System.out.println("You need more cash, you are short:" + shortamount +"\n");
				System.out.println("----------------------\n");
			}
			else{
				System.out.println("----------------------");
				System.out.println("Total Customer Bill:\n" + amount);
				
				System.out.println("--------Shop Cash--------");
				shop.cash = shop.getCash() +amount;
				System.out.println("Shop cash:" + shop.cash +"\n");

				for (ProductStock sname : shopstock ) {
					System.out.println(sname.getProduct().getName()+ " " +sname.getQuantity());
			
				}
		
			}

		}



	public static void main(String[] args) {

		Shop shop = new Shop("src/ShopVideoVersion/stock.csv");
		System.out.println(shop);

		Customer james = new Customer("src/ShopVideoVersion/customer.csv");
		System.out.println(james);

		//List shoppingList = new ArrayList[] {"Milk", 1};

		//Customer a = new Customer("test", 20, shoppingList);
		//System.out.println(a);

		//findPrice(Shop shop);
		findprice(shop, james);

		Scanner s = new Scanner(System.in);
		System.out.println("-----Live mode------");
		System.out.println(""+"What's your name?");
		String name2 = s.nextLine();

		System.out.println("Please enter budget?");
		double budget2 = Double.valueOf(s.nextLine());

		System.out.println("What product do you want to buy?");
		String productname = s.nextLine();

		System.out.println("How many?");
		int quantity = Integer.valueOf(s.nextLine());

		
		
		ArrayList<ProductStock> shoppingList2 = new ArrayList<ProductStock>();
				Product p = new Product(productname, 0);
				ProductStock sn = new ProductStock(p, quantity);
				shoppingList2.add(sn);

				System.out.println(sn);
		
		s.close();
				
		Customer newcustomer = new Customer( name2, budget2, shoppingList2);
		System.out.println(newcustomer);
		findprice(shop, newcustomer);


		
	}

}
