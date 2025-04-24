/*
*	All functions that are reusable and useful here please
*
*/
#ifndef ALAS
#define ALAS

void clear_input_buffer();

int is_input_whitespace();

int get_int_in_range(char *prompt, int Lower_bound, int Upper_bound);


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
#endif