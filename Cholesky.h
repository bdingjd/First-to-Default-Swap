#ifndef CHOLESKY_H
#define CHOLESKY_H

class Cholesky
{
public:
    Cholesky(){};
	void Decomposition(double **C,double **L,int n,int &singularity);
	void Inverses(double **C,double **L,double **InvC,double **InvL,int n,int &singularity);
	// return inverses for both C and L that are stored in InvC and InvL, respectively
    void LinearEquation(double **C,double **L,double *b,double *x,int n,int &singularity);
/*
    this is a code for solving linear equation C*x = b by decomposing C into 
    lower and up triangle matrices L and L', i.e., C = L*L', C is an (n,n) symmetric 
	matrix and b is an (n,1)matrix.
*/
private:
};
#endif

