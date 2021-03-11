package ro.ase.java;

import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import ro.ase.java.models.Product;
import ro.ase.java.models.ShoppingCart;

public class Application {
	public static void main(String[] args) {
		Product p1 = new Product("Hanorac Fucci", "IMBRACAMINTE", 300);
		Product p2 = new Product("Sneakers Nike", "INCALTAMINTE", 250);
		Product p3 = new Product("Sneakers Adibas", "INCALTAMINTE", 350);
		Product p4 = new Product("Sneakers Nike", "INCALTAMINTE", 250);
		
		ShoppingCart cart = new ShoppingCart();
		
		cart.addProduct(p1);
		cart.addProduct(p2);
		cart.addProduct(p3);
		cart.addProduct(p4);
		
		for(Product p : cart.getSelectedProducts()) {
			System.out.println(p.getProductName() + " - " + p.getPrice());
		}
		
		System.out.println();
		
		//Collections.sort(cart.getSelectedProducts());
		cart.getSelectedProducts().sort(null);
		
		for(Product p : cart.getSelectedProducts()) {
			System.out.println(p.getProductName() + " - " + p.getPrice());
		}
		
		Map<String, Integer> stocks = new HashMap<>();
		for(Product p : cart.getSelectedProducts()) {
			if(stocks.containsKey(p.getCategory())) {
				stocks.put(p.getCategory(), stocks.get(p.getCategory()) + 1);
			} else {
				stocks.put(p.getCategory(), 1);
			}
		}
		
		System.out.println();
		
		for(Entry<String, Integer> entry : stocks.entrySet()) {
			System.out.println(entry.getKey() + ": " + entry.getValue());
		}
		
		Set<Product> uniqueProducts = new HashSet<Product>();
		uniqueProducts.add(p1);
		uniqueProducts.add(p2);
		uniqueProducts.add(p3);
		uniqueProducts.add(p4);
		System.out.println();
		System.out.println("-------SET-------");
		for(Product p : uniqueProducts) {
			System.out.println(p.getProductName() + " - " + p.getPrice());
		}
	}
}