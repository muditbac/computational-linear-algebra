#include "inc/_functions.h"
#include "inc/_inputs.h"

vvf _A;


void reduceAb(vvf &A, vf &b){
	int n=SIZE(A);
	myfloat f;
	REP(i, n-1){
    	#pragma omp parallel for 
		FOR(j, i+1, n){
			f = A[j][i]/A[i][i];
			FOR(k, i+1, n)
				A[j][k] -= f*A[i][k];
			A[j][i]=0;
			b[j] -= f*b[i];
		}
	}
}



int main(int argc, char *argv[]){

	input(argc, argv);
	cout<<"A = "<<endl;
	print(A);
	_A = A;

	cout<<"A|b = "<<endl;
	reduceAb(_A, b);
	print(_A, b);
	cout<<endl;

	cout<<"x = ";
	backSubstitution(_A, b, x);
	print(x);
	cout<<endl;
}