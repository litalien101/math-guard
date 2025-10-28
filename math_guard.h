\
    #ifndef MATH_GUARD_H
    #define MATH_GUARD_H

    #include <math.h>
    #include "math_ledger.h"

    /* Sabotage return configuration:
     * Define these before including to override:
     * - MATH_SABOTAGE_POW_RET
     * - MATH_SABOTAGE_SQRT_RET
     * - MATH_SABOTAGE_LOG_RET
     * - MATH_SABOTAGE_DIV_RET
     */
    #ifndef MATH_SABOTAGE_POW_RET
    #define MATH_SABOTAGE_POW_RET NAN
    #endif
    #ifndef MATH_SABOTAGE_SQRT_RET
    #define MATH_SABOTAGE_SQRT_RET NAN
    #endif
    #ifndef MATH_SABOTAGE_LOG_RET
    #define MATH_SABOTAGE_LOG_RET NAN
    #endif
    #ifndef MATH_SABOTAGE_DIV_RET
    #define MATH_SABOTAGE_DIV_RET INFINITY
    #endif

    double safe_pow(double base, double exp);
    double safe_sqrt(double x);
    double safe_log(double x);
    double safe_div(double numerator, double denominator);

    /* Additional wrappers */
    double safe_exp(double x);
    double safe_fmod(double x, double y);
    double safe_sin(double x);

    #endif // MATH_GUARD_H
