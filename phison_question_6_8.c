#include <stdio.h>

/*
Question 6
給你一個sort好的陣列a[20] ，然後請你印出0 ~500的數字，
如果數字在a[20] 裡面，則不要印出，請你用最少的cpu和memory int

Question 7
類似上題，function給一個數字b = 0, 1, 2, 3, 4時，分別印出0 ~99, 100 ~199,200
~299, 300 ~399,400 ~499之中，不在a [20] 裡面的數字，也是用最少的CPU跟memory。

Question 8
有一個陣列A[500]，裡面都是存node的struct，假設第一個開頭index叫做listhead，
那我們要access這個list的第一個structnode就是A[listhead]，然後再透過 struct node
裡的next找到下一個struct
node，直到next是null，如果next是null就代表示list最後一個結點。題目會
#define null 0xffff
在來就是要透過給予的兩個值DATA_A和DATA_B來尋找我們要的node有沒有在A[500]裡面。check是否在陣列裡的方式會用計算Data_A<<4+Data_B會不會等
於DATA_H<<4+DATA_L，另外題目又有說DATA_H<<4+DATA_L會越來越大，所以不用搜尋到最後。如果找到就是印出找到node的index(FoundEntry)，和
它前一個node的index(PreEntry)。如果不在也是要印找不到。

struct ListStruct{
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
};
struct ListStruct ListArray[1000];
#define NULL 0xFFFF

Given DATA_A and DATA_B, if DataH == DATA_A && DataL == DATA_B, print
"FoundEntry" and "PreEntry", if there's no found entry, print "no found".

ListHead is the head entry of the list, NextPtr is the next index.
ex: if ListHead is "FoundEntry", "PreEntry" is NULL.
(If there's any question, let me know, I'll explain the problem in more detail.)
*/

// #define NULL 0xFFFF
struct ListStruct {
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
};
struct ListStruct ListArray[1000];
unsigned int ListHead = 0;

int searchlist(unsigned int DATA_A, unsigned int DATA_B) {
    unsigned int PreEntry = NULL, FoundEntry = ListHead;

    while (FoundEntry != NULL) {
        if (ListArray[FoundEntry].DataH == DATA_A &&
            ListArray[FoundEntry].DataL == DATA_B) {
            printf("FoundEntry");
            return 1;
        }
        PreEntry = FoundEntry;
        FoundEntry = ListArray[FoundEntry].NextPtr;
    }
    printf("no found");
    return -1;
}

// ?????
int searchlist2(unsigned int DATA_A, unsigned int DATA_B) {
    unsigned int PreEntry = NULL, FoundEntry = ListHead;
    int search = 0;
    while (FoundEntry != NULL) {
        if (ListArray[FoundEntry].DataH == DATA_A &&
            ListArray[FoundEntry].DataL == DATA_B) {
            if (PreEntry == NULL) {
                printf("FoundEntry = ListHead; PreEntry=NULL");
                search = 1;
            } else {
                unsigned int Next = ListArray[FoundEntry].NextPtr;
                if ((ListArray[Next].DataH << 16 + ListArray[Next].DataL) >
                    ListArray[FoundEntry].DataH
                        << 16 + ListArray[FoundEntry].DataL) {
                    printf("FoundEntry = %d ; PreEntry = %d\n", FoundEntry,
                           PreEntry);
                    search = 1;
                }
            }
        }
        PreEntry = FoundEntry;
        FoundEntry = ListArray[FoundEntry].NextPtr;
    }
    if (search == 0) {
        printf("no found");
        return -1;
    } else
        return 1;
}

void printArray(unsigned int *a, int size) {
    int index = 0;
    for (int i = 0; i <= 500; i++) {
        if (index < size && a[index] == i) {
            index++;
        } else {
            printf("%d ", i);
        }
    }
}

void printArrayRange(unsigned int *a, int b, int size) {
    int index = 0;
    for (int i = b * 100; i < (b + 1) * 100; i++) {
        if (index < size && a[index] == i) {
            index++;
        } else {
            printf("%d ", i);
        }
    }
    printf("\n\n");
}

int main() {
    // Question 6
    unsigned int a[20] = {1,   5,   9,   11,  18,  21,  23,  53,  200, 230,
                          330, 331, 332, 333, 400, 401, 405, 430, 450, 480};
    printArray(a, 20);

    // Question 7
    int b = 4; // b = 0, 1, 2, 3, 4
    printArrayRange(a, b, 20);
}

/*
Copy from http://l4disgreat.blogspot.com/2016/04/blog-post.html
and
http://shihweiyao.pixnet.net/blog/post/221520785-%E7%BE%A4%E8%81%AF%E9%9D%A2%E8%A9%A6-%E9%9F%8C%E9%AB%94%E5%B7%A5%E7%A8%8B%E5%B8%AB
and
https://github.com/yllibliu/Phison_interview
*/