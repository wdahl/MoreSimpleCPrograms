#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "knapsack.h"

/* pointer to linked list node data structure */
typedef struct listitem* listitemptr;

/*
 * adds an item to a knapsack; must only update the "count" if the item already exist in the knapsack; "count" must be set to 1 for previously-nonexisting items
 * @param knapsack: points to the first listitem in a knapsack; NULL if knapsack has not been created yet
 * @param item: integer item to add
 * @return pointer to the listitem added/updated; NULL if unsuccessful 
 */
listitemptr KnapsackAdd(listitemptr knapsack, int item){
	//checks if knapsack is empty
	if(knapsack == NULL){
		knapsack = (listitemptr)malloc(sizeof(listitemptr));// allocates meemory for a new node
		knapsack->item = item; // sets the item field of knapsack to item
		knapsack->count++; // increases count filed
		knapsack->next = NULL; // sets next node pointer to null
		return knapsack; // returns knapsack
	}

	//checks if knapsacks item is equal to the item being inserted
	if(knapsack->item == item){
		knapsack->count++;//incremants counter field of knapsack
		return knapsack;//reutrns knapsack
	}

	else{
		listitemptr current = knapsack; // makes new list pointer and points it at knapsack
		bool exist = false;// checks if the item already exists in the knapsack
		//loops through the knapsack
		while(current->next != NULL){
			//checks if th enext node item is equal to the item being inserted
			if(current->next->item == item){
				current->next->count++; // incremant the count of the next node
				exist = true;//sets exist to tru
				break;//breaks out of loop
			}

			else{
				current = current->next;//goes to the next node
			}
		}

		//if item was never added to knapsack
		if(exist == false){
			listitemptr new_item = (listitemptr)malloc(sizeof(listitemptr)); // allocates memeory for the new node
			//sets the field of the new item
			new_item->item = item;
			new_item->count = 1;
			new_item->next = NULL;
			current->next = new_item;//sets the next node to the new item
		}

		return current;//returns current node on
	}

	return NULL;//returns null if unsucessful
}

/*
 * removes a value from a knapsack; must update the "count" and delete the associated listitem when count becomes 0 
 * @param knapsack: points to the first listitem in a knapsack
 * @param item: integer item to remove
 * @return pointer to the first listitem in knapsack; NULL if knapsack becomes empty
 */
listitemptr KnapsackRemove(listitemptr knapsack, int item){
	if(knapsack == NULL){
		return NULL;//returns null if knapsack is empty
	}

	if(knapsack->item == item){
		knapsack->count--;//decrements the counter field of knapsack
		//checks if the count of knapsack is zero
		if(knapsack->count == 0){
			listitemptr delete = knapsack;
			knapsack = knapsack->next;// removes the head of the list
			free(delete);
		}
	}

	else{
		listitemptr current = knapsack;
		while(current->next != NULL){
			if(current->next->item == item){
				current->next->count--;
				if(current->next->count == 0){
					listitemptr delete = current->next;
					current->next = current->next->next;//removes the next node and points current to the next node in the list
					free(delete);
				}
			}

			else{
				current = current->next;
			}
		}
	}

	return knapsack;//returns knapsack
}

/*
 * prints elements and their counts in a knapsack
 * @param knapsack: points to the first listitem in a knapsack
 * @stdout: for example, "" (nothing) when knpsack==NULL, or "125 (4), -10 (1), 26 (2)" when items include four of 125, one of -10, and two of 26 
 * @return void
 */
void KnapsackPrint(listitemptr knapsack){
	if(knapsack == NULL){
		printf("\"\" (nothing)\n");
	}

	else{
		listitemptr current = knapsack;
		while(current != NULL){
			printf("%d (%d), ", current->item, current->count);
			current = current->next;
		}

		printf("\n");
	}
}

/*
 * count the number of specific item in the knapsack
 * @param knapsack: points to the first listitem in a knapsack
 * @param item: integer item to search for
 * @return item count, or 0 if it does not exist
 */
unsigned int KnapsackItemCount(listitemptr knapsack, int item){
	listitemptr current = knapsack;
	bool found = false;//em was found checks if the item was foun fin the list
	while(current != NULL){
		if(current->item == item){
			return current->count; // returns the count of the current item
		}

		else{
			current = current->next;
		}
	}

	return 0; // returns 0 if the item is not founf
}

/*
 * total count of items in the knapsack
 * @param knapsack: points to the first listitem in a knapsack
 * @return total item count. for example, 7 in case of above example "125 (4), -10 (1), 26 (2)"
 */
unsigned int KnapsackSize(listitemptr knapsack){
	unsigned int size = 0;//size of the knapsack
	listitemptr current = knapsack;
	while(current != NULL){
		size += current->count; //adds the count of the current item to the total size of knapsack
		current = current->next;
	}

	return size; // returns the total size of the knapsack
}