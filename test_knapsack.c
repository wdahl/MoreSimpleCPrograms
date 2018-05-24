#include <stdio.h>
#include <stdlib.h>
#include "knapsack.h"

/* pointer to linked list node data structure */
typedef struct listitem* listitemptr;

//main function to test the knapsack data structure
//@return: 0 on completion
int main(){
	listitemptr k1 = NULL; // creates a new list item pointer and sets it to null
	//adds items to the knapsack
	k1 = KnapsackAdd(k1, 10); // sets the head of the knapsack to the first item entered
	KnapsackAdd(k1, -20);
	KnapsackAdd(k1, 10);
	KnapsackAdd(k1, 15);
	KnapsackAdd(k1, -20);
	KnapsackAdd(k1, 10);
	printf("%u\n", KnapsackItemCount(k1, 10)); // count of 10s in the knapsack
	printf("%u\n", KnapsackItemCount(k1, 8)); // count of 8s in the knapsack
	printf("%u\n", KnapsackSize(k1)); // size of k1

	listitemptr k2 = NULL; // creask a new list item pointers to kn
	//adds items to the knapsack k2
	k2 = KnapsackAdd(k2, 5); //head of th eknapsac to the first item entered // sets the
	KnapsackAdd(k2, 10);
	KnapsackAdd(k2, 15);
	KnapsackAdd(k2, 20);
	KnapsackAdd(k2, -5);

	//removes items from the knapsac
	KnapsackRemove(k2, 15);
	KnapsackRemove(k2, 10);

	//adds item to k1
	KnapsackAdd(k1, 10);
	printf("%u\n", KnapsackSize(k2));//size of k2
	printf("%u\n", KnapsackSize(k1));//size of k1

	//prints out the items and their counts in the knapsack
	KnapsackPrint(k1);
	KnapsackPrint(k2);

	return 0; // retuns 0 on succsufl run of program.
}