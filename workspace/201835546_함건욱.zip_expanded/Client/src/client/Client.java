package client;

import java.net.*;
import java.text.SimpleDateFormat;
import java.io.*;
import java.util.*;

public class Client {
	public static void main(String args[]) {
		try {
			//get file
			File file = new File(".\\server.txt");
			FileReader filereader = new FileReader(file);
			BufferedReader bufReader = new BufferedReader(filereader);
			//use to save information of file
			String line[]={"asdf","asdf"};
			
			//input information of file to line
			for(int i=0;i<2;i++) {
				line[i]=bufReader.readLine();
			}
			
			// first line is server ip address and second line is server port num
			String serverIP=line[0];
			String portN=line[1];
			int portNum=Integer.parseInt(portN);
			bufReader.close();
			
			// request connection
			Socket socket = new Socket(serverIP, portNum); 
			
			// make Stream
			Scanner scanner = new Scanner(System.in);
			DataInputStream in=null;
		   	DataOutputStream out=null;
			in = new DataInputStream(socket.getInputStream());
			out = new DataOutputStream(socket.getOutputStream());
   			PrintWriter outToServer = new PrintWriter(out,true);
   			
   			//input user name
   			String username="";
   			System.out.println("Enter your name");
   			username = scanner.nextLine();
   			
   			//make requestCode
   			String requestCode;
   			requestCode= username+getTime()+socket.getInetAddress();
   			
   			//sent requestCode to server
   			outToServer.println(requestCode);
   			System.out.println(in.readUTF());
   			
   			//loop for talk to server
   			while(in!=null)
   			{ 
   				System.out.println(in.readUTF());
   				outToServer.println(scanner.nextLine()); 
   			}
			// close if finish
   			scanner.close();
   			socket.close();
		} catch(ConnectException ce) {
			ce.printStackTrace();
		} catch(IOException ie) {
			ie.printStackTrace();
		} catch(Exception e) {
			e.printStackTrace();  
		}  
	} // main
	
	// to get current time
	static String getTime() {
		SimpleDateFormat f = new SimpleDateFormat("[hh:mm:ss]");
		return f.format(new Date());
		}
	}
