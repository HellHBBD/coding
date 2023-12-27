---
marp: true
theme: uncover
class: invert
paginate: true
---

簡化取出最前面`d`個bits的巨集。

```c
#define firstBits(n, d) ((n) >> (32 - (d)))
```

- 宣告成全域變數，不用另外傳參數。
- `head`用來存未分類的prefix，再把`head`的資料分類到`group`裡面。

```c
struct prefix *head = 0;
struct prefix **group = 0;
int d = 0;
char *input_file, *insert_file, *delete_file, *search_file;
unsigned long long begin, end;
```

---

- 用5個bytes的的`unsigned char []`存4個bytes的`unsigned`和1個byte的`unsigned char`，讀取完直接`memcpy()`即可。
- 不過因為位元組順序的關係，要反過來讀。

```c
void input() {
    FILE *init = fopen(input_file, "r");
    unsigned char temp[5];
    int count = 0;
    struct prefix *current = 0;
    while (1) {
        int scanCount = fscanf(init, "%hhu.%hhu.%hhu.%hhu/%hhu", temp + 3, temp + 2, temp + 1, temp, temp + 4);
```

---

- 如果只讀到前四個，表示沒有給`len`，從第四個到第一個byte依序判斷有沒有值。

- 如果沒有讀到東西就計算總prefixes並關檔。

```c
        if (scanCount == 4) {
            temp[4] = temp[3] ? 32 : temp[2] ? 24
                                   : temp[1] ? 16
                                   : temp[0] ? 8
                                             : 0;
        } else if (scanCount == -1) {
            printf("The total number of prefixes in the input file is : %d.\n", count);
            fclose(init);
            return;
        }
```

---

如果`current`有值表示前面已經有prefix了，可以直接新增。

```c
        if (current) {
            current->next = malloc(sizeof(struct prefix));
            count++;
            current = current->next;
            memcpy(&current->ip, temp, 4);
            current->len = temp[4];
            current->next = 0;
        }
```

---

反之需要特別對`head`處理。

```c
        else {
            head = malloc(sizeof(struct prefix));
            current = head;
            count++;
            memcpy(&current->ip, temp, 4);
            current->len = temp[4];
            current->next = 0;
        }
    }
}
```

---

計算特定`len`的個數。

```c
void length_distribution(int i) {
    int count = 0;
    for (struct prefix *current = head; current; current = current->next)
        if (current->len == i)
            count++;
    printf("The number of prefixes with prefix length %d = %d.\n", i, count);
}
```

---

初始化`group`，和不同bit組合的頭(含special group)。

```c
void segment(int d) {
  int size = (1 << d);
    group = malloc(sizeof(struct prefix *) * size + 1);
    for (int i = 0; i < size; i++) {
        group[i] = malloc(sizeof(struct prefix));
        group[i]->ip = (i << (32 - d));
        group[i]->len = d;
        group[i]->next = 0;
    }
    group[size] = malloc(sizeof(struct prefix));
    group[size]->ip = 0;
    group[size]->len = 0;
    group[size]->next = 0;
```

---

- 把`head`的所有資料分類的到`group`裡面。

- 先判斷是否是special group，如果不是再找符合的`group`。

```c
    int i;
    for (struct prefix *current = head; current;) {
        head = current->next;
        i = 0;
        if (current->len < d)
            i = size;
        else
            while (firstBits(group[i]->ip, d) != firstBits(current->ip, d))
                i++;
```

---

因為同個`group`需要排序，要找到適合的位子再插入。

```c
        struct prefix *currentPrefix = group[i];
        while (currentPrefix->next && currentPrefix->next->ip < current->ip)
            currentPrefix = currentPrefix->next;
        current->next = currentPrefix->next;
        currentPrefix->next = current;
        current = head;
    }
}
```

---

讀檔部分同`input()`，不過要在`fscanf()`前開始計算clock cycle。

```c
void prefix_insert() {
 FILE *insert = fopen(insert_file, "r");
    unsigned char temp[5];
    int count = 0;
    int size = (1 << d);
    while (1) {
        begin = rdtsc();
        int scanCount = fscanf(insert, "%hhu.%hhu.%hhu.%hhu/%hhu", temp + 3, temp + 2, temp + 1, temp, temp + 4);
        if (scanCount == 4) {
            temp[4] = temp[3] ? 32 : temp[2] ? 24
                                   : temp[1] ? 16
                                   : temp[0] ? 8
                                             : 0;
        } else if (scanCount == -1) {
            fclose(insert);
            return;
        }
```

---

剩下也跟`input()`類似，差異是在`input()`是從`head`裡面找`current`，而`prefix_insert()`是從檔案中讀完直接`malloc()`。

