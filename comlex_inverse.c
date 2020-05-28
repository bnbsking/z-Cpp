#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double re;
    double im;
}Complex;

Complex Csum(Complex x, Complex y){
    Complex z;
    z.re = x.re + y.re;
    z.im = x.im + y.im;
    return z;
}

Complex Csub(Complex x, Complex y){
    Complex z;
    z.re = x.re - y.re;
    z.im = x.im - y.im;
    return z;
}

Complex Cprod(Complex x, Complex y){
    Complex z;
    z.re = x.re*y.re - x.im*y.im;
    z.im = x.re*y.im + x.im*y.re;
    return z;
}

void print2D(Complex** A, int row, int col){
    int i, j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            if(A[i][j].im>=0) printf("%.2lf+%.2lf ", A[i][j].re, A[i][j].im);
            else printf("%.2lf%.2lf ", A[i][j].re, A[i][j].im);
        }
        printf("\n");
    }
    printf("\n");
}

Complex** zeroMatrix(int row, int col){
    Complex** C = malloc(row*sizeof(Complex*));
    int i;
    for(i=0; i<row; i++) C[i] = malloc(col*sizeof(Complex));
    return C;
}

Complex* cofactor(Complex** A, int n, int row, int col){
    Complex** C = zeroMatrix(n-1, n-1);
    int i, j, ai, aj;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1; j++){
            if(i<row) ai=i;
            else ai=i+1;
            if(j<col) aj=j;
            else aj=j+1;
            C[i][j] = A[ai][aj];
        }
    }
    return C;
}

Complex det(Complex** A, int n){
    if(n==1) return A[0][0];
    else{
        Complex s;
        s.re=0;
        s.im=0;
        int i;
        for(i=0; i<n; i++){     //s = s + pow(-1,i) * A[0][i] * det(cofactor(A,n,0,i), n-1));
            if(i%2==0) s = Csum(s, Cprod(A[0][i], det(cofactor(A,n,0,i),n-1) ) );
            else s = Csub(s, Cprod(A[0][i], det(cofactor(A,n,0,i),n-1) ) );
        }
        return s;
    }
}

Complex** inverse(Complex** A, int n){
    Complex** C = zeroMatrix(n,n);
    Complex d = det(A,n);       // d=a+bi
    Complex pCoeff, nCoeff;     // 1/d=1/(a+bi)=(a-bi)/(a^2+b^2)
    pCoeff.re = d.re/(pow(d.re,2)+pow(d.im,2));
    pCoeff.im = -d.im/(pow(d.re,2)+pow(d.im,2));
    nCoeff.re = pCoeff.re*(-1);
    nCoeff.im = pCoeff.im*(-1);
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){ //C[i][j] = (1.0/d)*pow(-1,i+j)*det(cofactor(A,n,i,j), n-1);
            if((i+j)%2==0) C[i][j] = Cprod(pCoeff, det(cofactor(A,n,j,i), n-1));
            else C[i][j] = Cprod(nCoeff, det(cofactor(A,n,j,i), n-1));
        }
    }
    return C;
}
/**/
int main()
{
    Complex** M = zeroMatrix(3,3);
    print2D(M, 3, 3);
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            M[i][j].re=i+j;
            M[i][j].im=i-j;
        }
    }
    M[0][0].re = 5;
    print2D(M, 3, 3);
    
    Complex** cof = cofactor(M, 3, 1, 1);
    print2D(cof, 2, 2);
    
    Complex d = det(M, 3);
    printf("%.2lf %.2lf \n\n", d.re, d.im);
    
    Complex** I = inverse(M, 3);
    print2D(I,3,3);/**/
    
    return 0;
}
