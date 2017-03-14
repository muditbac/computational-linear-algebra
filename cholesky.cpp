#include "inc/_functions.h"
#include "inc/_inputs.h"

vvf L;
vvf tL;
vf y;

void reduceLU(const vvf &A, vvf &L){
	int n=SIZE(A);
	int m=SIZE(A[0]);

	initialize_identity(L, n);

	myfloat f;
	REP(i, n){
		myfloat sum=0;
		FOR(j, 0, i)
			sum += (L[i][j]*L[i][j]);

		L[i][i] = sqrt(A[i][i]-sum);
		FOR(j, i+1, m){
			f = A[i][j];
			FOR(k, 0, j)
				f -= L[i][k]*L[j][k];

			L[j][i] = f/L[i][i];
		}
	}
}



int main(int argc, char *argv[]){

	input(argc, argv);
	cout<<"A|b = "<<endl;
	print(A, b);

	reduceLU(A, L);
	tL = L;
	transpose(tL);

	cout<<"L = "<<endl;
	print(L);
	cout<<"t(L) = "<<endl;
	print(tL);


	cout<<"Lt(L) = "<<endl;
	print(matrixMultiply(L, tL));

	cout<<"y = ";
	forwardSubstitution(L, b, y);
	print(y);

	cout<<"x = ";
	backSubstitution(tL, y, x);
	print(x);

}