```c
        struct prefix *current = malloc(sizeof(struct prefix));
        memcpy(&current->ip, temp, 4);
        current->len = temp[4];
        current->next = 0;

        int i = 0;
        if (current->len < d)
            i = size;
        else
            while (firstBits(group[i]->ip, d) != firstBits(current->ip, d))
                i++;
```

---

insert結束停止計算clock cycle。

```c
        struct prefix *currentPrefix = group[i];
        while (currentPrefix->next && currentPrefix->next->ip < current->ip)
            currentPrefix = currentPrefix->next;
        current->next = currentPrefix->next;
        currentPrefix->next = current;

        end = rdtsc();
        printf("%llu\n", (end - begin));
    }
}
```

---

讀檔部分同`input()`，不過要在`fscanf()`前開始計算clock cycle。

```c
void prefix_delete() {
    FILE *delete = fopen(delete_file, "r");
    unsigned char temp[5];
    int count = 0;
    int size = (1 << d);
    while (1) {
        begin = rdtsc();
        int scanCount = fscanf(delete, "%hhu.%hhu.%hhu.%hhu/%hhu", temp + 3, temp + 2, temp + 1, temp, temp + 4);
        if (scanCount == 4) {
            temp[4] = temp[3] ? 32 : temp[2] ? 24
                                   : temp[1] ? 16
                                   : temp[0] ? 8
                                             : 0;
        } else if (scanCount == -1) {
            fclose(delete);
            return;
        }
```

---

1. 只要用個`unsigned`和`unsigned char`存讀進來的資料即可。

2. 尋找`group`的部分和先前兩個function差不多

```c
        unsigned ip;
        memcpy(&ip, temp, 4);
        unsigned char len = temp[4];
        int i = 0;
        if (len < d)
            i = size;
        else
            while (firstBits(group[i]->ip, d) != firstBits(ip, d))
                i++;
```

---

把找到的prefix刪掉，並停止計算clock cycle。

```c
        struct prefix *previous;
        struct prefix *current = group[i]->next;
        while (current && current->ip != ip) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        free(current);
        current = 0;

        end = rdtsc();
        printf("%llu\n", (end - begin));
    }
}
```

---

讀檔部分同`input()`，不過要在`fscanf()`前開始計算clock cycle。

```c
void search() {
    FILE *search = fopen(search_file, "r");
    unsigned char temp[5];
    int size = (1 << d);
    while (1) {
        begin = rdtsc();
        int scanCount = fscanf(search, "%hhu.%hhu.%hhu.%hhu/%hhu", temp + 3, temp + 2, temp + 1, temp, temp + 4);
        if (scanCount == 4) {
            temp[4] = temp[3] ? 32 : temp[2] ? 24
                                   : temp[1] ? 16
                                   : temp[0] ? 8
                                             : 0;
        } else if (scanCount == -1) {
            fclose(search);
            return;
        }
```

---

與`prefix_delete()`類似，只要`unsigned`和`unsigned char`存即可。

```c
        unsigned ip;
        memcpy(&ip, temp, 4);
        unsigned char len = temp[4];
        int i = 0;
        if (len < d)
            i = size;
        else
            while (firstBits(group[i]->ip, d) != firstBits(ip, d))
                i++;
```

---

找到就直接跳出迴圈，所以如果`current`是null pointer表示沒有找到，結束停止計算clock cycle。

```c
        struct prefix *current = group[i]->next;
        while (current && current->ip != ip)
            current = current->next;
        if (current)
            puts("successful");
        else
            puts("failed");

        end = rdtsc();
        printf("%llu\n", (end - begin));
    }
}
```

---

計算每個`group`的prefix數量。

```c
void print() {
    int size = (1 << d);
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (struct prefix *printNode = group[i]->next; printNode; printNode = printNode->next)
            count++;
        printf("The number of prefixes in group %d = %d\n", i, count);
    }
}
```

---

把`head`和`group`裡面所有的prefixes都刪掉。

```c
void clear() {
    for (struct prefix *deleteNode = head; deleteNode; deleteNode = head) {
        head = head->next;
        free(deleteNode);
    }
    head = 0;
    int size = (1 << d);
    for (int i = 0; i < size + 1 && group; i++) {
        for (struct prefix *deleteNode = group[i]; deleteNode; deleteNode = group[i]) {
            group[i] = group[i]->next;
            free(deleteNode);
        }
    }
    free(group);
}
```

---

初始化檔案名稱和d並把初始資料讀進來。

```c
int main(int arvc, char **argv) {
    input_file = argv[1];
    insert_file = argv[2];
    delete_file = argv[3];
    search_file = argv[4];
    d = atoi(argv[5]);
    input();
```

---

照順序呼叫函式。

```c
    for (int i = 0; i <= 32; i++)
        length_distribution(i);
    segment(d);
    /* print(); */
    prefix_insert();
    prefix_delete();
    search();
    clear();
    return 0;
}
```

---

---

---
