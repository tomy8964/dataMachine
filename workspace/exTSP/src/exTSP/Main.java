package exTSP;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.Date;
/*
sample input(ù ��° ���ڴ� ����� ����, �� ��° ���ڴ� ������ ���� �̴�).
2
5
8
0 1 5
0 4 1
0 2 7
0 3 2
1 2 3
1 3 6
2 3 10
3 4 4
 */
public class Main {
	static int N, M, S, F,allNum;
	static int[][] dist;
	static String[][] path;

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		String today = null;
	    
	    Date date = new Date();
	     
	     
	    // ���˺��� ( ����� �ú���)
	    SimpleDateFormat sdformat = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss"); 
	     
	    // Java �ð� ���ϱ�
	     
	    Calendar cal = Calendar.getInstance();
	     
	    cal.setTime(date);
		
		// �ʱ�ȭ
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// �� ������ ��
		allNum = Integer.parseInt(br.readLine());
		// �� ���� ��
		N = Integer.parseInt(br.readLine());
		// �� ���� ��
		M = Integer.parseInt(br.readLine());
		// �÷��̵� �ʱ� �Ÿ� ���̺� �ʱ�ȭ
		dist = new int[N][N];
		path = new String[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// �ڱ� �ڽ����� ���� ���� �ּ� ����� 0�̴�.
				if (i == j) {
					dist[i][j] = 0;
					continue;
				}
				// �ڱ� �ڽ����� ���� ��츦 �����ϰ�� �ſ� ū ��(N���� ��带 ��� ���ļ� ������ �� ū ��).
				dist[i][j] = 100_000_000;
			}
		}

		for (int i = 0; i < M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());

			// ���� ��ΰ� �ϳ��� �ƴ� �� �ִ�. ���� �� �� �ּ� ����� �����صθ� �ȴ�.
			dist[a][b] = Math.min(dist[a][b], cost);
			dist[b][a] = Math.min(dist[b][a], cost);
			// i���� j�� ���� ��� ����
			String aString = Integer.toString(a);
			String bString = Integer.toString(b);
			path[a][b]=aString+bString;
		}

		// �÷��̵� ���� �˰���
		// ��带 1������ N������ ���İ��� ��츦 ��� ����Ѵ�.
		for (int k = 0; k < N; k++) {
			// ��� i���� j�� ���� ���.
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					// k��° ��带 ���İ��� ����� ���� ��뺸�� �� ���� ��� ����
					// �Ǵ� ������ �ȵǾ��ִ� ���(INF) ���� ��� ����.
					// i���� j�� ���� ��� ����
					if(k==0)
					{
					if(dist[i][j]>(dist[i][k] + dist[k][j]))
					{
					String iString = Integer.toString(i);
					String jString = Integer.toString(j);
					String kString = Integer.toString(k);
						if(i==k)
						{
							if(k==j)
							{
								path[i][j]=iString;
							}
							else
							{
								path[i][j]=iString+'-'+jString;					
							}
						}
						else if(k==j)
						{
							if(i==j)
							{
								path[i][j]=iString;
							}
							path[i][j]=iString+'-'+jString;	
						}
						else
						{
							path[i][j]=iString+'-'+kString+'-'+jString;
						}
					}
					else
					{
						String iString = Integer.toString(i);
						String jString = Integer.toString(j);
						if(i==j)
						{
							path[i][j]=iString;					
						}
						else
						{
							path[i][j]=iString+'-'+jString;
						}
					}
					}
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		// ���
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// ������ �ȵǾ� �ִ� ���
				if (dist[i][j] == 100_000_000) {
					System.out.print("INF ");
				} else {
					System.out.print(dist[i][j] + " ");
				}
			}
			System.out.println();
		}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			// ������ �ȵǾ� �ִ� ���
			if (dist[i][j] == 100_000_000) {
				System.out.print("INF ");
			} else {
				System.out.print(path[i][j] + " ");
			}
		}
		System.out.println();
	}
	
	
	
	for(int R=0;R<allNum;R++)
	{
	
		int last = allNum-R;
		System.out.println("���� ��� �� : " + last+" ��");
		S = Integer.parseInt(br.readLine());
		F = Integer.parseInt(br.readLine());
		
	    System.out.println("���� ��� : " + path[S][F]);   // gui
	  
	    today = sdformat.format(cal.getTime());  
	    System.out.println("���� �ð� : " + today); // gui
	    
	    System.out.println("�ҿ� �ð� : " + dist[S][F]+"�ð�");
	    cal.add(cal.HOUR,dist[S][F]);
	    
	    today = sdformat.format(cal.getTime()); 
	    System.out.println("��� ����ð� : "+today);// gui
	
	    int random;
	    random = (int)(Math.random() * (5)) + 1;
	    
	    if(random == 1) {   // ���������� 1�� ������ ��� �߻��ߴ� �����ϰ� �ڽ�Ʈ �������� �����Ͽ� ��� ��Ž��
	        
	        int randomdest1,randomdest2,randomcost;
	        
	        randomdest1 = (int)(Math.random() * (N)) + 0;
	        randomdest2 = (int)(Math.random() * (N)) + 0;
	        while(randomdest1 == randomdest2) {
	           randomdest1 = (int)(Math.random() * (N)) + 0;
	           randomdest2 = (int)(Math.random() * (N)) + 0;
	        }
	        randomcost = (int)(Math.random() * (120)) + 10;   
	       
	        dist[randomdest1][randomdest2] += randomcost;
	        cal.add(cal.HOUR,-dist[S][F]);
	        
	        System.out.println(randomdest1+"-"+randomdest2+"�� ��� �߻��߽��ϴ�! ��θ� ��Ž�� ���Դϴ�.....");
	        System.out.println("��� �߻��߽��ϴ�! ��θ� ��Ž�� ���Դϴ�....."); // gui
	        R--;
	        
	        // �÷��̵� ���� �˰���
			// ��带 1������ N������ ���İ��� ��츦 ��� ����Ѵ�.
			for (int k = 0; k < N; k++) {
				// ��� i���� j�� ���� ���.
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						// k��° ��带 ���İ��� ����� ���� ��뺸�� �� ���� ��� ����
						// �Ǵ� ������ �ȵǾ��ִ� ���(INF) ���� ��� ����.
						// i���� j�� ���� ��� ����
						if(k==0)
						{
						if(dist[i][j]>(dist[i][k] + dist[k][j]))
						{
						String iString = Integer.toString(i);
						String jString = Integer.toString(j);
						String kString = Integer.toString(k);
							if(i==k)
							{
								if(k==j)
								{
									path[i][j]=iString;
								}
								else
								{
									path[i][j]=iString+'-'+jString;					
								}
							}
							else if(k==j)
							{
								if(i==j)
								{
									path[i][j]=iString;
								}
								path[i][j]=iString+'-'+jString;	
							}
							else
							{
								path[i][j]=iString+'-'+kString+'-'+jString;
							}
						}
						else
						{
							String iString = Integer.toString(i);
							String jString = Integer.toString(j);
							if(i==j)
							{
								path[i][j]=iString;					
							}
							else
							{
								path[i][j]=iString+'-'+jString;
							}
						}
						}
						dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
					}
				}
			}
	     
     }
	}
	System.out.println("����� �Ϸ��Ͽ����ϴ�");
	System.out.println("���� �ð� : "+today);
	}
}