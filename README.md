/////////////////////
计算最大公约数的函数
int calculateGCD(int m, int n)
{
    while (m != n)
    {
        if (m > n)
        {
            m = m - n;
        }
        else
        {
            n = n - m;
        }
    }
    return m;
}

/////////////
 计算最小公倍数的函数
int calculateLCM(int m, int n)
{
    return (m * n) / calculateGCD(m, n);
}
//////////////
哥德巴赫猜想

# include <stdio.h>

// 判断一个数是否为素数
int is_prime(int num) {
    if (num < 2) {
        return 0; // 不是素数
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0; // 不是素数0
        }
    }
    return 1; // 是素数1
}

void goldbach_conjecture(int n) {
    if (n % 2 != 0 || n <= 2) {
        return;
    }
    for (int p = 2; p <= n / 2; ++p) {
        int q = n - p;
        if (is_prime(p) && is_prime(q)) {
            printf("%d = %d + %d\n", n, p, q);
            return;
        }
    }
}

int main(void) {
    int N;

    scanf("%d", &N);
    goldbach_conjecture(N);

    return 0;
}
//////////////////////////////


排序

# include <stdio.h>

// 冒泡排序函数
void bubbleSort(int arr[], int n) {
    // 外层循环控制比较轮数
    for (int i = 0; i < n - 1; i++) {
        // 内层循环控制每一轮比较的次数
        for (int j = 0; j < n - i - 1; j++) {
            // 如果前一个元素比后一个元素大，交换它们
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 主函数
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 调用冒泡排序函数
    bubbleSort(arr, n);

    // 打印排序后的数组
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
3. 选择排序（Selection Sort）：
# include <stdio.h>

// 选择排序函数
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // 找到未排序部分的最小元素的索引
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // 将找到的最小元素与当前位置交换
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// 主函数
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 调用选择排序函数
    selectionSort(arr, n);

    // 打印排序后的数组
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
这两种排序算法也都带有详
# include <stdio.h>

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 获取划分点的位置
        int pivotIndex = partition(arr, low, high);

        // 递归调用左半部分和右半部分
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// 划分函数
int partition(int arr[], int low, int high) {
    // 选取最右边的元素作为基准值
    int pivot = arr[high];
    int i = low - 1;

    // 将小于基准值的元素放到左侧，大于基准值的元素放到右侧
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // 交换 arr[i] 和 arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 交换 arr[i+1] 和 arr[high]，将基准值放到正确位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // 返回基准值的位置
    return i + 1;
}

// 主函数
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 调用快速排序函数
    quickSort(arr, 0, n - 1);

    // 打印排序后的数组
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

////////查找书籍

# include <stdio.h>
# include <string.h>

struct BookAndPrice {
    char name[300];
    double price;
};

int main() {
    struct BookAndPrice now, max, min;

    max.price = 0;
    min.price = 9999999999999;
    int n, i;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        getchar();
        gets(now.name);
        scanf("%lf", &now.price);

        if (now.price > max.price) {
            strcpy(max.name, now.name);
            max.price = now.price;
        }
        
        if (now.price < min.price) {
            strcpy(min.name, now.name);
            min.price = now.price;
        }
    }

    printf("%.2lf, %s\n%.2lf, %s", max.price, max.name, min.price, min.name);

    return 0;
}
///////////////////水仙花

int narcissistic(int number)
{
    int sum = 0;
    int temp = number;
    int n = 0;

    // 计算number的位数
    while (temp != 0)
    {
        temp /= 10;
        n++;
    }

    temp = number;
    while (temp != 0)
    {
        int digit = temp % 10;
        sum += pow(digit, n);
        temp /= 10;
    }

    return sum == number;
}

void PrintN(int m, int n)
{
    for (int i = m + 1; i < n; i++)
    {
        if (narcissistic(i))
        {
            printf("%d\n", i);
        }
    }
}
////////////////字符定位（最后一次找到的字符）
# include <stdio.h>
char *match(char*s, char ch);

int main(void )
{
    char ch, str[80], *p = NULL;

    scanf("%s", str);
    getchar();                 /* 跳过输入字符串和输入字符之间的分隔符 */
    ch = getchar();          /* 输入一个字符 */
    p = match(str, ch);     /* 调用函数match() */
    if( p != NULL ){        /* 找到字符ch */
        printf("%s\n", p);
    }else{ 
        printf("Not Found.\n");
    }

    return 0;
}
char *match(char*s, char ch)
{
    char *result = NULL;

    while (*s != '\0')
    {
        if (*s == ch)
        {
            result = s; // 找到字符ch时，更新result为当前位置
        }
        s++;
    }

    return result;
}
//////////////////分类统计字符
void StringCount(char s[])
{
    int letter = 0, blank = 0, digit = 0, other = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            letter++;
        }
        else if (s[i] == ' ' || s[i] == '\n')
        {
            blank++;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            digit++;
        }
        else
        {
            other++;
        }
        i++;
    }

    // 输出统计结果
    printf("letter = %d, blank = %d, digit = %d, other = %d\n", letter, blank, digit, other);
}
////////////交换最值
# include <stdio.h>

