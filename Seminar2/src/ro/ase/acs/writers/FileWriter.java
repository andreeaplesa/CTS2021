package ro.ase.acs.writers;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;

public class FileWriter extends ConsoleWriter{

	@Override
	public void print(String message) {
		OutputStreamWriter osWriter=null;
		try {
			FileOutputStream fileOutputStream= new FileOutputStream("output.txt");
			osWriter=new OutputStreamWriter(fileOutputStream);
			osWriter.write(message);
		}catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally {
			if(osWriter!=null) {
				try {
					osWriter.close();
				}catch(IOException e) {
					e.printStackTrace();
				}
			}
		}
	}

}
