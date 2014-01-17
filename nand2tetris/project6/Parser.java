package assembler;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

public class Parser {
	private int index = 0;
	private int val = 1;
	private File file = null;
	private BufferedReader reader = null;
	private BufferedWriter writer = null;
	private String strLine;
	private String str;
	private char[] tmp = new char[1];
	private char[] std = new char[16];
	private char[] cmd = new char[1];
	private HashMap<String, Integer> symbol = new HashMap<String, Integer>();
	private HashMap<String, String> comp = new HashMap<String, String>();
	private HashMap<String, String> dest = new HashMap<String, String>();
	private HashMap<String, String> jump = new HashMap<String, String>();
	

	public Parser(String fileName) {		 
		file = new File(fileName);
		try {
			reader = new BufferedReader(new FileReader(file));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		try {
			writer = new BufferedWriter(new FileWriter("D:/nand2tetris/projects/06/pong/Pong1.hack"));
		} catch (IOException e) {
			e.printStackTrace();
		}
		comp.put("0", "0101010");
		comp.put("1", "0111111");
		comp.put("-1", "0111010");
		comp.put("D", "0001100");
		comp.put("A", "0110000");
		comp.put("!D", "0001101");
		comp.put("!A", "0110001");
		comp.put("-D", "0001111");
		comp.put("-A", "0110011");
		comp.put("D+1", "0011111");
		comp.put("A+1", "0110111");
		comp.put("D-1", "0001110");
		comp.put("A-1", "0110010");
		comp.put("D+A", "0000010");
		comp.put("D-A", "0010011");
		comp.put("A-D", "0000111");
		comp.put("D&A", "0000000");
		comp.put("D|A", "0010101");
		comp.put("M", "1110000");
		comp.put("!M", "1110001");
		comp.put("-M", "1110011");
		comp.put("M+1", "1110111");
		comp.put("M-1", "1110010");
		comp.put("D+M", "1000010");
		comp.put("D-M", "1010011");
		comp.put("M-D", "1000111");
		comp.put("D&M", "1000000");
		comp.put("D|M", "1010101");
		
		dest.put("M", "001");
		dest.put("D", "010");
		dest.put("MD", "011");
		dest.put("A", "100");
		dest.put("AM", "101");
		dest.put("AD", "110");
		dest.put("AMD", "111");
		
		jump.put("JGT", "001");
		jump.put("JEQ", "010");
		jump.put("JGE", "011");
		jump.put("JLT", "100");
		jump.put("JNE", "101");
		jump.put("JLE", "110");
		jump.put("JMP", "111");
		
	}
	
	public Boolean hasMoreCommands() {
		for(int i=0; i < std.length; i++)
			std[i] = '0';
		try {
			if((strLine = reader.readLine()) != null) return true;
		} catch (IOException e) {
			e.printStackTrace();
		}
		return false;
	}
	
	public void storeValue() {
		symbol.put("R0", 0);
		symbol.put("R1", 1);
		symbol.put("R2", 2);
		symbol.put("R3", 3);
		symbol.put("R4", 4);
		symbol.put("R5", 5);
		symbol.put("R6", 6);
		symbol.put("R7", 7);
		symbol.put("R8", 8);
		symbol.put("R9", 9);
		symbol.put("R10", 10);
		symbol.put("R11", 11);
		symbol.put("R12", 12);
		symbol.put("R13", 13);
		symbol.put("R14", 14);
		symbol.put("R15", 15);
		symbol.put("SP", 0);
		symbol.put("LCL", 1);
		symbol.put("ARG", 2);
		symbol.put("THIS", 3);
		symbol.put("THAT", 4);
		symbol.put("SCREEN", 16384);
		symbol.put("KBD", 24576);
		
		while(hasMoreCommands()) {
			str = strLine.replaceAll("\\s+", "");
			cmd = str.toCharArray();
			index++;
			if(cmd[0] == '('){
				index--;
				LCmd(str.substring(1, str.length()-1));
			}
			if(cmd[0] == '/')
				index--;
		}
	}
	
	public void parseFile() {
		storeValue();
		try {
			reader.close();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		try {
			reader = new BufferedReader(new FileReader(file));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		while(hasMoreCommands()) {
				str = strLine.replaceAll("\\s+", "");
				cmd = str.toCharArray();
				switch(cmd[0]) {
				case '/':	{
								System.out.println("The comments are:\n" + str.substring(2)); 
								break;
							}
				case '@':	{
								ACmd(str.substring(1));
								break;
							}
				case '(':	{
								break;
							}
				default:	{
								CCmd(str);
								break;
							}
				}
			}
			try {
				reader.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				writer.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	
	public void CCmd(String str) {
		String compstr = "";
		String jumpstr = "";
		String string = "";
		String[] c = str.split("//");
		String[] s = c[0].split("=");
		if(s.length == 1) {
			String[] ss = s[0].split(";");
			compstr = comp.get(ss[0]);
			jumpstr = jump.get(ss[1]);
			tmp = compstr.toCharArray();
			for(int i = 0; i < tmp.length; i++) {
				std[i + 3] = tmp[i];
			}
			tmp = jumpstr.toCharArray();
			for(int i = 0; i < tmp.length; i++) {
				std[i + 13] = tmp[i];
			}
		}
		else {
			string += comp.get(s[1]) + dest.get(s[0]);
			tmp = string.toCharArray();
			for(int i = 0; i < tmp.length; i++)
				std[i + 3] = tmp[i];
		}
		
		for(int i = 0; i < 3; i++)
			std[i] = '1';
		
		for(int i = 0; i < std.length; i++)
			write(std[i]);
		
		try {
			writer.newLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void ACmd(String str) {
		String s;
		System.out.println(str);
		if(str.charAt(0) < 48 || str.charAt(0) > 57) {
			if(symbol.containsKey(str))
				s = Integer.toBinaryString(symbol.get(str));
			else {
				symbol.put(str, 15 + val);
				s = Integer.toBinaryString(15 + val);
				val++;
			}
		}
		else
			s= Integer.toBinaryString(Integer.parseInt(str));
		
		System.out.println(s);
		tmp = s.toCharArray();
		for(int i = 0; i < tmp.length; i++) {
			std[std.length - tmp.length + i] = tmp[i];
		}	
		for(int i=0; i < std.length; i++)
			write(std[i]);
		try {
			writer.newLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void LCmd(String str) {
		if(!symbol.containsKey(str)) symbol.put(str, index);
		else return;
	}
	
	public void write(char c) {
		try {
			writer.write(c);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		
		Parser paser = new Parser("D:/nand2tetris/projects/06/pong/Pong.asm");
		paser.parseFile();
		
	}

}
