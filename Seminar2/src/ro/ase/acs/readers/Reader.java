package ro.ase.acs.readers;

import java.io.Closeable;
import java.io.IOException;
import java.util.Scanner;


public class Reader implements Closeable, ro.ase.acs.contracts.Readable{
	private Scanner scanner=new Scanner(System.in);
	
	public String read() {	
		System.out.print("Message: ");
		String message=scanner.nextLine();
		return message;
	}

	@Override
	public void close() throws IOException {
		// TODO Auto-generated method stub
		scanner.close();
		
	}

}
