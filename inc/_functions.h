#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

typedef float myfloat;
typedef vector<myfloat> vf;
typedef vector<vf> vvf;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG
  #define VALUE(x)
  #define debug(...)
#endif

#define MAX_SIZE 100
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define FORIT(a,b) for (auto (a)=(b).begin();(a)!=(b).end(); (a)++)
#define FORITR(a,b) for (auto (a)=(b).rbegin();(a)!=(b).rend(); (a)++)
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)


void print(const vvf &A, const vf &b={}, int print_max_lines=4){
	bool concat = false;
	bool term = false;
	int n=SIZE(A);

	if (n>2*print_max_lines) term=true;
	print_max_lines--;

	if (b!=vf {}) concat = true;
	
	REP(i, n){
		REP(j, SIZE(A[i])){
			cout<<fixed<<setprecision(3)<<setw(8)<<A[i][j]<<"  ";
			if (term && j==print_max_lines) {
				cout<<"...  ";
				j=SIZE(A[i])-j-2;
			}
		}
		if (concat) cout<<"  |  "<<fixed<<setprecision(3)<<setw(8)<<b[i];

		cout<<endl;
		if (term && i==print_max_lines) {
			cout<<"  ...  \n";
			i=n-i-2;
		}
	}
	cout<<endl;
}

void print(const vf &v){
	FOREACH(i, v){
			cout<<fixed<<setprecision(3)<<setw(8)<<i<<"  ";
	}
	cout<<endl;
}

void initialize_identity(vvf &A, int n, int m=-1){
	if (m==-1) m=n;
	REP(i, n){
		vf temp;
		REP(j, m)
			if (i!=j) temp.pb(0);
			else temp.pb(1);
		A.pb(temp);
	}
}
void initialize_zeros(vvf &A, int n, int m=-1){
	if (m==-1) m=n;
	vf temp(m, 0);
	REP(i, n){
		A.pb(temp);
	}
}

void backSubstitution(const vvf &A, const vf &b, vf &x){
	int n=SIZE(A);
	myfloat a;
	FORD(i, n-1, 0){
		a = b[i];
		FOR(j, i+1, n){
			a -= A[i][j]*x[j];
		}
		x[i] = a/A[i][i];
	}
}

void forwardSubstitution(const vvf &L, const vf &b, vf &y){
	int n=SIZE(L);
	y=b;
	myfloat a;
	REP(i, n){
		a = b[i];
		REP(j, i){
			a -= L[i][j]*y[j];
		}
		y[i] = a/L[i][i];
	}
}


vvf matrixMultiply(const vvf &A, const vvf &B){
	int m = SIZE(A);
	int n = SIZE(B[0]);
	int k = SIZE(A[0]);

	assert(k==SIZE(B));

	vvf ans;
	initialize_zeros(ans, m, n);

	REP(i, m)
		REP(j, n){
			REP(p, k)
				ans[i][j] += A[i][p]*B[p][j];
		}
	return ans;

}