package exTSP;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.Date;
/*
sample input(첫 번째 숫자는 노드의 개수, 두 번째 숫자는 간선의 개수 이다).
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
	     
	     
	    // 포맷변경 ( 년월일 시분초)
	    SimpleDateFormat sdformat = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss"); 
	     
	    // Java 시간 더하기
	     
	    Calendar cal = Calendar.getInstance();
	     
	    cal.setTime(date);
		
		// 초기화
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// 총 목적지 수
		allNum = Integer.parseInt(br.readLine());
		// 총 도시 수
		N = Integer.parseInt(br.readLine());
		// 총 도로 수
		M = Integer.parseInt(br.readLine());
		// 플로이드 초기 거리 테이블 초기화
		dist = new int[N][N];
		path = new String[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 자기 자신으로 가는 길은 최소 비용이 0이다.
				if (i == j) {
					dist[i][j] = 0;
					continue;
				}
				// 자기 자신으로 가는 경우를 제외하고는 매우 큰 값(N개의 노드를 모두 거쳐서 가더라도 더 큰 값).
				dist[i][j] = 100_000_000;
			}
		}

		for (int i = 0; i < M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int cost = Integer.parseInt(st.nextToken());

			// 가는 경로가 하나가 아닐 수 있다. 따라서 그 중 최소 비용을 저장해두면 된다.
			dist[a][b] = Math.min(dist[a][b], cost);
			dist[b][a] = Math.min(dist[b][a], cost);
			// i에서 j로 가는 경로 저장
			String aString = Integer.toString(a);
			String bString = Integer.toString(b);
			path[a][b]=aString+bString;
		}

		// 플로이드 워셜 알고리즘
		// 노드를 1개부터 N개까지 거쳐가는 경우를 모두 고려한다.
		for (int k = 0; k < N; k++) {
			// 노드 i에서 j로 가는 경우.
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					// k번째 노드를 거쳐가는 비용이 기존 비용보다 더 작은 경우 갱신
					// 또는 연결이 안되어있던 경우(INF) 연결 비용 갱신.
					// i에서 j로 가는 경로 저장
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

		// 출력
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				// 연결이 안되어 있는 경우
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
			// 연결이 안되어 있는 경우
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
		System.out.println("남은 배달 수 : " + last+" 개");
		S = Integer.parseInt(br.readLine());
		F = Integer.parseInt(br.readLine());
		
	    System.out.println("예상 경로 : " + path[S][F]);   // gui
	  
	    today = sdformat.format(cal.getTime());  
	    System.out.println("현재 시간 : " + today); // gui
	    
	    System.out.println("소요 시간 : " + dist[S][F]+"시간");
	    cal.add(cal.HOUR,dist[S][F]);
	    
	    today = sdformat.format(cal.getTime()); 
	    System.out.println("퇴근 예상시간 : "+today);// gui
	
	    int random;
	    random = (int)(Math.random() * (5)) + 1;
	    
	    if(random == 1) {   // 랜덤값으로 1이 나오면 사고 발생했다 가정하고 코스트 무작위로 변경하여 경로 재탐색
	        
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
	        
	        System.out.println(randomdest1+"-"+randomdest2+"에 사고가 발생했습니다! 경로를 재탐색 중입니다.....");
	        System.out.println("사고가 발생했습니다! 경로를 재탐색 중입니다....."); // gui
	        R--;
	        
	        // 플로이드 워셜 알고리즘
			// 노드를 1개부터 N개까지 거쳐가는 경우를 모두 고려한다.
			for (int k = 0; k < N; k++) {
				// 노드 i에서 j로 가는 경우.
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						// k번째 노드를 거쳐가는 비용이 기존 비용보다 더 작은 경우 갱신
						// 또는 연결이 안되어있던 경우(INF) 연결 비용 갱신.
						// i에서 j로 가는 경로 저장
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
	System.out.println("배달을 완료하였습니다");
	System.out.println("현재 시각 : "+today);
	}
}