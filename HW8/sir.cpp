#include "sir.h"
#include <cmath>  // for exp function

SIR::SIR(const double cm,
         const double cn,
         const int P,
         const double f,
         const double istar,
         const double beta,
         const double gamma,
         const double mu) :
    daily_moron_contacts(cm),
    daily_normal_contacts(cn),
    population_size(P),
    proportion_of_morons(f),
    contagiousness(beta),
    daily_recovery_probability(gamma),
    risk_reduction_factor(mu),
    time(0.),
    num_normals(P * (1. - f)),
    num_morons(P * f),
    susceptible_normals((1. - istar) * (1. - f)),
    susceptible_morons((1. - istar) * f),
    infected_normals(istar * (1. - f)),
    infected_morons(istar * f),
    recovered_normals(0.),
    recovered_morons(0.) {
}

double SIR::get_time() const { return time; }

double SIR::get_sn()   const { return susceptible_normals; }
double SIR::get_sm()   const { return susceptible_morons;  }

double SIR::get_in()   const { return infected_normals;    }
double SIR::get_im()   const { return infected_morons;     }

double SIR::get_rn()   const { return recovered_normals;   }
double SIR::get_rm()   const { return recovered_morons;    }

void SIR::step(const double dt) {
    // This whole function just uses the formulas given in assignement.pdf
    // No need to use descriptive variables because I don't even know what these values represent
    const double psi = num_normals * daily_normal_contacts + num_morons * daily_moron_contacts;
    const double psi_m = num_morons * daily_moron_contacts / psi;
    const double exponent = risk_reduction_factor * (1. - psi_m) * infected_normals / (1. - proportion_of_morons)
                          + psi_m * infected_morons / proportion_of_morons;
    const double H_n = 1. - exp(-contagiousness * dt * daily_normal_contacts * exponent);
    const double H_m = 1. - exp(-contagiousness * dt * daily_moron_contacts * exponent);
    const double R = 1. - exp(-daily_recovery_probability * dt);
    // Calculate how much to change each variable at the end of the iteration, but don't change
    // change any member variables until all the deltas have been calculated, or else
    // the earlier calculations will mess up the later ones
    const double d_sn = -H_n * susceptible_normals;
    const double d_sm = -H_m * susceptible_morons;
    const double d_in = H_n * susceptible_normals - R * infected_normals;
    const double d_im = H_m * susceptible_morons - R * infected_morons;
    const double d_rn = R * infected_normals;
    const double d_rm = R * infected_morons;

    susceptible_normals += d_sn;
    susceptible_morons += d_sm;
    infected_normals += d_in;
    infected_morons += d_im;
    recovered_normals += d_rn;
    recovered_morons += d_rm;

    time += dt;
}
