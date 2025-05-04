/*
*	All functions that are reusable and useful here please
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "all.h"


//			   RANDOM			 //
/*******************************/

void grid_init(Grid* g, int rows, int cols, size_t elem_size){
    g->rows = rows;
    g->cols = cols;
    g->elem_size = elem_size;
    g->data = malloc(rows * cols * elem_size);
	if(g->data == NULL);
}

void clear_input_buffer(){char c; while((c = getchar()) != '\n' && c != EOF);}

int is_input_whitespace(){
	char c;
	while((c = getchar()) == ' ' || c == '\t');
	return (c == '\n');
}


//			   MATH			    //
/*******************************/



int factorial(int x){
	int f = 1; 
	while(x > 1){
		f = x * f; 
		x--;
	} 
	return f;
}

void display_fib_seq_to_n(long int n){
	long int a = 0, b = 1, c, i;
	if(n == 1){
		printf("\n0");
	}else{
		printf("%ld\n%ld\n", a, b);
		for(i = 2; i <= n; i++){
			c = a + b;
			a = b;
			b = c;
			printf("%ld\n", c);
		}
		printf("%ldnth fibonacci number is: %ld\n", n, c);
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


//			 STRINGS			//
/*******************************/

int string_compare(const char *str1, const char *str2){
	int i;
	for(i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
			return 0;
	}
	return(str1[i] == '\0' && str2[i] == '\0');
}

int string_compare_either(const char *str1, const char *str2,  const char *str3){
	return(string_compare(str1, str2) || string_compare(str1, str3));
}
	

//			  INPUT				//
/*******************************/

int get_int_in_range(const char *type, const int Lower_bound, int Upper_bound, const char *prompt, const char *type_error, const char *range_error){
	int input, valid = 0;
	
	while(!valid){
		if(get_input(type, &input, prompt, type_error)){
			if(input >= Lower_bound && input <= Upper_bound)
				valid = 1;
			else
				printf("%s", range_error);
		}
	}
	return input;
}


int get_input(const char *type, void *out, const char *prompt, const char *error){
	char buffer[100];
	FormatType input_format = get_format_type(type);
	
	printf("%s", prompt);
	
	if( !(fgets(buffer, sizeof(buffer), stdin)) || !(get_input_of_type(input_format, out, buffer))){
		printf("%s", error);		
		return 0;
	}else
		return 1;
}

int looped_get_input(const char *type, void *out, const char *prompt, const char *error){
	while(!get_input(type, out, prompt, error));
	return 1;
}


FormatType get_format_type(const char *type){
	if (string_compare_either(type, "%d", "%i")) return FORMAT_INT;
	if (string_compare_either(type, "%ld", "%li")) return FORMAT_LONG;
	if (string_compare_either(type, "%lld", "%lli")) return FORMAT_LLONG;
	if (string_compare_either(type, "%e", "%E")) return FORMAT_SCI;
	if (string_compare_either(type, "%g", "%G")) return FORMAT_G;
	if (string_compare_either(type, "%x", "%X")) return FORMAT_HEX;
	if (string_compare(type, "%u")) return FORMAT_UINT;
	if (string_compare(type, "%f")) return FORMAT_FLOAT;
	if (string_compare(type, "%lf")) return FORMAT_DOUBLE;
	if (string_compare(type, "%lf")) return FORMAT_LDOUBLE;
	if (string_compare(type, "%lu")) return FORMAT_ULONG;
	if (string_compare(type, "%llu")) return FORMAT_ULLONG;
	if (string_compare(type, "%s")) return FORMAT_STRING;
	if (string_compare(type, "%o")) return FORMAT_OCTAL;
	return FORMAT_UNKNOWN;
}

int get_input_of_type(FormatType format, void *out, char *buffer){
	switch (format){
		case FORMAT_FLOAT: 		if(sscanf(buffer, "%f", (float *)out) == 1) return 1;	
		case FORMAT_DOUBLE:		if(sscanf(buffer, "%lf", (double *)out) == 1) return 1;
		//case FORMAT_LDOUBLE: 	if(sscanf(buffer, "%Lf", (long double *)out) == 1) return 1;
		case FORMAT_SCI: 		if(sscanf(buffer, "%e", (float *)out) == 1) return 1;
		case FORMAT_G: 			if(sscanf(buffer, "%g", (float *)out) == 1) return 1;
		case FORMAT_INT:		if(sscanf(buffer, "%d", (int *)out) == 1) return 1;
		//case FORMAT_LONG:		if(sscanf(buffer, "ld", (long *)out) == 1) return 1;
		//case FORMAT_ULLONG: 	if(sscanf(buffer, "%llu", (unsigned long long *)out) == 1) return 1;
		//case FORMAT_LLONG: 	if(sscanf(buffer, "%lld", (long long *)out) == 1) return 1;
		case FORMAT_ULONG:		if(sscanf(buffer, "%lu", (unsigned long *)out) == 1) return 1;
		case FORMAT_UINT:		if(sscanf(buffer, "%u", (unsigned int *)out) == 1) return 1;
		case FORMAT_OCTAL:		if(sscanf(buffer, "%o", (unsigned int *)out) == 1) return 1;
		case FORMAT_STRING:		if(sscanf(buffer, "%s", (char *)out) == 1) return 1;
		default:				return 0;
	}
}


//			  FILES				//
/*******************************/

int open_file(const char *file_name){
	FILE *file;
	file = fopen(file_name, "r");
	
	if(file == NULL)
		return 0;
	else{
		fclose(file);
		return 1;
	}
}

int count_file_lines(FILE *fptr){
    int lines = 1;
    int c;

    fseek(fptr, 0, SEEK_SET);
	if((c = fgetc(fptr)) == EOF){
		return 0;
	}

    while((c = fgetc(fptr)) != EOF){
        if (c == '\n') {
            lines++;
        }
    }
    return lines;
}


int longest_line_size(FILE *fptr){
    char c;
    int current_line = 0, max = 0;
	
	if(fptr == NULL){
		perror("\n[:Function=longest_line_size:]\n{::File pointer is NULL::}\n");
	}

    fseek(fptr, 0, SEEK_SET);
	
	c = fgetc(fptr);
	
    while((c = fgetc(fptr)) != EOF){
		if(c == '\n'){
			if(current_line > max){
				max = current_line;
			}
			current_line = 0;
		}else{
			current_line++;
		}
    }
	if (current_line > max) {
        max = current_line;
    }
    return max;	
}