#include<bits/stdc++.h>
using namespace std;
#define Maxx 2
struct matrix
{
    long long int mat[Maxx][Maxx];
};
matrix mul(matrix a, matrix b){
    matrix C;
    for (int row = 0; row < Maxx; row++)
	{
		for (int col = 0; col < Maxx; col++)
		{
			long long int here= 0;
			for (int k = 0; k < Maxx; k++)
				here += a.mat[row][k]*b.mat[k][col];
            C.mat[row][col]=here;
		}
        
	}
    return C;
}
matrix identity(){
    matrix A;
    for(int i=0; i<Maxx; i++){
        for(int j=0; j<Maxx; j++){
            if(i==j)A.mat[i][j]=1;
            else A.mat[i][j]=0;
        }
    }
    return A;
}
matrix power(matrix A, int N){
    if(N==0) return identity();
    matrix X= power(A, N/2);
    if(N%2==0) return mul(X, X);
    else return mul(mul(X,X),A);
}
long long int get_nth_fibonacci(int N){
    matrix fib;
    fib.mat[0][0] = 1;
    fib.mat[0][1] = 1;
    fib.mat[1][0] = 1;
    fib.mat[1][1] = 0;
    return power(fib,N).mat[0][0];
}
int main()
{
    // matrix input;
    // for(int i=0; i<Maxx; i++){
    //     for(int j=0; j<Maxx; j++){
    //         scanf("%lld",&input.mat[i][j]);
    //     }
    // }
    // matrix output =power(input,500);
    // for(int i=0; i<Maxx; i++){
    //     for(int j=0; j<Maxx; j++){
    //         printf("%lld ",output.mat[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i=0; i<100; i++) cout<<i+1<<"th fib= "<<get_nth_fibonacci(i)<<endl;
    }