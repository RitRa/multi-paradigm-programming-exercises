package JavaShop;

public class Shop {
	private double cash;
	private ArrayList <ProductStock> stock;
	
	public Shop(String filename) {
		//To Do finish constructor
	}
	
	public double getCash() {
		return cash;
		
	}
	
	@Override
	public String toString() {
		return "Shop [cash=" + cash + "]";
	}
	

}
