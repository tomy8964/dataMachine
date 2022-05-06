package ex;

import java.util.*;

public class delievery {
    public static void main(String[] args) {
        int N = 5;
        int K = 3;
        int[][] road = {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
        delievery s = new delievery();
        System.out.println(s.solution(N,road,K));
    }

    static class Node implements Comparable<Node>{
        int index;
        int cost;

        public Node(int index,int cost){
            this.index = index;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }

    ArrayList<ArrayList<Node>> array;
    PriorityQueue<Node> pq;
    int[] d;

    public int solution(int N,int[][] road, int K){
        int answer = 0;
        d = new int[N+1];
        array = new ArrayList<>();
        pq = new PriorityQueue<>();

        Arrays.fill(d,Integer.MAX_VALUE);

        for(int i = 0; i<N+1;i++){
            array.add(new ArrayList<Node>());
        }

        for(int i = 0; i< road.length;i++){
            int a = road[i][0];
            int b = road[i][1];
            int cost = road[i][2];

            array.get(a).add(new Node(b,cost));
            array.get(b).add(new Node(a,cost));
        }
        d[1] = 0;
        pq.offer(new Node(1,0));

        dijkstra();

        for(int i = 0; i<d.length;i++){
            if(d[i] <=K){
                answer++;
            }
        }

        return answer;
    }

    public void dijkstra() {
        while(!pq.isEmpty()){
            Node node = pq.poll();
            for(Node newNode : array.get(node.index)){
                if(d[newNode.index] > d[node.index] + newNode.cost){
                    d[newNode.index] = d[node.index] + newNode.cost;
                    pq.offer(newNode);
                }
            }
        }
    }
}