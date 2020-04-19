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
