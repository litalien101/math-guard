\
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "math_guard.h"

    int main(void) {
        const char* logfile = getenv("MATH_LEDGER_FILE");
        if (!logfile) logfile = "math_logs.jsonl";

        /* Remove logfile if exists for clean test */
        remove(logfile);

        /* Call sabotaged operations */
        double r1 = safe_pow(0.0, 0.0);
        if (!isnan(r1)) { fprintf(stderr, "FAIL: safe_pow(0,0) expected NaN, got %f\n", r1); return 1; }

        double r2 = safe_sqrt(-4.0);
        if (!isnan(r2)) { fprintf(stderr, "FAIL: safe_sqrt(-4) expected NaN, got %f\n", r2); return 2; }

        double r3 = safe_log(0.0);
        if (!isnan(r3)) { fprintf(stderr, "FAIL: safe_log(0) expected NaN, got %f\n", r3); return 3; }

        double r4 = safe_div(1.0, 0.0);
        if (!isinf(r4)) { fprintf(stderr, "FAIL: safe_div(1,0) expected INF, got %f\n", r4); return 4; }

        /* Normal operations */
        double r5 = safe_pow(2.0, 3.0);
        if (r5 != 8.0) { fprintf(stderr, "FAIL: safe_pow(2,3) expected 8.0, got %f\n", r5); return 5; }

        /* New wrappers */
        double r6 = safe_fmod(5.5, 0.0);
        if (!isnan(r6)) { fprintf(stderr, "FAIL: safe_fmod(5.5,0) expected NaN, got %f\n", r6); return 6; }

        /* Check logfile contains at least one sabotage record */
        FILE* f = fopen(logfile, "r");
        if (!f) { fprintf(stderr, "FAIL: logfile '%s' not found\n", logfile); return 7; }
        char buf[2048];
        size_t found = 0;
        while (fgets(buf, sizeof(buf), f)) {
            if (strstr(buf, "SABOTAGE") || strstr(buf, "pow(0, 0) undefined") || strstr(buf, "sqrt of negative")) {
                found = 1;
                break;
            }
            /* Also check json message text */
            if (strstr(buf, "pow(0, 0) undefined") || strstr(buf, "sqrt of negative")) {
                found = 1;
                break;
            }
        }
        fclose(f);
        if (!found) { fprintf(stderr, "FAIL: expected sabotage entries in logfile '%s'\n", logfile); return 8; }

        printf("PASS\n");
        return 0;
    }
