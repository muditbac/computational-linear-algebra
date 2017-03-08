#include "inc/_functions.h"
#include "inc/_inputs.h"

vvf L;
vvf U;
vf y;

void reduceLU(const vvf &A, vvf &L, vvf &U){
	int n=SIZE(A);
	int m=SIZE(A[0]);

	initialize_identity(L, n);
	initialize_identity(U, n, m);

	myfloat f;
	REP(i, n){
		FOR(j, i, m){
			f = A[i][j];
			REP(k, i)
				f -= L[i][k]*U[k][j];

			U[i][j] = f;
		}
		FOR(k, i+1, n){
			if (i>=m) break;
			f = A[k][i];
			REP(p, i)
				f -= L[k][p]*U[p][i];
			f = f/U[i][i];
			L[k][i] = f;
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