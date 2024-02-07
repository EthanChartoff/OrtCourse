#include <stdio.h>

// void f1(struct St1* p)
// {
//     strcpy(p->ptr, "abvgd");
//     p->x = 90.67;
// }
// void f2(struct St2** p)
// {
//     (*p)--;
//     strcpy((*p)->pSt1->ptr, "mnbvc");
//     (*p)->pSt1->z = 200;
// }
struct St1
{
char ptr[10];
double x;

short z;
};
struct St2
{
char ptr[6];
struct St1 str;
struct St1* pSt1;
};


int main()
{
struct St1 lol = {"125678", 12.56,100};
struct St1 st1Arr[] = { {"12345678", 12.56,100},{"qwert", 23.13,-98},
{"abcdefg90", 145.89,115} };
struct St1* pSt1 = st1Arr;
struct St2 st2Arr[] = { {"poiuy", *(++pSt1+1), ++pSt1 - 1},
{",.?!", *(++pSt1 -3),--pSt1},
{"rewqt", *(--pSt1 + 1), pSt1++} };

struct St2* pSt2 = st2Arr;
struct St2** ppSt2 = &pSt2;

printf("size=%d\n", sizeof(st1Arr));
printf("size=%d\n", sizeof(&st1Arr));
printf("size=%d\n", sizeof(st2Arr));
printf("%s\n", (*pSt1++).ptr);
printf("%s\n", (pSt2++)->ptr);
printf("%f\n", (++*ppSt2)->pSt1->x);
// f1(pSt2);
printf("%s\n", (*pSt2).ptr);
printf("%d\n", (*(*ppSt2 -2)).pSt1->z);
// f2(ppSt2);
printf("%d\n", pSt2->pSt1->z);
printf("%s\n", pSt2->pSt1->ptr);
printf("%f\n", (*&pSt2-1)->pSt1->x);
printf("%s\n", (*((--pSt2 + 1) - 1)).ptr);
return 0;
}