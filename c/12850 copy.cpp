#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MOD = 1000000007;
#define N 8

typedef vector<vector<long long> > matrix;

matrix mul(matrix A, matrix B){
	matrix result(N,vector<long long>(N,0));
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			for(int k = 0; k<N; k++)
				(result[i][j] += A[i][k] * B[k][j])%=MOD;
		}
	}
	return result;
}

matrix calcul(long long pow, matrix B){
	if(pow == 1)
		return B;
	matrix ret = calcul(pow/2,B);
	ret = mul(ret,ret);
	if(pow%2 == 1)
		ret = mul(ret,B);
	return ret;
	
}

void setValue(matrix &v, int i, int j){
    v[i][j] = 1;
    v[j][i] = 1;
}

int main() {
	freopen("input.txt","r",stdin);
	matrix v(N, vector<long long>(N,0));
	
    setValue(v, 0, 1);
    setValue(v, 0, 2);
    setValue(v, 1, 3);
    setValue(v, 1, 2);
    setValue(v, 2, 3);
    setValue(v, 2, 4);
    setValue(v, 3, 4);
    setValue(v, 3, 5);
    setValue(v, 4, 5);
    setValue(v, 4, 6);
    setValue(v, 5, 7);
    setValue(v, 6, 7);

	for(int i = 0 ; i<N; i++){
		for(int j = 0; j<N; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
	long long B;
	cin >> B;
	v = calcul(B,v);
	cout << v[0][0]%MOD;
	return 0;
}