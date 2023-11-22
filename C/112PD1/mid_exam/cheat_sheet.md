#### 4

```c
#include <stdio.h>
#define MAX 100

int pureRecursive(int n) {
    if (n <= 2)
        return n;
    else
        return pureRecursive(n - 1) + pureRecursive(n - 2) + pureRecursive(n - 3);
}

int iterative(int n) {
    if (n <= 2)
        return n;
    int i0 = 0, i1 = 1, i2 = 2, j;
    for (int i = 3; i <= n; i++) {
        j = i0 + i1 + i2;
        i0 = i1;
        i1 = i2;
        i2 = j;
    }
    return j;
}

int temp[MAX], record = 7;

int tempRecursive(int n) {
    if (record & (1 << n))
        ;
    else {
        temp[n] = tempRecursive(n - 1) + tempRecursive(n - 2) + tempRecursive(n - 3);
        record |= (1 << n);
    }
    return temp[n];
}

int main() {
    for (int i = 0; i < 10; i++)
        printf("%d ", pureRecursive(i));
    puts("");
    for (int i = 0; i < 10; i++)
        printf("%d ", iterative(i));
    puts("");
    temp[0] = 0;
    temp[1] = 1;
    temp[2] = 2;
    for (int i = 0; i < 10; i++)
        printf("%d ", tempRecursive(i));
    puts("");
    return 0;
}
```

#### 5

```c
#include <limits.h>
#include <stdio.h>

void check(int a, int b) {
    if (b > 0 && a > INT_MAX - b)
        puts("overflow");
    else if (b < 0 && a < INT_MIN - b)
        puts("overflow");
    else
        puts("no overflow");
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    check(a, b);
    return 0;
}
```

#### 6

```c
#include <stdio.h>

int main() {
    int x = 0; //a
    if (x = 1)
        printf("%d\n", x);

    x = (3 < 2) ? 3 : (2 > 1) ? 2 //b
                              : 1;
    printf("%d\n", x);

    x = 1; //c
    printf("%d\n", x);
    {
        int x = 2, y = 3;
        printf("%d %d\n", x, y);
    }
    /* printf("%d %d\n", x, y); */

    //d
    /* for (x = 2;x = 1;x = 0) */
    /*     printf("%d\n", x); */

    //e
    /* int i = 0; */
    while (i < 10) {
        i++;
        break;
    }
    printf("%d\n", i);
    return 0;
}
```

#### 7

```c
#include <stdio.h>
#define n 4

void range(int I[n][2], int v, int *R[n]) {
    for (int i = 0; i < n; i++)
        if (v >= I[i][0] && v <= I[i][1])
            R[i] = I[i];
}

int main() {
    int I[n][2] = {{3, 19}, {11, 33}, {18, 80}, {80, 100}}, *R[n] = {0};
    range(I, 18, R);
    for (int i = 0; i < n; i++) {
        if (R[i] == 0)
            continue;
        printf("%2d %2d\n", R[i][0], R[i][1]);
    }
    return 0;
}
```

#### 8

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv) {
    srand(time(0));
    int n = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);
    for (int i = 0; i < n; i++)
        printf("%d ", rand() % (max - min + 1) + min);
    puts("");
    return 0;
}
```

#### 9

```c
#include <stdio.h>

int main() {
    char c = getchar();
    getchar();
    unsigned address = 0;
    int byte[4] = {0};
    if (c == 'a') {
        scanf("%d.%d.%d.%d", &byte[0], &byte[1], &byte[2], &byte[3]);
        /* address |= (byte[0] << 24); */
        /* address |= (byte[1] << 16); */
        /* address |= (byte[2] << 8); */
        /* address |= byte[3]; */
        for (int i = 0; i < 4; i++)
            address |= (byte[i] << (24 - 8 * i));
        for (int i = 0; i < 32; i++)
            if (address & (1 << (31 - i)))
                putchar('1');
            else
                putchar('0');
        puts("");
    }

    if (c == 'b') {
        for (int i = 0; i < 32; i++) {
            char bit = getchar();
            if (bit - '0')
                address |= (1 << (31 - i));
        }
        /** for (int i = 0; i < 4; i++) */
        /**     byte[i] = (address >> (24 - 8 * i)) & 255; */
        for (int i = 0; i < 4; i++) {
            byte[3 - i] = address & 255;
            address >>= 8;
        }
        printf("%d.%d.%d.%d\n", byte[0], byte[1], byte[2], byte[3]);
    }
    return 0;
}
```

#### 10

```c
#include <stdio.h>

int main() {
    int i;
    float f = 2;
    /* 3 */
    /* switch (i) */
    /* case i: */
    /*     puts("case 1"); */

    /* 4 */
    switch (i)
    default:
        puts("Ex1: default");

    /* 5 */
    switch (i) {}

    /* 6 */
    /* switch (f) {} */
    return 0;
}
```

#### anagram_checker

```c
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void areAnagrams(char str1[], char str2[]) {
    /* Your own expression */
    if (strlen(str1) != strlen(str2)) {
        puts("No, the strings are not anagrams.");
        return;
    }
    int length = strlen(str1);
    for (int i = 0; i < length; i++) {
        bool notIn1 = true, notIn2 = true;
        for (int j = 0; j < length; j++) {
            if (str1[i] == str2[j])
                notIn1 = false;
            if (str2[i] == str1[j])
                notIn2 = false;
        }
        if (notIn1 || notIn2) {
            puts("No, the strings are not anagrams.");
            return;
        }
    }
    puts("Yes, the strings are anagrams.");
}

