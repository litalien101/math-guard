\
    #ifndef MATH_LEDGER_H
    #define MATH_LEDGER_H

    /* Writes a sabotage record (human-readable to stderr and JSON-line to file).
     * Set MATH_LEDGER_FILE environment variable to change file path.
     */
    void log_sabotage(const char* message);

    #endif // MATH_LEDGER_H
