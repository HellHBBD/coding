---
marp: true
theme: uncover
class: invert
paginate: true
---

題目要求：
把三種不同的函式用function pointer傳入另一個函式
實現不同的運算方式。

---

把`double (*)(double,int)`定義成`F`

```c
typedef double (*F)(double, int);
```

---

把`n = 0`當成終止條件，如果`n < 0`就向上遞迴，`n > 0`則下向遞迴，讓`power()`可以接受所有整數的`n`。

```c
double power(double x, int n) {
    if (n > 0)
        return x * power(x, n - 1);
    else if (n < 0)
        return (1 / x) * power(x, n + 1);
    else
        return 1;
}
```

---

直接回傳相乘的結果。

```c
double multiply(double x, int n) {
    return x * n;
}
```

---

直接回傳相除的結果。

```c
double divide(double x, int n) {
    return x / n;
}
```

---

`x`和`n`的運算交給傳進來的`function()`，接著把運算結果`m`次方。

```c
double powerpower(F function, double x, int n, int m) {
    return power(function(x, n), m);
}
```

---

預設參數的格式為`./a.out x n m`，依序把字串轉成數字，在使用`powerpower()`的分別使用`power()`、`multiply()`、`divide()`測試。

```c
int main(int argc, char **argv) {
    double x = atof(argv[1]);
    int n = atoi(argv[2]);
    int m = atoi(argv[3]);
    printf("call powerpower() with power(): %lf\n", powerpower(power, x, n, m));
    printf("call powerpower() with multiply(): %lf\n", powerpower(multiply, x, n, m));
    printf("call powerpower() with divide(): %lf\n", powerpower(divide, x, n, m));
    return 0;
}
```