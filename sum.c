#include <stdio.h>
#include <stdlib.h>

// main function that accepts command line arguemnts
int main(int argc, char* argv[]){
	// checks if there were numbers entered
	if(argc == 1){
		printf("no input numbers\n");
	}

	else{
		int j;// index of argv[]
		int sum = 0;//holds sum
		int i;//holds the char turned into a int
		//loops through the command arguemnts
		for(j = 1; j < argc; j++){
			i = strtol(argv[j], NULL, 10); // gets the char in argv at j and turns it into a int
			sum += i; // adds i to the sum
		}

		//prints sum
		printf("%d\n", sum);
	}

	return 0; // returns 0 on successful run
}