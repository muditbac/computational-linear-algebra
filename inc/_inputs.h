vvf A;
vf b;
int n;
vf x;

float r(){
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void input_random(int n){
    REP(i,n){
        vf v(n);
        generate(v.begin(), v.end(), r);
        v[i] += n;
        A.pb(v);
        b.pb(r());
    }
    x = vf(n, 0);
}


void input0(){
    n=3;
    A.pb(vf {1,1,1});
    A.pb(vf {1,1.0001,2});
    A.pb(vf {1,2,2});
    b= vf {1,2,1};
	x = vf {0,0,0};
}

void input1(){
    n=2;
    A.pb(vf {1.0001,1});
    A.pb(vf {1,1.0001});
    b= vf {2.0001,2.0001};
	x = vf {0,0};
}

void input2(){
    n=2;
    A.pb(vf {1000,999});
    A.pb(vf {999,998});
    b= vf {1999,1997};
    b= vf {1998.99,1997.01};
	x = vf {0,0};
}

void input3(){
    n=4;
    A.pb(vf {2,3,0,0});
    A.pb(vf {4,7,2,0});
    A.pb(vf {-6,-10,0,1});
    A.pb(vf {4,6,4,5});
    x = vf {0,0,0,0};
}

void input4(){
    n=3;
    A.pb(vf {4,2,-6});
    A.pb(vf {2,10,9});
    A.pb(vf {-6,9,26});
    b= vf {1,2,1};
    x = vf {0,0,0};
}

void input_non1(){
    n=2;
    A.pb(vf {3,-1,4});
    A.pb(vf {6,-3,10});
    A.pb(vf {-9,5,-11});
    A.pb(vf {-3,0,-7});
    A.pb(vf {6,-4,2});
    // A.pb(vf {7,-2,4});
}
void input_non2(){
    n=2;
    A.pb(vf {3,-1,4});
    A.pb(vf {6,-3,10});
}

void input(int argc, char *argv[]){
    if (argc==1)
        input4();
    else 
        input_random(atoi(argv[1]));
}

void input_non(){
    input_non2();
}