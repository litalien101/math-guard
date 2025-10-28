\
    #include "math_guard.h"
    #include <errno.h>

    double safe_pow(double base, double exp) {
        if (base == 0.0 && exp == 0.0) {
            log_sabotage("pow(0, 0) undefined");
            return MATH_SABOTAGE_POW_RET;
        }
        return pow(base, exp);
    }

    double safe_sqrt(double x) {
        if (x < 0.0) {
            log_sabotage("sqrt of negative");
            return MATH_SABOTAGE_SQRT_RET;
        }
        return sqrt(x);
    }

    double safe_log(double x) {
        if (x <= 0.0) {
            log_sabotage("log of non-positive");
            return MATH_SABOTAGE_LOG_RET;
        }
        return log(x);
    }

    double safe_div(double numerator, double denominator) {
        if (denominator == 0.0) {
            log_sabotage("division by zero");
            return MATH_SABOTAGE_DIV_RET;
        }
        return numerator / denominator;
    }

    /* New wrappers */
    double safe_exp(double x) {
        /* exp is safe for all real x, but check for overflow */
        double res = exp(x);
        if (isinf(res)) {
            log_sabotage("exp overflow/underflow");
        }
        return res;
    }

    double safe_fmod(double x, double y) {
        if (y == 0.0) {
            log_sabotage("fmod division by zero");
            return NAN;
        }
        return fmod(x, y);
    }

    double safe_sin(double x) {
        /* sin is safe but preserve type integrity */
        return sin(x);
    }
