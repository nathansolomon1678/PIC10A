#ifndef SIR_H
#define SIR_H

/**
 * @struct SIR simulator for an SIR infection model
 */
struct SIR {
public:
    // Constructor
    SIR(const double cm, const double cn, const int P, const double f, const double istar, const double beta, const double gamma, const double mu);

    // Misc getter funcs
    double get_time() const;

    double get_sn() const;
    double get_sm() const;
    double get_in() const;
    double get_im() const;
    double get_rn() const;
    double get_rm() const;

    // Simulates one iteration of the model, using the given time step
    void step(const double dt);

private:
    // Const member variables represent settings (parameters) of the model,
    // and the non-const member variables represent the current status of the population
    const int population_size;  // P
    const double proportion_of_morons;  // f
    const double initial_num_infected;  // i*

    const int num_normals;  // N
    const int num_morons;  // M

    const double daily_normal_contacts;  // c_n
    const double daily_moron_contacts;  // c_m

    const double contagiousness;  // beta
    const double daily_recovery_probability;  // gamma
    const double risk_reduction_factor;  // mu

    double time;  // t

    double susceptible_normals  /* s_n */, susceptible_morons;  // s_m
    double infected_normals     /* i_n */,    infected_morons;  // i_m
    double recovered_normals    /* r_n */,   recovered_morons;  // r_m
};

#endif  // SIR_H
