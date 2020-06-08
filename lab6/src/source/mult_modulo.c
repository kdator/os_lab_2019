#include <unistd.h>
#include "mult_modulo.h"

uint64_t MultModulo( uint64_t a, uint64_t b, uint64_t mod, uint64_t presentable )
{
    if (!presentable) {
        uint64_t result = 0;
        a = a % mod;
        while (b > 0) {
            if (b % 2 == 1)
            result = (result + a) % mod;
            a = (a * 2) % mod;
            b /= 2;
        }
        return result % mod;
    }
    int result = 1;
    for (size_t i = a; i < b; i++) {
        result *= (i + 1);
    }
    return result;
}
