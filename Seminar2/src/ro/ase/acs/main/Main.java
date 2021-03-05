package ro.ase.acs.main;

import ro.ase.acs.readers.Reader;
import ro.ase.acs.writers.ConsoleWriter;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

import ro.ase.acs.contracts.Readable;
import ro.ase.acs.contracts.Writeable;

public class Main {
	
	public static void main(String[] args) {
		IoC ioc=new IoC();
		ioc.register(Readable.class,Reader.class);
		ioc.register(Writeable.class, ConsoleWriter.class);
		
		Class<?> readerClass=ioc.resolve(Readable.class);
		Class<?> consoleWriterClass=ioc.resolve(Writeable.class);
		
		Constructor<?> readerConstructor=null;
		Constructor<?> consoleWriterConstructor=null;
		
		try {
			readerConstructor= readerClass.getConstructor();
			consoleWriterConstructor=consoleWriterClass.getConstructor();
		} catch (NoSuchMethodException e) {
			e.printStackTrace();
		} catch (SecurityException e) {
			e.printStackTrace();
		}
		
		Orchestrator orchestrator=null;
		try {
			orchestrator = new Orchestrator((Reader)readerConstructor.newInstance(),(ConsoleWriter)consoleWriterConstructor.newInstance());
			
		} catch (InstantiationException | IllegalAccessException | IllegalArgumentException
				| InvocationTargetException e) {

			e.printStackTrace();
		}
		orchestrator.execute();
	}
}