int main() {
    int i, n, arr[10], minIndex = 0, temp;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    temp = arr[minIndex];
    arr[minIndex] = arr[0];
    arr[0] = temp;

    minIndex = 0;
    for (i = 1; i < n; i++) {
        if (arr[i] > arr[minIndex]) {
            minIndex = i;
        }
    }

    temp = arr[minIndex];
    arr[minIndex] = arr[n - 1];
    arr[n - 1] = temp;

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
////////////////循环链表
# include <stdio.h>
# include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void show(struct Node*r);//show data    需要完成的函数

int main(){
    int n,m;scanf("%d%d",&n,&m);
    struct Node *p=fun(n,m));//创建按出列顺序排列的循环单链表，返回指向尾元素的指针：测试程序提供
    show(p);//调用显示函数显示数据   该函数需要编程完成
    return 0;
}
/* 请在这里填写答案 */
void show(struct Node *r) {
    if (r) {
        struct Node*current = r->next;
        int isFirst = 1;
        printf("[");
        while (current != r->next || isFirst) {
            if (isFirst) {
                isFirst = 0;
                printf("%d", current->data);
            } else {
                printf(",%d", current->data);
            }
            current = current->next;
        }
        printf("]");
    } else {
        printf("[]\n");
    }
}




fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';  // 去掉换行符
///////字符串压缩
// 字符串压缩函数
void zip(char *p) {
    int len = strlen(p);

    if (len <= 1) {
        // 字符串为空或只有一个字符，无需压缩
        return;
    }

    char result[MAXS * 2];  // 用于存储压缩后的字符串
    int count = 1;          // 用于计数重复字符的个数

    int j = 0;  // 用于遍历压缩后的字符串

    for (int i = 0; i < len; i++) {
        if (p[i] == p[i + 1]) {
            // 如果当前字符与下一个字符相同，增加计数
            count++;
        } else {
            // 如果不同，将字符和计数添加到压缩后的字符串中
            result[j++] = p[i];

            if (count > 1) {
                // 只有当计数大于1时，才添加计数值
                result[j++] = count + '0';
                count = 1;  // 重置计数
            }
        }
    }

    result[j] = '\0';  // 添加字符串结束符

    // 将压缩后的字符串复制回原始字符串
    strcpy(p, result);
}
//////二分查找

// 查找函数
int Bsearch(int *p, int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (p[mid] == x) {
            // 找到目标值，返回下标
            return mid;
        } else if (p[mid] < x) {
            // 目标值在右半部分
            low = mid + 1;
        } else {
            // 目标值在左半部分
            high = mid - 1;
        }
    }

    // 没有找到目标值，返回-1
    return -1;
}
///////////成绩排序
# include <stdio.h>
# include <string.h>

typedef struct {
    char name[21];
    int score;
} Student;

void sortStudents(Student students[], int n);

