package server;

import java.io.*;
import java.net.*;
import java.util.*;
import java.text.SimpleDateFormat;

public class Mainserver {
    
	public static void main(String[] args) throws Exception{
		
		try{
			//Make serverSocket port#6789
			ServerSocket serverSocket = new ServerSocket(6789);
			
			//definition requestCode and responseCode
			String requestCode;
			String responseCode="Connect Complete";
			
			while(true)
			{	//wait for connect
				Socket socket = serverSocket.accept();
				//print client information
				System.out.println(getTime()+socket.getInetAddress()+" want connection"+'\n');
				//make Stream
			    DataInputStream in;
			   	DataOutputStream out;
			   	out = new DataOutputStream(socket.getOutputStream());
   				in = new DataInputStream(socket.getInputStream());
   				BufferedReader inFromClient = new BufferedReader(new InputStreamReader(socket.getInputStream()));
   				
   				//receive requestCode
   				requestCode = inFromClient.readLine();
	   			System.out.println(requestCode);
	   			// normal requestCode
	   			if(requestCode!=null)
	   			{
	   			out.writeUTF(responseCode+'\n');
	   			//make thread
				MyThread thread = new MyThread(socket);
				thread.start();
	   			}
	   			//if requestCode is null
	   			else
	   			{
	   				serverSocket.close();
	   			}
			} 
		}catch(IOException e){
			e.printStackTrace();
		}
    }

//get current time
static String getTime() {
	SimpleDateFormat f = new SimpleDateFormat("[hh:mm:ss]");
	return f.format(new Date());
}
}

// make thread extends Thread
class MyThread extends Thread {
    Socket socket;
    DataInputStream in;
   	DataOutputStream out;
   	// initialize Account information
   	static class Account{
   		public static String name1="Kim";
   		public static String name2="Ham";
   		public static String name3="Lee";
   		public static String name4="Park";
   		public static String name5="Choi";
   		public static String balance1="50";
   		public static String balance2="30";
   		public static String balance3="100";
   		public static String balance4="50";
   		public static String balance5="40";
   	}
    	
   	public MyThread(Socket socket)
   	{
   		this.socket = socket;
   		try {
   			in = new DataInputStream(socket.getInputStream());
   			out = new DataOutputStream(socket.getOutputStream());
   		} catch(Exception e) {
   			e.printStackTrace();
   		}
   	}
   	
