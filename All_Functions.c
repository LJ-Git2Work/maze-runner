/*
*	All functions that are reusable and useful here please
*/

#include <stdio.h>
#include <stdlib.h>
#include "All_Functions.h"

void clear_input_buffer(){char c; while((c = getchar()) != '\n' && c != EOF);}

int is_input_whitespace(){
	char c;
	while((c = getchar()) == ' ' || c == '\t');
	return (c == '\n');
}


int get_int_in_range(char *prompt, int Lower_bound, int Upper_bound){
	int input, valid = 0;
	
	while(!valid){
		printf("\n%s", prompt);
		if(scanf("%d", &input) != 1|| is_input_whitespace() != 1){
			printf("\n#ERROR: Input is NOT a number!\n");
			clear_input_buffer();
		}else if(input < Lower_bound || input > Upper_bound){
			printf("\n#ERROR: Input is NOT inside the valid range!\n");
		}else
			valid = 1;
	}
	clear_input_buffer();
	return input;
}



//			   MATH			    //
/*******************************/



int factorial(int x){int f = 1; while(x > 1){f = x * f; x--;} return f;}

void display_fib_seq_to_n(long int n){
	unsigned long long int a = 0, b = 1, c, i;
	if(n == 1){
		printf("\n0");
	}else{
		printf("%d\n%d\n", a, b);
		for(i = 2; i <= n; i++){
			c = a + b;
			a = b;
			b = c;
			printf("%d\n", c);
		}
		printf("%dnth fibonacci number is: %d\n", n, c);
	}
}

void K_to_C(const float *K, int SIZE, float *C){
	for(int i = 0; i < SIZE; i++){
		C[i] = K[i] - 273.15;
	}
	
}

void C_to_F(const float *C, int SIZE, float *F){
	for(int i = 0; i < SIZE; i++){
		F[i] = C[i] * 9 / 5 + 32;
	}
}



//			  ARRAYS			//
/*******************************/




float float_array_mean(const float *farr, int SIZE){
	float sum = 0;
	for(int i = 0; i < SIZE; i++){
		sum += farr[i];
	}
	return sum / (float) SIZE;
}


void string_Case_Invert(char *string){
	for(int i = 0; string[i] != '\0'; i++){
		if(string[i] >= 'A' && string[i] <= 'Z'){
			string[i] += 32;
		}else if(string[i] >= 'a' && string[i] <= 'z')
			string[i] -= 32;
	}
}


int get_largest(const float *farr, int SIZE, float *largest){
	int largest_index = farr[0];
	*largest = farr[0];
	
	for(int i = 0; i < SIZE; i++){
		if (farr[i] > *largest){
			*largest = farr[i];
			largest_index = i;
		}
	}
	return largest_index;
}


int get_lowest(const float *farr, int SIZE, float *lowest){ 
	int lowest_index = farr[0];
	*lowest = farr[0];
	
	for(int i = 0; i < SIZE; i++){
		if (farr[i] < *lowest){
			*lowest = farr[i];
			lowest_index = i;
		}
	}
	return lowest_index;
}


int count_lower_than_x(const float *farr, int SIZE, float x){
	int count = 0;
	for(int i = 0; i < SIZE; i++){
		if(farr[i] < x)
			count++;
	}return count;
}


void elements_less_than_x(const float *farr, int SIZE, float x, int *elements_arr){	
	for(int i = 0, j = 0; j < SIZE; i++){
		if(farr[i] < x){
			elements_arr[j] = i;
			j++;
		}
	}
}