int main() {
    int n;
    scanf("%d", &n);

    Student students[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
    }

    sortStudents(students, n);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", students[i].name, students[i].score);
    }

    return 0;
}

void sortStudents(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].score < students[j + 1].score || (students[j].score == students[j + 1].score && strcmp(students[j].name, students[j + 1].name) > 0)) {
                // 交换两个学生的位置
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
//////////计算两个点
# include <stdio.h>
# include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double calculateDistance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) *(p1.x - p2.x) + (p1.y - p2.y)* (p1.y - p2.y));
}

int main() {
    int n;
    scanf("%d", &n);

    Point points[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double minDistance = -1;  // 初始化为负数，确保第一对点的距离一定会被记录
    Point minPoint1, minPoint2;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double distance = calculateDistance(points[i], points[j]);
            if (minDistance == -1 || distance < minDistance) {
                minDistance = distance;
                minPoint1 = points[i];
                minPoint2 = points[j];
            }
        }
    }

    // 按照规定输出结果
    if (minPoint1.x + minPoint1.y <= minPoint2.x + minPoint2.y) {
        printf("(%.2lf,%.2lf),(%.2lf,%.2lf),miniDist=%.3lf\n", minPoint1.x, minPoint1.y, minPoint2.x, minPoint2.y, minDistance);
    } else {
        printf("(%.2lf,%.2lf),(%.2lf,%.2lf),miniDist=%.3lf\n", minPoint2.x, minPoint2.y, minPoint1.x, minPoint1.y, minDistance);
    }

    return 0;
}
/////////////////考试座位号
# include <stdio.h>
# include <math.h>

typedef struct {
    double x;
    double y;
} Point;

double calculateDistance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) *(p1.x - p2.x) + (p1.y - p2.y)* (p1.y - p2.y));
}

int main() {
    int n;
    scanf("%d", &n);

    Point points[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double minDistance = -1;  // 初始化为负数，确保第一对点的距离一定会被记录
    Point minPoint1, minPoint2;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double distance = calculateDistance(points[i], points[j]);
            if (minDistance == -1 || distance < minDistance) {
                minDistance = distance;
                minPoint1 = points[i];
                minPoint2 = points[j];
            }
        }
    }

    // 按照规定输出结果
    if (minPoint1.x + minPoint1.y <= minPoint2.x + minPoint2.y) {
        printf("(%.2lf,%.2lf),(%.2lf,%.2lf),miniDist=%.3lf\n", minPoint1.x, minPoint1.y, minPoint2.x, minPoint2.y, minDistance);
    } else {
        printf("(%.2lf,%.2lf),(%.2lf,%.2lf),miniDist=%.3lf\n", minPoint2.x, minPoint2.y, minPoint1.x, minPoint1.y, minDistance);
    }

    return 0;
}
///////极坐标
void ToCoord(double *x, double*y, double r, double theta) {
    *x = r* cos(theta);
    *y = r* sin(theta);
}
////////#include "string.h"
void strmcpy(char *t, int m, char*s) {
    int i, j;

    // 初始化目标字符串为空串
    s[0] = '\0';

    // 如果 m 超过输入字符串长度，直接返回空串
    if (m > strlen(t))
        return;

    // 从第 m 个字符开始复制到目标字符串
    for (i = m - 1, j = 0; t[i] != '\0'; i++, j++) {
        s[j] = t[i];
    }

    // 添加字符串结束符
    s[j] = '\0';
}
///////