   	public void run() {
   		while(true) {
   			try {	
				out = new DataOutputStream(socket.getOutputStream());
   				in = new DataInputStream(socket.getInputStream());
   				BufferedReader inFromClient = new BufferedReader(new InputStreamReader(socket.getInputStream()));
   				String operation;
   				String name;
   				
   				out.writeUTF("What do you want to do?"+'\n');
   				while(in!=null)
   	   			{
   					//input operation
   	   				operation = inFromClient.readLine();
   	   				System.out.println(operation);
   	   				//Check operation
   	   				//Just show Account balance
   	   				if(operation.equals("Check"))
   					{
   	    				out.writeUTF("Who?"+'\n');
   	    				while(in!=null)
   	   					{
   	    					name = inFromClient.readLine();
   	   						if(name.equals("Kim"))
   	   						{
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
   	   							String money = Account.balance1;
   	   							out.writeUTF(money);
   	   							}
   	   							continue;
   	   						}
   	   						else if(name.equals("Ham"))
   	   						{
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
   	   							String money = Account.balance2;
	   							out.writeUTF(money);
	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Lee"))
   	   						{
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
   	   							String money = Account.balance3;
	   							out.writeUTF(money);
	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Park"))
   	   						{
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
   	   							String money = Account.balance4;
	   							out.writeUTF(money);
	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Choi"))
   	   						{
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
   	   							String money = Account.balance5;
	   							out.writeUTF(money);
	   							continue;
   	   							}
   	   						}
   	   						// client wants to exit
   	   						else if(name.equals("exit"))
   	   						{
   	   							out.writeUTF("exit"+'\n');
   	   							break;
   	   						}
   	   						//error occur
   	   						else
   	   						{
   	   							out.writeUTF("error"+'\n');
   	   						}
   	   					}
   					}
   	   				// Deposit operation
					// sum Account balance and money and change information of Account
   					else if(operation.equals("Deposit"))
   					{
   						out.writeUTF("To Who?"+'\n');
   						while(in!=null)
   	   					{
   	    					name = inFromClient.readLine();
   	    					String much="";
   	   						if(name.equals("Kim"))
   	   						{
   	   							out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
   	   							much = inFromClient.readLine();
   	   							String money = Account.balance1;
   	   							int result1 =Integer.parseInt(much)+Integer.parseInt(money);
   	   							String result2 = Integer.toString(result1);
   	   							Account.balance1=result2;
   	   							out.writeUTF("Kim now has "+Account.balance1+'\n');
   	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Ham"))
   	   						{
   	   						    out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
	   							much = inFromClient.readLine();
	   							String money = Account.balance2;
	   							int result1 =Integer.parseInt(much)+Integer.parseInt(money);
	   							String result2 = Integer.toString(result1);
	   							Account.balance2=result2;
	   							out.writeUTF("Ham now has "+Account.balance2+'\n');
   	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Lee"))
   	   						{
   	   						    out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
	   							much = inFromClient.readLine();
	   							String money = Account.balance3;
	   							int result1 =Integer.parseInt(much)+Integer.parseInt(money);
	   							String result2 = Integer.toString(result1);
	   							Account.balance3=result2;
	   							out.writeUTF("Lee now has "+Account.balance3+'\n');
   	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Park"))
   	   						{
   	   						    out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
	   							much = inFromClient.readLine();
	   							String money = Account.balance4;
	   							int result1 =Integer.parseInt(much)+Integer.parseInt(money);
	   							String result2 = Integer.toString(result1);
	   							Account.balance4=result2;
	   							out.writeUTF("Park now has "+Account.balance4+'\n');
   	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Choi"))
   	   						{
   	   						    out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
	   							much = inFromClient.readLine();
	   							String money = Account.balance5;
	   							int result1 =Integer.parseInt(much)+Integer.parseInt(money);
	   							String result2 = Integer.toString(result1);
	   							Account.balance5=result2;
	   							out.writeUTF("Choi now has "+Account.balance5+'\n');
   	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("exit"))
   	   						{
   	   							out.writeUTF("exit"+'\n');
   	   							break;
   	   						}
   	   						else
   	   						{
   	   							out.writeUTF("error"+'\n');
   	   						}
   	   					}
   					}
   	   				// Withdraw operation
   	   				//withdraw money from Account balance and update information
   					else if(operation.equals("Withdraw"))
   					{
   						out.writeUTF("From Who?"+'\n');
   						while(in!=null)
   	   					{
   	    					name = inFromClient.readLine();
   	    					String much="";
   	   						if(name.equals("Kim"))
   	   						{
   	   							out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
   	   							much = inFromClient.readLine();
   	   							String money = Account.balance1;
   	   							if((Integer.parseInt(money))<(Integer.parseInt(much)))
   	   							{
   	   	   							out.writeUTF("Kim money lack"+'\n');
   	   	   							break;
   	   							}
   	   							int result1 =Integer.parseInt(money)-Integer.parseInt(much);
   	   							String result2 = Integer.toString(result1);
   	   							Account.balance1=result2;
   	   							out.writeUTF("Kim now has "+Account.balance1+'\n');
   	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Ham"))
   	   						{
   	   							out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
	   							much = inFromClient.readLine();
	   							String money = Account.balance2;
	   							if((Integer.parseInt(money))<(Integer.parseInt(much)))
	   							{
	   	   							out.writeUTF("Ham money lack"+'\n');
	   	   							break;
	   							}
	   							int result1 =Integer.parseInt(money)-Integer.parseInt(much);
	   							String result2 = Integer.toString(result1);
	   							Account.balance2=result2;
	   							out.writeUTF("Ham now has "+Account.balance2+'\n');
	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Lee"))
   	   						{
   	   							out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
	   							much = inFromClient.readLine();
	   							String money = Account.balance3;
	   							if((Integer.parseInt(money))<(Integer.parseInt(much)))
	   							{
	   	   							out.writeUTF("Lee money lack"+'\n');
	   	   							break;
	   							}
	   							int result1 =Integer.parseInt(money)-Integer.parseInt(much);
	   							String result2 = Integer.toString(result1);
	   							Account.balance3=result2;
	   							out.writeUTF("Lee now has "+Account.balance3+'\n');
	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Park"))
   	   						{
   	   							out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
	   							much = inFromClient.readLine();
	   							String money = Account.balance4;
	   							if((Integer.parseInt(money))<(Integer.parseInt(much)))
	   							{
	   	   							out.writeUTF("Park money lack"+'\n');
	   	   							break;
	   							}
	   							int result1 =Integer.parseInt(money)-Integer.parseInt(much);
	   							String result2 = Integer.toString(result1);
	   							Account.balance4=result2;
	   							out.writeUTF("Park now has "+Account.balance4+'\n');
	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Choi"))
   	   						{
   	   							out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
	   							much = inFromClient.readLine();
	   							String money = Account.balance5;
	   							if((Integer.parseInt(money))<(Integer.parseInt(much)))
	   							{
	   	   							out.writeUTF("Choi money lack"+'\n');
	   	   							break;
	   							}
	   							int result1 =Integer.parseInt(money)-Integer.parseInt(much);
	   							String result2 = Integer.toString(result1);
	   							Account.balance5=result2;
	   							out.writeUTF("Choi now has "+Account.balance5+'\n');
	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("exit"))
   	   						{
   	   							out.writeUTF("exit"+'\n');
   	   							break;
   	   						}
   	   						else
   	   						{
   	   							out.writeUTF("error"+'\n');
   	   						}
   	   					}
   					}
   	   				//Trans operation
   	   				//Transfer money from one's Account to the other Account balance and update information
   					else if(operation.equals("Trans"))
   					{
   						out.writeUTF("From Who?"+'\n');
   						while(in!=null)
   	   					{
   	    					name = inFromClient.readLine();
   	    					String much="";
   	   						if(name.equals("Kim"))
   	   						{
   	   							out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
   	   							much = inFromClient.readLine();
   	   							String money = Account.balance1;
   	   							if((Integer.parseInt(money))<(Integer.parseInt(much)))
   	   							{
   	   	   							out.writeUTF("Kim money lack"+'\n');
   	   	   							break;
   	   							}
   	   							out.writeUTF("To who?"+'\n');
   	   							name = inFromClient.readLine();
   	   							String toMoney="";
   	   							if(name.equals("Ham")) {
   	   								toMoney=Account.balance2;
   	   							}
   	   							else if(name.equals("Lee")){
   	   								toMoney=Account.balance3;
   	   							}
   	   							else if(name.equals("Park")){
   	   								toMoney=Account.balance4;
   	   							}
   	   							else if(name.equals("Choi")){
   	   								toMoney=Account.balance5;
   	   							}
   	   							else {
   	   								out.writeUTF("error"+'\n');
   	   								break;
   	   							}
   	   							int result1 =Integer.parseInt(money)-Integer.parseInt(much);
   	   							int result2 = Integer.parseInt(toMoney)+Integer.parseInt(much);
   	   							String result3 = Integer.toString(result1);
   	   							String result4 = Integer.toString(result2);
   	   							Account.balance1=result3;
   	   							out.writeUTF("Kim now has "+Account.balance1+'\n');
   	   							if(name.equals("Ham")) {
	   								Account.balance2=result4;
	   							}
	   							else if(name.equals("Lee")){
	   								Account.balance3=result4;
	   							}
	   							else if(name.equals("Park")){
	   								Account.balance4=result4;
	   							}
	   							else if(name.equals("Choi")){
	   								Account.balance5=result4;
	   							}
	   							else {
	   								out.writeUTF("error"+'\n');
	   								break;
	   							}
   	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Ham"))
   	   						{
   	   							out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
   	   							much = inFromClient.readLine();
   	   							String money = Account.balance2;
   	   							if((Integer.parseInt(money))<(Integer.parseInt(much)))
   	   							{
   	   	   							out.writeUTF("Ham money lack"+'\n');
   	   	   							break;
   	   							}
   	   							out.writeUTF("To who?"+'\n');
   	   							name = inFromClient.readLine();
   	   							String toMoney="";
   	   							if(name.equals("Kim")) {
   	   								toMoney=Account.balance1;
   	   							}
   	   							else if(name.equals("Lee")){
   	   								toMoney=Account.balance3;
   	   							}
   	   							else if(name.equals("Park")){
   	   								toMoney=Account.balance4;
   	   							}
   	   							else if(name.equals("Choi")){
   	   								toMoney=Account.balance5;
   	   							}
   	   							else {
   	   								out.writeUTF("error"+'\n');
   	   								break;
   	   							}
   	   							int result1 =Integer.parseInt(money)-Integer.parseInt(much);
   	   							int result2 = Integer.parseInt(toMoney)+Integer.parseInt(much);
   	   							String result3 = Integer.toString(result1);
   	   							String result4 = Integer.toString(result2);
   	   							Account.balance2=result3;
   	   							out.writeUTF("Ham now has "+Account.balance2+'\n');
   	   							if(name.equals("Kim")) {
	   								Account.balance1=result4;
	   							}
	   							else if(name.equals("Lee")){
	   								Account.balance3=result4;
	   							}
	   							else if(name.equals("Park")){
	   								Account.balance4=result4;
	   							}
	   							else if(name.equals("Choi")){
	   								Account.balance5=result4;
	   							}
	   							else {
	   								out.writeUTF("error"+'\n');
	   								break;
	   							}
   	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Lee"))
   	   						{
   	   							out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
   	   							much = inFromClient.readLine();
   	   							String money = Account.balance3;
   	   							if((Integer.parseInt(money))<(Integer.parseInt(much)))
   	   							{
   	   	   							out.writeUTF("Lee money lack"+'\n');
   	   	   							break;
   	   							}
   	   							out.writeUTF("To who?"+'\n');
   	   							name = inFromClient.readLine();
   	   							String toMoney="";
   	   							if(name.equals("Ham")) {
   	   								toMoney=Account.balance2;
   	   							}
   	   							else if(name.equals("Kim")){
   	   								toMoney=Account.balance1;
   	   							}
   	   							else if(name.equals("Park")){
   	   								toMoney=Account.balance4;
   	   							}
   	   							else if(name.equals("Choi")){
   	   								toMoney=Account.balance5;
   	   							}
   	   							else {
   	   								out.writeUTF("error"+'\n');
   	   								break;
   	   							}
   	   							int result1 =Integer.parseInt(money)-Integer.parseInt(much);
   	   							int result2 = Integer.parseInt(toMoney)+Integer.parseInt(much);
   	   							String result3 = Integer.toString(result1);
   	   							String result4 = Integer.toString(result2);
   	   							Account.balance3=result3;
   	   							out.writeUTF("Lee now has "+Account.balance3+'\n');
   	   							if(name.equals("Ham")) {
	   								Account.balance2=result4;
	   							}
	   							else if(name.equals("Kim")){
	   								Account.balance1=result4;
	   							}
	   							else if(name.equals("Park")){
	   								Account.balance4=result4;
	   							}
	   							else if(name.equals("Choi")){
	   								Account.balance5=result4;
	   							}
	   							else {
	   								out.writeUTF("error"+'\n');
	   								break;
	   							}
   	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("Park"))
	   						{
	   							out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
	   							much = inFromClient.readLine();
	   							String money = Account.balance4;
	   							if((Integer.parseInt(money))<(Integer.parseInt(much)))
	   							{
	   	   							out.writeUTF("Park money lack"+'\n');
	   	   							break;
	   							}
	   							out.writeUTF("To who?"+'\n');
	   							name = inFromClient.readLine();
	   							String toMoney="";
	   							if(name.equals("Ham")) {
	   								toMoney=Account.balance2;
	   							}
	   							else if(name.equals("Lee")){
	   								toMoney=Account.balance3;
	   							}
	   							else if(name.equals("Kim")){
	   								toMoney=Account.balance1;
	   							}
	   							else if(name.equals("Choi")){
	   								toMoney=Account.balance5;
	   							}
	   							else {
	   								out.writeUTF("error"+'\n');
	   								break;
	   							}
	   							int result1 =Integer.parseInt(money)-Integer.parseInt(much);
	   							int result2 = Integer.parseInt(toMoney)+Integer.parseInt(much);
	   							String result3 = Integer.toString(result1);
	   							String result4 = Integer.toString(result2);
	   							Account.balance4=result3;
	   							out.writeUTF("Park now has "+Account.balance4+'\n');
	   							
	   							if(name.equals("Ham")) {
   								Account.balance2=result4;
	   							}
	   							else if(name.equals("Lee")){
   								Account.balance3=result4;
	   							}
	   							else if(name.equals("Kim")){
   								Account.balance1=result4;
	   							}
	   							else if(name.equals("Choi")){
   								Account.balance5=result4;
	   							}
	   							else {
	   								out.writeUTF("error"+'\n');
	   								break;
	   							}
	   								continue;
   	   							}
	   						}
   	   						else if(name.equals("Choi"))
   	   						{
   	   							out.writeUTF("How much?"+'\n');
   	   							//synchronized Account balance
   	   							synchronized(this)
   	   							{
   	   							much = inFromClient.readLine();
   	   							String money = Account.balance5;
   	   							if((Integer.parseInt(money))<(Integer.parseInt(much)))
   	   							{
   	   	   							out.writeUTF("Choi money lack"+'\n');
   	   	   							break;
   	   							}
   	   							out.writeUTF("To who?"+'\n');
   	   							name = inFromClient.readLine();
   	   							String toMoney="";
   	   							if(name.equals("Ham")) {
   	   								toMoney=Account.balance2;
   	   							}
   	   							else if(name.equals("Lee")){
   	   								toMoney=Account.balance3;
   	   							}
   	   							else if(name.equals("Park")){
   	   								toMoney=Account.balance4;
   	   							}
   	   							else if(name.equals("Kim")){
   	   								toMoney=Account.balance1;
   	   							}
   	   							else {
   	   								out.writeUTF("error"+'\n');
   	   								break;
   	   							}
   	   							int result1 =Integer.parseInt(money)-Integer.parseInt(much);
   	   							int result2 = Integer.parseInt(toMoney)+Integer.parseInt(much);
   	   							String result3 = Integer.toString(result1);
   	   							String result4 = Integer.toString(result2);
   	   							Account.balance5=result3;
   	   							out.writeUTF("Choi now has "+Account.balance5+'\n');
   	   							if(name.equals("Ham")) {
	   								Account.balance2=result4;
	   							}
	   							else if(name.equals("Lee")){
	   								Account.balance3=result4;
	   							}
	   							else if(name.equals("Park")){
	   								Account.balance4=result4;
	   							}
	   							else if(name.equals("Kim")){
	   								Account.balance1=result4;
	   							}
	   							else {
	   								out.writeUTF("error"+'\n');
	   								break;
	   							}
   	   							continue;
   	   							}
   	   						}
   	   						else if(name.equals("exit"))
   	   						{
   	   							out.writeUTF("exit"+'\n');
   	   							break;
   	   						}
   	   						else
   	   						{
   	   							out.writeUTF("error"+'\n');
   	   						}
   	   					}
   					}
   					else
   					{
   						out.writeUTF("error"+'\n');
   					}
   	   			}
   			
   			} catch (IOException e)
   			{
   				e.printStackTrace();
   			}
   		}
   	}
}   	














