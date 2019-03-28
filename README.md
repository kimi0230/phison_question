# phison interview question

# Phison Interview


## Q1:

int a[] = {1,2,3,4,5}

int* p=a;

*(p++) +=100;
*(++p) +=200;


a[] =???



## Q2:

Write a function strcmp(char* s1, char* s2) to compare two strings, if they are same return 0, otherwise, return -1.


## Q3:

Sort an array a[5].

## Q4:

Describe "volatile".

## Q5:

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

## Q6:
a[20]={1,5,9,11,18,21,23,53,200,230,330,331,332,333,400,401,405,430,450,480};

From 0~500, if the number is not in a[], print it out.
Use less CPU time and space.

## Q7:
a[20]={1,5,9,11,18,21,23,53,200,230,330,331,332,333,400,401,405,430,450,480};
b=0,1,2,3,4

Write a function,
if b=0 print    0~99
if b=1 print  100~199
if b=2 print  200~299
if b=3 print  300~399
if b=4 print  400~499

if the number is in a[], don't print it.

## Q8

struct ListStruct{
    unsigned int DataH;
    unsigned int DataL;
    unsigned int NextPtr;
};
struct ListStruct ListArray[1000];
#define NULL 0xFFFF

Given DATA_A and DATA_B, if DataH == DATA_A && DataL == DATA_B, print "FoundEntry" and "PreEntry", if there's no found entry,
print "no found".

ListHead is the head entry of the list, NextPtr is the next index.
ex: if ListHead is "FoundEntry", "PreEntry" is NULL.
(If there's any question, let me know, I'll explain the problem in more detail.)
