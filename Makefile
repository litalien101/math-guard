\
    CC = gcc
    CFLAGS = -Wall -O2
    # To enable AVX acceleration uncomment:
    # CFLAGS += -mavx

    OBJS = main.o math_guard.o math_ledger.o

    all: mathguarddemo

    mathguarddemo: $(OBJS)
    \t$(CC) $(CFLAGS) -o mathguarddemo $(OBJS) -lm

    main.o: main.c math_guard.h
    \t$(CC) $(CFLAGS) -c main.c

    math_guard.o: math_guard.c math_guard.h math_ledger.h
    \t$(CC) $(CFLAGS) -c math_guard.c -o math_guard.o

    math_ledger.o: math_ledger.c math_ledger.h
    \t$(CC) $(CFLAGS) -c math_ledger.c -o math_ledger.o

    math_simd.o: math_simd.c math_types.h
    \t$(CC) $(CFLAGS) -c math_simd.c -o math_simd.o

    test: all test_math_guard

    test_math_guard: test/test_math_guard.c math_guard.o math_ledger.o
    \t$(CC) $(CFLAGS) -o test_math_guard test/test_math_guard.c math_guard.o math_ledger.o -lm
    \t# Run test with a fresh logfile
    \tMATH_LEDGER_FILE=test_logs.jsonl ./test_math_guard

    clean:
    \trm -f *.o mathguarddemo test_math_guard test_logs.jsonl math_logs.jsonl