int main() {
    char str1[100], str2[100];
    scanf("%s", str1);
    scanf("%s", str2);
    areAnagrams(str1, str2);
    return 0;
}
```

#### decimalToBinary

```c
#include <math.h>
#include <stdio.h>

void decimalToBinary(int num) {
    int maxBit = log2(num);
    /* for (int i = 31; i >= 0; i--) */
    for (int i = maxBit; i >= 0; i--)
        if (num & (1 << i))
            putchar('1');
        else
            putchar('0');
    puts("");
}

int main() {
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    decimalToBinary(num);

    return 0;
}
```

#### expextedValue

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Using rand() to generate a random number between 1 and 6.
double rollDice(int roll) {
    int sum = 0;
    for (int i = 0; i < roll; i++)
        sum += rand() % 6 + 1;
    return (double)sum / roll;
}

int main() {
    srand(time(0));

    printf("The Expected Value is %lf\n", rollDice(10000));

    return 0;
}
```

#### GCD

```c
#include <stdio.h>
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

int GCD_recursion(int p, int q) {
    /* int r; */
    int r = p % q;
    printf("%2d %2d %2d\n", p, q, r);
    /* if ((r = p % q) == 0) */
    if (r == 0)
        return q;
    else
        return GCD_recursion(q, r);
}

int GCD_loop(int p, int q) {
    while (p > 0 && q > 0) {
        int r = p % q;
        printf("%2d %2d %2d\n", p, q, r);
        if (r == 0)
            return q;
        p = q;
        q = r;
    }
}

int main() {
    printf("Please input two integer and get their GCD(greastest common divisor).\n");
    int n, m, gcd;
    scanf("%d%d", &n, &m);
    puts("recursion");
    printf("The GCD of the two numbers is %d.\n", GCD_recursion(m, n));
    puts("loop");
    printf("The GCD of the two numbers is %d.\n", GCD_loop(m, n));

    return 0;
}
```

#### limits

```c
#include <limits.h>
#include <stdio.h>

int main() {
    printf("INT_MIN(2^31-1): %d\nINT_MAX(-2^31): %d\n", INT_MIN, INT_MAX);
    printf("UINT_MAX(2^32-1): %u\n", UINT_MAX);
    printf("LLONG_MIN(2^63-1): %lld\nLLONG_MAX(-2^63): %lld\n", LLONG_MIN, LLONG_MAX);
    /* INT_MIN(2^31-1): -2147483648 */
    /* INT_MAX(-2^31): 2147483647 */
    /* UINT_MAX(2^32-1): 4294967295 */
    /* LLONG_MIN(2^63-1): -9223372036854775808 */
    /* LLONG_MAX(-2^63): 9223372036854775807 */
    return 0;
}
```

#### permutation_using_recursion

```c
#include <stdio.h>

int answer[8], used = 0;

void permutation(int cnt) {
    /* printf("%d call\n",cnt); */
    if (cnt == 8) {
        for (int i = 0; i < 8; i++)
            printf("%d ", answer[i]);
        puts("");
        /* printf("%d return\n",cnt); */
        return;
    }
    for (int i = 1; i <= 8; i++) {
        if (~used & (1 << (i - 1))) {
            answer[cnt] = i;
            used |= (1 << (i - 1));
            permutation(cnt + 1);
            used &= ~(1 << (i - 1));
        }
    }
}

int main() {
    permutation(0);
    return 0;
}
```

#### quickSort

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))
#define SIZE 10

/* void swap(int *a, int *b) { */
/*     int temp = *a; */
/*     *a = *b; */
/*     *b = *a; */
/* } */

void print(int *array) {
    for (int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
    puts("");
}

void quickSort(int array[], int leftest, int rightest) {
    if (leftest < rightest) {
        int key = array[(leftest + rightest) / 2];
        int left_index = leftest - 1;
        int right_index = rightest + 1;

        while (1) {
            while (array[++left_index] < key)
                ;
            /* find left */
            while (array[--right_index] > key)
                ;
            /* find right */
            if (left_index >= right_index)
                break;
            swap(array[left_index], array[right_index]);
        }
        quickSort(array, leftest, left_index - 1);     //recursive at left
        quickSort(array, right_index + 1, rightest); //recursive at right
    }
}

int main(void) {
    srand(time(0));
    int array[SIZE];
    for (int i = 0; i < SIZE; i++)
        array[i] = rand() % 10;

    quickSort(array, 0, SIZE - 1);

    for (int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);
    puts("");
    return 0;
}
```

#### truthTable

```c
#include <stdio.h>
#define N 3

int record[N];

void truthTableGen(int n) {
    if (n == 0) {
        for (int i = 0; i < N; i++)
            printf("%d ", record[i]);
        puts("");
    } else {
        for (int i = 0; i < 2; i++) {
            record[N - n] = i;
            truthTableGen(n - 1);
        }
    }
}

int main() {
    truthTableGen(N);
    return 0;
}
```
