#ifndef _SURVIVALPROB_H
#define _SURVIVALPROB_H
class SurvivalProb
{
public:
    SurvivalProb(){}; 
	~SurvivalProb(){}; 
	void input(double *ZeroRate,double *ZeroTerm,int noZeroTerms,
		double *SpreadRate,double *SpreadTerm,int noSpreadTerms,double recovery,
		double *ProbTerm,int noProbTerms);
	// probCalc calculates survival probability at probTerm[0], ..., probTerm[noProbTerms-1] 
	// save them in prob
	void probCalc(double *prob);
    
private: 
	double *zeroTerm,*zeroRate,*spreadTerm,*spreadRate,*probTerm;
	double recovery;
	int noZeroTerms,noSpreadTerms,noProbTerms; 
	double LinearInt(double time);
	double LinearIntSpd(double time);

};
#endif