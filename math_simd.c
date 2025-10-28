\
    // Optional SIMD acceleration (x86 AVX)
    #include "math_types.h"

    #if defined(__AVX__)
    #include <immintrin.h>

    void simdsqrtf32(const f32* input, f32* output, int count) {
        int i = 0;
        for (; i + 8 <= count; i += 8) {
            __m256 vec = _mm256_loadu_ps(&input[i]);
            __m256 res = _mm256_sqrt_ps(vec);
            _mm256_storeu_ps(&output[i], res);
        }
        for (; i < count; ++i) {
            output[i] = sqrtf(input[i]);
        }
    }
    #else
    #include <math.h>
    void simdsqrtf32(const f32* input, f32* output, int count) {
        for (int i = 0; i < count; ++i) {
            output[i] = sqrtf(input[i]);
        }
    }
    #endif
