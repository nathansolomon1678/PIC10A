#ifndef SIR_H
#define SIR_H

/**
 * @struct SIR
 * @brief Population simulator for an SIR (Susceptible --> Infected --> Recovered) infection model
 */
struct SIR {
public:
    /**
     * @param cm The average number of daily contacts per moron
     * @param cn The average number of daily contacts per normal person
     * @param P The number of people in the model
     * @param f The proportion of people who are morons
     * @param istar The proportion of people who are infected at time 0
     * @param beta The probability of getting sick from one contact
     * @param gamma The daily probability of recovering
     * @param mu The risk reduction factor from wearing masks
     */
    SIR(const double cm, const double cn, const int P, const double f, const double istar, const double beta, const double gamma, const double mu);

    /** @returns the current time */
    double get_time() const;

    /** @returns the number of susceptible normals, as a proportion of the total population */
    double get_sn() const;
    /** @returns the number of susceptible morons, as a proportion of the total population */
    double get_sm() const;
    /** @returns the number of infected normals, as a proportion of the total population */
    double get_in() const;
    /** @returns the number of infected morons, as a proportion of the total population */
    double get_im() const;
    /** @returns the number of recovered (or deceased) normals, as a proportion of the total population */
    double get_rn() const;
    /** @returns the number of recovered (or deceased) morons, as a proportion of the total population */
    double get_rm() const;

    /** Simulates one iteration of the model, using the given time step */
    void step(const double dt);

private:
    // Const member variables represent settings (parameters) of the model,
    // and the non-const member variables represent the current status of the population
    const int population_size;  // P
    const double proportion_of_morons;  // f

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
