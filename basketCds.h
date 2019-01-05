#ifndef _BASKETCDS_H
#define _BASKETCDS_H

class BasketCds
{
public:

    BasketCds(){};
	~BasketCds(){};
	// recovery starts from recovery[1], ... , recovery[noCreditNames]
	// corr starts from corr[1][1], ... , corr[noCreditNames][noCreditNames]
	// spread starts from spread[0][0], ... , spread[noSpreadTerms-1][noCreditNames] 
	// the first column of spread stores term of time and rest columns store 
	// corresponding credit spreads for each credit name
	// all other inputs starts from 0
	void input(int noSimulations,double maturity,int freq,int noCreditNames,
			double premium,double notional,double *CashTerm,int noCashTerms,
			double *Recovery,double **Corr,double **Spread,int noSpreadTerms,
			double *ZeroTerm,double *ZeroRate,int noZeroTerms);
	double price(double &premiumPV,double &protectionPV);
    
	void releaseM();
    
private:
	int noSimulations,freq,noCreditNames,noCashTerms,noSpreadTerms,noZeroTerms;
	double maturity,notional,*cashTerm,*recovery,**corr,**spread,*zeroTerm,*zeroRate;
	double premium;
	double LinearInt(double time);
	// for a given survivalProb and creditIndex, survivalTime returns a defualt time for 
	// th-creditIndex credit name 
	// noSurvivalTerms is equal to number of FUTURE premium payment dates. From inside of code, 
	// you can that noSurvivalTerms = noProbTerms
	double survivalTime(int creditIndex,double survivalProb,double **survivalInfo,
			int noSurvivalTerms);
    
};
#endif
