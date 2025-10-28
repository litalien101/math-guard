\
    #include <stdio.h>
    #include "math_guard.h"

    int main() {
        double a = 0.0;
        double b = 0.0;
        double c = -9.0;
        double d = 10.0;
        double e = 0.0;

        double result1 = safe_pow(a, b);       // Triggers sabotage: pow(0, 0)
        double result2 = safe_sqrt(c);         // Triggers sabotage: sqrt(-9)
        double result3 = safe_log(e);          // Triggers sabotage: log(0)
        double result4 = safe_div(d, e);       // Triggers sabotage: division by zero
        double result5 = safe_pow(2.0, 3.0);   // Normal operation
        double result6 = safe_exp(-1.0);       // New wrapper
        double result7 = safe_fmod(5.5, 2.0);  // New wrapper

        printf("Results:\\n");
        printf("pow(0,0) = %f\\n", result1);
        printf("sqrt(-9) = %f\\n", result2);
        printf("log(0) = %f\\n", result3);
        printf("10/0 = %f\\n", result4);
        printf("2^3 = %f\\n", result5);
        printf("exp(-1) = %f\\n", result6);
        printf("fmod(5.5,2) = %f\\n", result7);

        return 0;
    }
