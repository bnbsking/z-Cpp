#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(int* arr, int n){
	int i=0;
	for(i=0;i<n;i++) printf("%d ", arr[i]);
	printf("\n");
}

int* random_arr(int n){
	int* arr = calloc(n, sizeof(int));
	int i=0;
	srand(time(0));
	for(; i<n; i++) arr[i] = rand()%10;
	return arr;
}

void print_arr_2(int** arr, int m, int n){
	int i=0, j=0;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++) printf("%d ", arr[i][j]);
		printf("\n");
	}
}

int** random_arr_2(int m, int n){
	int** arr = calloc(m, sizeof(int*));
	int i=0;
	for(i=0; i<m; i++) arr[i] = calloc(n, sizeof(int));
	
	int j=0;
	srand(time(0));
	for(i=0; i<m; i++)
		for(j=0; j<n; j++) arr[i][j] = rand()%10;
	return arr;
}

int main(){
	int i=0;
	
	int sarr[4] = {0};
	print_arr(sarr, 4);
	int* darr = random_arr(5);
	print_arr(darr, 5);
	free(darr);
	
	int sarr2[2][4] = {0};
	int* ptr[2];	//«ü¼Ð°}¦C 
	ptr[0] = sarr2;
	ptr[1] = sarr2[1];
	print_arr_2(ptr, 2, 4);

	int** darr2 = random_arr_2(3, 2);
	print_arr_2(darr2, 3, 2);
	for(i=0; i<3; i++) free(darr2[i]);
	free(darr2);
	
	return 0;
} 