// 计算并输出菲波那契数列前N项
void printFibonacci(int N) {
    long long fib[N];  // 使用长整型数组存储菲波那契数列

    fib[0] = fib[1] = 1;

    // 计算并存储前N项的菲波那契数列
    for (int i = 2; i < N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // 输出结果，每行5个数字，每个数字占11位
    for (int i = 0; i < N; i++) {
        printf("%11lld", fib[i]);

        // 每行输出5个数字
        if ((i + 1) % 5 == 0 || i == N - 1) {
            printf("\n");
        }
    }
}
# include <stdio.h>
# include <ctype.h>

int main() {
    char str[81];
    scanf("%[^#]", str);  // 读取字符串直到遇到#

    // 初始化十六进制字符串和整数结果
    char hexStr[81] = "";
    long long int decimal = 0;

    // 提取十六进制字符并拼接为新的字符串
    for (int i = 0; str[i] != '\0'; i++) {
        if (isxdigit(str[i])) {
            hexStr[i] = tolower(str[i]);
        }
    }

    // 输出滤去非十六进制字符的字符串
    printf("%s\n", hexStr);

    // 将十六进制字符串转换为十进制数
    sscanf(hexStr, "%llx", &decimal);

    // 输出转换后的十进制数
    printf("%lld\n", decimal);

    return 0;
}



# include <stdio.h>

void bubbleSort(int *arr, int*index, int m);
void calculateScores(int [*scores](10), int*result, int m, int n);

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int scores[10][10];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &scores[i][j]);
        }
    }

    int result[10];
    calculateScores(scores, result, m, n);

    for (int i = 0; i < m; i++) {
        printf("%3d", result[i]);
    }

    return 0;
}

void bubbleSort(int *arr, int*index, int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // 交换总分数组元素
                int tempScore = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempScore;

                // 交换对应的选手编号数组元素
                int tempIndex = index[j];
                index[j] = index[j + 1];
                index[j + 1] = tempIndex;
            }
        }
    }
}

void calculateScores(int [*scores](10), int*result, int m, int n) {
    int totalScores[10];

    for (int i = 0; i < m; i++) {
        // 计算每位选手的总分，去掉一个最高分和一个最低分
        int sum = 0, max = scores[i][0], min = scores[i][0];
        for (int j = 0; j < n; j++) {
            sum += scores[i][j];

            if (scores[i][j] > max) {
                max = scores[i][j];
            }

            if (scores[i][j] < min) {
                min = scores[i][j];
            }
        }
        sum = sum - max - min;  // 去掉一个最高分和一个最低分
        totalScores[i] = sum;
    }

    // 初始化选手编号数组
    for (int i = 0; i < m; i++) {
        result[i] = i + 1;
    }

    // 冒泡排序，按总分从高到低排序，并记录对应的选手编号
    bubbleSort(totalScores, result, m);
}
int ChickenRabbit(int *chicken, int*rabbit, int head, int foot){

    int asurabbit = (foot - 2 * head) / 2;
    int asuchicken = head - asurabbit;
    
    
    if (foot % 2 != 0 || head <= 0 || foot <= 0 || head > foot) {
            return 0;  // 无解
        }
    
    
    if (asuchicken < 0 || asurabbit < 0) {
            return 0;  // 无解
        }
    else{
        *chicken = asuchicken;
        *rabbit  = asurabbit;
        return 1;  // 有解
    }

}
/鸡兔同笼// 定义函数 delchar
void delchar(char *s, char ch) {
    // 遍历字符串，使用指针进行操作
    char*ptr = s;
    while (*s != '\0') {
        if (*s != ch) {
            *ptr =*s;  // 将非删除字符移到新的位置
            ptr++;
        }
        s++;
    }
    *ptr = '\0';  // 添加字符串结束符
}
# include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);  // 输入矩阵阶数

    int matrix[6][6];  // 假设矩阵最大为6x6
    int i, j;

    // 输入矩阵元素
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int found_saddle = 0;  // 记录是否找到了鞍点

    // 找鞍点
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int is_saddle = 1;

            // 检查该元素是否在行上最大
            for (int k = 0; k < n; k++) {
                if (matrix[i][j] < matrix[i][k]) {
                    is_saddle = 0;
                    break;
                }
            }

            // 检查该元素是否在列上最小
            for (int k = 0; k < n; k++) {
                if (matrix[i][j] > matrix[k][j]) {
                    is_saddle = 0;
                    break;
                }
            }

            // 如果是鞍点，输出结果
            if (is_saddle) {
                printf("%d %d\n", i, j);
                found_saddle = 1;
                return 0;  // 找到鞍点后结束程序
            }
        }
    }

    // 如果没有找到鞍点，输出 "NONE"
    if (!found_saddle) {
        printf("NONE\n");
    }

    return 0;a
}
鞍点#include <stdio.h>

