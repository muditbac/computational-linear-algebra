#include "inc/_functions.h"
#include "inc/_inputs.h"

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
			f = U[j][i]/U[i][i];
			FOR(k, i+1, m)
				U[j][k] -= f*U[i][k];
			U[j][i]=0;
			L[j][i]=f;
		}
	}
}



int main(int argc, char *argv[]){

	input(argc, argv);
	cout<<"A|b = "<<endl;
	print(A, b);

	reduceLU(A, L, U);
	cout<<"L = "<<endl;
	print(L);
	cout<<"U = "<<endl;
	print(U);

	cout<<"LU = "<<endl;
	print(matrixMultiply(L, U));

	cout<<"y = ";
	forwardSubstitution(L, b, y);
	print(y);

	cout<<"x = ";
	backSubstitution(U, y, x);
	print(x);

}


