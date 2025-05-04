/*
*	All functions that are reusable and useful here please
*/
#include <stdlib.h>

#ifndef ALAS
#define ALAS

typedef enum{
	FORMAT_INT,
	FORMAT_UINT,
	FORMAT_FLOAT,
	FORMAT_DOUBLE,
	FORMAT_LDOUBLE,
	FORMAT_LONG,
	FORMAT_ULONG,
	FORMAT_LLONG,
	FORMAT_ULLONG,
	FORMAT_STRING,
	FORMAT_SCI,
	FORMAT_G,
	FORMAT_HEX,
	FORMAT_OCTAL,
	FORMAT_UNKNOWN
}FormatType;


/* 2d Array of a any user defined type*/
typedef struct{
	void* data;
	int rows, cols;
	size_t elem_size;
}Grid;

void grid_init(Grid* g, int rows, int cols, size_t elem_size);

void clear_input_buffer();

int is_input_whitespace();



//			   MATH			    //
/*******************************/


int factorial(int x);

void display_fib_seq_to_n(long int n);

void K_to_C(const float *K, int SIZE, float *C);

void C_to_F(const float *C, int SIZE, float *F);


//			  ARRAYS			//
/*******************************/

float float_array_mean(const float *farr, int SIZE);

void string_Case_Invert(char *string);

int get_largest(const float *farr, int SIZE, float *largest);

int get_lowest(const float *farr, int SIZE, float *lowest);

int count_lower_than_x(const float *farr, int SIZE, float x);

void elements_less_than_x(const float *farr, int SIZE, float x, int *elements_arr);



//			  INPUT				//
/*******************************/
int get_int_in_range(const char *type, const int Lower_bound, int Upper_bound, const char *prompt, const char *type_error, const char *range_error);
int looped_get_input(const char *type,  void *out, const char *prompt, const char *error);
int get_input(const char *type, void *out, const char *prompt, const char *error);

FormatType get_format_type(const char *type);
int get_input_of_type(FormatType format, void *out, char *buffer);

int string_compare(const char *str1, const char *str2);


//			  FILES				//
/*******************************/

int open_file(const char *file_name);
int count_file_lines(FILE *fptr);
int longest_line_size(FILE *fptr);

#endif