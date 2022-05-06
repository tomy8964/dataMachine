#include <cstdio>
#include <algorithm>
#include <climits> 

using namespace std;
int N; int cost[10][10];
bool visited[10];
int lowCost = INT_MAX;
int city[10];

void tsp(int node, int costSum, int count) {
    visited[node] = true;
    city[count - 1] = node;
    if (count == N) {
        lowCost = min(lowCost, costSum);
        for (int i = 0; i < N; i++) {
            printf("%d ", city[i]);
        }
        visited[node] = false;
        city[count - 1] = -1;
        return;
    }

    for (int i = 0;i < N;i++) {
        if (!visited[i] && cost[node][i] != 0) {
            if (costSum + cost[node][i] < lowCost) { //여기 코드로 횟수 줄임
                tsp(i, costSum + cost[node][i], count + 1);
            }
        }
    }
    visited[node] = false;
    city[count - 1] = -1;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        city[i] = -1;
        visited[i] = false;
        for (int j = 0; j < N; j++)
            scanf("%d", &cost[i][j]);
    }
    printf("\n");
    for (int i = 0; i < N; i++)
        tsp(i, 0, 1);

    printf("%d\n", lowCost);
    return 0;
}
