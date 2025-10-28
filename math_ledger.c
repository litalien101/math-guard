\
    #include <stdio.h>
    #include <time.h>
    #include <string.h>
    #include <stdlib.h>
    #include <errno.h>

    #include "math_ledger.h"

    static const char* default_logfile = "math_logs.jsonl";

    static void iso8601_timestamp(char* buf, size_t buflen) {
        time_t now = time(NULL);
        struct tm t;
        #if defined(_WIN32) || defined(_WIN64)
            gmtime_s(&t, &now);
        #else
            gmtime_r(&now, &t);
        #endif
        strftime(buf, buflen, "%Y-%m-%dT%H:%M:%SZ", &t);
    }

    void log_sabotage(const char* message) {
        char timestamp[64] = {0};
        iso8601_timestamp(timestamp, sizeof(timestamp));

        /* Human-friendly stderr */
        fprintf(stderr, "[%s] SABOTAGE: %s\n", timestamp, message);

        /* JSON-line append to file. File path can be overridden via env var MATH_LEDGER_FILE */
        const char* logfile = getenv("MATH_LEDGER_FILE");
        if (!logfile) logfile = default_logfile;

        FILE* f = fopen(logfile, "a");
        if (!f) {
            /* If file can't be opened, emit an error to stderr but don't abort program */
            fprintf(stderr, "[%s] ERROR: unable to open ledger file '%s' (%s)\n", timestamp, logfile, strerror(errno));
            return;
        }
        /* Minimal JSON-line with timestamp and message. Messages are escaped simply. */
        /* Escape double quotes and backslashes in message */
        char esc_msg[1024];
        size_t oi = 0;
        for (size_t i = 0; message[i] != '\\0' && oi + 2 < sizeof(esc_msg); ++i) {
            if (message[i] == '\"' || message[i] == '\\\\') {
                esc_msg[oi++] = '\\\\';
                esc_msg[oi++] = message[i];
            } else {
                esc_msg[oi++] = message[i];
            }
        }
        esc_msg[oi] = '\\0';

        fprintf(f, "{\"timestamp\":\"%s\",\"message\":\"%s\"}\n", timestamp, esc_msg);
        fclose(f);
    }
