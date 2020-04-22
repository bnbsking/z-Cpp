# include <iostream> // input output stream 輸入輸出資料流 
# include <vector>
using namespace std; // 防止函數名稱重複, 若沒寫則要用 std:: 

/*
Generate x sequence：x = [0 1 0 1 1 1 0 1 0] and 
    h sequence：h = [5 4 3 2 1]
Convolution ： y = conv_inC(x, h);
Verify with MATLAB conv and print out the result.
*/

//input 短vector<int> m維, 長vector<int> n維 
//output vector<int> m+n-1維 

vector<int> conv(vector<int> h, vector<int> x){
	int m = h.size();
	int n = x.size()-2*(m-1);
	int output_size = m+n-1;
	vector<int> y;
	for(int i=0; i<output_size; i++){
		int sum = 0;
		for(int k=0; k<m; k++){
			sum = sum + h[m-k-1]*x[m-k-1+i];
		}
		y.push_back(sum);
	}
	return y;
}


int main(){
	
	vector<int> h;
	h.push_back(5);
	h.push_back(4);
	h.push_back(3);
	h.push_back(2);
	h.push_back(1);
	
	vector<int> x;
	for(int i=0; i<h.size()-1; i++) x.push_back(0);	
	x.push_back(0);
	x.push_back(1);
	x.push_back(0);
	x.push_back(1);
	x.push_back(1);
	x.push_back(1);
	x.push_back(0);
	x.push_back(1);
	x.push_back(0);
	for(int i=0; i<h.size()-1; i++) x.push_back(0);
	
	vector<int> result = conv(h,x);
	for(int i=0; i<=result.size(); i++) cout << result[i] << " ";
} 
--------------------------------------
#include <stdio.h>
#include <stdlib.h>

int* convolution(int* h, int m, int* x, int l){
    int* c = malloc((l-m)*sizeof(int));
    int i=0;
    for(i=0; i<l; i++){
		int sum = 0;
		for(int j=0; j<m; j++){
			sum = sum + h[m-j-1]*x[m-j-1+i];
		}
		c[i] = sum;
	}
    return c;
}

int main()
{
    int i=0;
    
    int m=5;
    int* h = malloc(m*sizeof(int));
    h[0] = 5; h[1] = 4; h[2] = 3; h[3] = 2; h[4] = 1;
    
    int n=9, l=n+m*2-2; //17
    int* x = malloc(l*sizeof(int));
    for(i=0; i<m-1; i++) x[i] = 0; //0~3 補0
    x[m-1] = 0; x[m] = 1; x[m+1] = 0; x[m+2] = 1; x[m+3] = 1;
    x[m+4] = 1; x[m+5] = 0; x[m+6] = 1; x[m+7] = 0; //4~12 x
    for(i=n+m-1; i<l; i++) x[i] = 0; //13~16 補0
    
    int* c = convolution(h, m, x, l);
    for(i=0; i<n+m-1; i++) printf("%d ", c[i]);
    
    return 0;
}

------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float re;
    float im;
}Complex;

void p(Complex* arr){
    int i=0;
    for(i=0; i<5; i++){
        printf("%f+%fi \n", arr[i].re, arr[i].im);
    }
}

Complex* tw(Complex* arr){
    int i=0;
    for(i=0; i<5; i++){
        arr[i].re*=2;
        arr[i].im*=2;
    }
    return arr; 
}

int main()
{
    int i=0;
    printf("%ld \n", sizeof(Complex));
    
    Complex* arr = malloc(5*sizeof(Complex));
    for(i=0; i<5; i++){
        arr[i].re = i;
        arr[i].im = i*2;
    }
    
    for(i=0; i<5; i++){
        printf("%f+%fi \n", arr[i].re, arr[i].im);
    }
    p(arr);
    Complex* A = tw(arr);
    p(A);
    
    return 0;
}
