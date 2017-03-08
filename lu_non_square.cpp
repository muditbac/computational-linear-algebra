#include "_functions.h"
#include "_inputs.h"

vvf L;
vvf U;
vf y;

void reduceLU(const vvf &A, vvf &L, vvf &U){
	
	int n=SIZE(A);
	int m=SIZE(A[0]);
	U=A;
	initialize_identity(L, n);
	myfloat f;
	REP(i, n-1){
		FOR(j, i+1, n){
			if (i>=m) continue;
			f = U[j][i]/U[i][i];
			FOR(k, i+1, m)
				U[j][k] -= f*U[i][k];
			U[j][i]=0;
			L[j][i]=f;
		}
	}
}



int main(int argc, char *argv[]){

	input_non1();
	cout<<"A = "<<endl;
	print(A);

	reduceLU(A, L, U);
	cout<<"L = "<<endl;
	print(L);
	cout<<"U = "<<endl;
	print(U);

	cout<<"LU = "<<endl;
	print(matrixMultiply(L, U));

}


