package JavaShop;

public class Customer {
	private String name;
	private double budget;
	private ArrayList<ProductStock> shoppingList;
	
	public Customer(String filename)
	public String getName() {
		return name;
	}


	public double getBudget() {
		return budget;
	}


	public ArrayList<ProductStock> getShoppingList() {
		return shoppingList;
	}


	@Override
	public String toString() {
		return "Customer [name=" + name + ", budget=" + budget + "]";
	}

}	
