#include <algorithm> // std::sort
#include <iostream>  // std::cout
#include <stdio.h>
using namespace std;

#define ADD_TWO(x, y)                                                          \
    x += 2;                                                                    \
    y += 2;

/*
    Question 1
    int a[] = {1, 2, 3, 4, 5}
    int *p = a;
    *(p++) += 100;
    *(++p) += 200;
    a[] = ? ? ?
*/
void question1() {
    int a[] = {1, 2, 3, 4, 5};
    int *p = a;
    *(p++) += 100;
    *(++p) += 200;

    size_t n = sizeof(a) / sizeof(a[0]);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]); // 101 2 203 4 5
    }
    printf("\n");
}

/*
    Question 2
    Write a function strcmp(char *s1, char *s2) to compare two strings,
    if they are same return 0, otherwise,
    return -1.
*/

int question2(char *s1, char *s2) {
    while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2) {
        s1++;
        s2++;
    }
    if (*s1 == *s2) {
        return 0;
    } else {
        return -1;
    }
}

/*
    Question 3
    Sort an array a[5]
    greater<int>()  大->小
    less<int>() 小->大
*/
void question3() {
    int a[5] = {1, 3, 5, 2, 4};
    size_t n = sizeof(a) / sizeof(a[0]);
    sort(a, a + n, less<int>());
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/*
    Question 5
    ## define ADD_TWO(x,y) x+=2;y+=2;
    void main()
    {
        int j=2;
        int k=7;

        bool flag=false;

        if(flag) ADD_TWO(j,k);
        printf("%d,%d"j,k);
    }
    Write down the output.
*/

void question5() {
    int j = 2;
    int k = 7;

    // bool flag = false;
    bool flag = true;
    if (flag) {
        ADD_TWO(j, k);
    }
    //  bool flag = false; -> 2,7
    //  bool flag = true; -> 4,9
    printf("%d,%d \n", j, k);
}

int main() {
    question1();

    char str1[] = "hello";
    char str2[] = "hello2";
    int q2_result = question2(str1, str2);
    printf("%d \n", q2_result);

    question3();
    question5();
}