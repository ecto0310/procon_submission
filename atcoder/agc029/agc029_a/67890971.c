// Date: Fri, 25 Jul 2025 11:15:54 +0000
// Language: C (gcc 12.2.0)
#include <stdio.h>
#include <string.h>

int main() {
    char S[200001];
    scanf("%s", S);

    long long countB = 0;
    long long result = 0;
    int len = strlen(S);

    for (int i = 0; i < len; i++) {
        if (S[i] == 'B') {
            countB++;
        } else {
            result += countB;
        }
    }
    printf("%lld\n", result);

    return 0;
}