// 定义函数 hanoi
void hanoi(int n, char source, char target, char auxiliary);

int main() {
    int n;

    // 输入盘子的个数
    scanf("%d", &n);

    // 调用 hanoi 函数求解并输出路径
    hanoi(n, 'a', 'b', 'c');

    return 0;
}

// 定义函数 hanoi
void hanoi(int n, char source, char target, char auxiliary) {
    // 递归终止条件：只有一个盘子时直接搬动即可
    if (n == 1) {
        printf("%c-->%c\n", source, target);
    } else {
        // 将 n-1 个盘子从源座搬到辅助座，目标座作为中转
        hanoi(n - 1, source, auxiliary, target);
        // 将第 n 个盘子从源座搬到目标座
        printf("%c-->%c\n", source, target);
        // 将 n-1 个盘子从辅助座搬到目标座，源座作为中转
        hanoi(n - 1, auxiliary, target, source);
    }
}
# include <stdio.h>

// 定义复数结构体
typedef struct {
    double real;
    double imaginary;
} Complex;

// 函数声明
void complexAddition(Complex c1, Complex c2, Complex *resultSum);
void complexMultiplication(Complex c1, Complex c2, Complex*resultProduct);

int main() {
    // 定义两个复数变量和一个存放计算结果的变量
    Complex c1, c2, resultSum, resultProduct;

    // 输入两个复数的实部和虚部
    scanf("%lf %lf %lf %lf", &c1.real, &c1.imaginary, &c2.real, &c2.imaginary);

    // 调用函数计算两个复数的和与积
    complexAddition(c1, c2, &resultSum);
    complexMultiplication(c1, c2, &resultProduct);

    // 输出结果
    printf("addition of complex is %.6lf+%.6lfi\n", resultSum.real, resultSum.imaginary);
    printf("product of complex is %.6lf+%.6lfi\n", resultProduct.real, resultProduct.imaginary);

    return 0;
}

// 定义函数实现复数的加法
void complexAddition(Complex c1, Complex c2, Complex *resultSum) {
    resultSum->real = c1.real + c2.real;
    resultSum->imaginary = c1.imaginary + c2.imaginary;
}

// 定义函数实现复数的乘法
void complexMultiplication(Complex c1, Complex c2, Complex *resultProduct) {
    resultProduct->real = c1.real* c2.real - c1.imaginary *c2.imaginary;
    resultProduct->imaginary = c1.real* c2.imaginary + c2.real * c1.imaginary;
}
# include <stdio.h>
# define MAXN 101

int max(int a[], int m, int n);
int min(int a[], int m, int n);

int main(void) {
    int i, n;
    int a[MAXN];

    scanf("%d", &n);
    if (n >= 2 && n <= MAXN - 1) {
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("max = %d\n", max(a, 0, n - 1));
        printf("min = %d\n", min(a, 0, n - 1));
    } else {
        printf("Invalid Value.\n");
    }

    return 0;
}

// 递归函数 max 用分治法求出 a[m]~a[n] 中的最大值并返回
int max(int a[], int m, int n) {
    if (m == n) {
        return a[m];
    } else {
        int mid = (m + n) / 2;
        int maxLeft = max(a, m, mid);
        int maxRight = max(a, mid + 1, n);
        return maxLeft > maxRight ? maxLeft : maxRight;
    }
}

// 递归函数 min 用分治法求出 a[m]~a[n] 中的最小值并返回
int min(int a[], int m, int n) {
    if (m == n) {
        return a[m];
    } else {
        int mid = (m + n) / 2;
        int minLeft = min(a, m, mid);
        int minRight = min(a, mid + 1, n);
        return minLeft < minRight ? minLeft : minRight;
    }
}
