#include<iostream>
#include "sir.h"

int main() {

	const double cm = 14; // normal, without distancing
	const double cn = 9; // after distancing
	
	const int P = 1000000; // 1 million people, say
	
	const double istar = 0.005; // 0.5% are initially infected
	const double beta = 0.02; // /day
	const double gamma = 1./14; // /day
	const double mu = 0.34; // if wearing mask

	const double f1 = 0.001; // 1 in 1000 are morons
	const double f2 = 0.05; // 1 in 20 are morons

	const double Tend = 300; // run till 300 days, say
	const double dT = 1.; // time steps of 1 day
	
	SIR p1(cm, cn, P, f1, istar, beta, gamma, mu);

	while (p1.get_time() < Tend) { // until simulation end time
		p1.step(dT);
	}

	// calculate fractions of different populations no longer susceptible
	const double frac_to_pct = 100;
	const double normal_percent_infected_or_recovered1 = frac_to_pct *
		(1-f1 - p1.get_sn())/(1-f1);
	const double moron_percent_infected_or_recovered1 = frac_to_pct * 
		(f1-p1.get_sm())/f1;
	
	std::cout << "With a fraction " << f1 << " being morons, by day " <<
		p1.get_time() << ", " << normal_percent_infected_or_recovered1 <<
		"% of normal people have been infected and "
		<< moron_percent_infected_or_recovered1 << "% of morons have been infected.\n";

	SIR p2(cm, cn, P, f2, istar, beta, gamma, mu);

	while (p2.get_time() < Tend) { // until simulation end time
		p2.step(dT);
	}

	// calculate fractions of different populations no longer susceptible
	const double normal_percent_infected_or_recovered2 = frac_to_pct * 
		(1 - f2 - p2.get_sn())/(1-f2);
	const double moron_percent_infected_or_recovered2 = frac_to_pct * 
		(f2-p2.get_sm())/f2;

	std::cout << "With a fraction " << f2 << " being morons, by day " <<
		p2.get_time() << ", " << normal_percent_infected_or_recovered2 << 
		"% of normal people have been infected and "
		<< moron_percent_infected_or_recovered2 << "% of morons have been infected.\n";

	return 0;

}