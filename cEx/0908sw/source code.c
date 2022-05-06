#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BAR 1
#define BELL 2
#define LEMON 3
#define CHERRY 4
#define RMAX 4

int main() {
	int slot1, slot2, slot3;
	char anykey;
	while (1) {
		printf("\ntype any key to start the slot machine\n");
		scanf_s("%c",anykey);
		/*scan anykey to start machine*/
		srand(time(NULL));
		/*get a random number every time*/
		slot1 = 1 + (int)rand() % RMAX;
		slot2 = 1 + (int)rand() % RMAX;
		slot3 = 1 + (int)rand() % RMAX;
		/*The remainder of the random number divided by RMAX*/
		if (slot1 == slot2 && slot2 == slot3 && slot1 == CHERRY)
			printf("Congratulations On A JACKPOT\n");
		/*every slots are CHEERY*/
		else if (slot1 == CHERRY || slot2 == CHERRY || slot3 == CHERRY)
			printf("Paid Out: One DIME\n");
		/*only one slot is CHEERY*/
		else if (slot1 == slot2 && slot2 == slot3)
			printf("Paid Out: One Nickel\n");
		/*every slots are same, not CHEERY*/
		else printf("Sorry. Better Luck Next Time\n");
		/*else case*/

	}

	return 1;
}