#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "FunMoreFun.h"

#define LIST_LEN 6
#define LIST_NUM 22

void FreeList(Node** list);
void FillList(Node** list, int*,int);
int CheckList(Node* list1, Node* listStudent);
//int CheckList(int* list1, int len, Node* listStudent);
//int Fun(Node** list, Node** res);
//void MoreFun(Node* list, Node** res);

int main()
{
	Node* list;
	Node* res;
	Node* list2;
	Node* listStudent;
	Node* resStudent;
	
	int  list2A[LIST_LEN + 5];

	int bad = 0;
	int badWhich[LIST_NUM] = { 0 };

	int a[LIST_NUM][LIST_LEN] = { {9, 8, 7, 10, 11, 12}, //1+2{9, 2, 3, 4, 5, 6},
								  {10, 9, 6, 7, 8, 12}, //2+1{2, 9, 3, 4, 5, 6},
								  {9, 8, 10, 7, 11, 12}, //1+3{9, 3, 2, 4, 5, 6},
								  {10, 8, 9, 7, 11, 12}, //3+1{2, 3, 9, 4, 5, 6},
								  {11, 8, 9, 11, 12, 7}, //1+E{9, 3, 4, 5, 6, 2},
								  {10, 8, 9, 11, 13, 7}, //E+1{2, 3, 4, 5, 6, 9},
								  {8, 9, 6, 5, 11, 12}, //2+3{3, 2, 9, 4, 5, 6},
								  {9, 10, 7, 5, 11, 12}, //3+2{3, 9, 2, 4, 5, 6},
								  {8, 9, 6, 10, 5, 12}, //2+4{3, 2, 4, 9, 5, 6},
								  {9, 10, 7, 11, 5, 12}, //4+2{3, 9, 4, 2, 5, 6},
								  {9, 10, 11, 5, 12, 8}, //3+5{3, 9, 4, 5, 6, 2},
								  {7, 8, 10, 6, 11, 9}, //5+3{3, 2, 4, 5, 6, 9},
								  {7, 8, 10, 6, 12, 9}, //2ZZ{3, 2, 4, 5, 6, 9},
								  {7, 8, 13, 6, 11, 9}, //2EE{3, 2, 4, 5, 6, 9},
								  {7, 6, 5, 2, 11, 12}, //3{3, 4, 5, 6, 2, 9},
								  {7, 8, 6, 5, 4, 9}, //3{3, 4, 5, 6, 9, 2},
								  {7, 6, 8, 5, 4, 9}, //3{3, 4, 5, 6, 9, 2},
								  {7, 6, 8, 5, 9, 4}, //3{3, 4, 5, 6, 9, 2},
								  {7, 8, 6, 9, 10, 11},//1{3, 4, 9, 2, 5, 6} 
								  {7, 6, 8, 9, 10, 11},//1{3, 4, 9, 2, 5, 6} 
								  {8, 6, 7, 9, 10, 11},//1{3, 4, 9, 2, 5, 6} 
								  {7, 8, 9, 10, 11, 12}//0{3, 4, 9, 2, 5, 6} 
	};


	int listA[LIST_NUM - 10][LIST_LEN - 2] = { {7, 10, 11, 12}, //1+2{9, 8, 7, 10, 11, 12}
								  { 6, 7, 8, 12}, //2+1{10, 9, 11, 7, 8, 12}
								  { 8, 7, 11, 12}, //1+3{9, 8, 10, 7, 11, 12}
								  { 8, 7, 11, 12}, //3+1{10, 8, 9, 7, 11, 12}
								  { 8, 9, 11, 7}, //1+E{11, 8, 9, 11, 12, 7}
								  {8, 9, 11, 7}, //E+1{10, 8, 9, 11, 13, 7}
								  {8, 5, 11, 12}, //2+3{8, 9, 6, 5, 11, 12}
								  {9, 5, 11, 12}, //3+2{9, 10, 7, 5, 11, 12}
								  {8, 6, 5, 12}, //2+4{8, 9, 6, 7, 5, 12}
								  {9, 7, 5, 12}, //4+2{9, 10, 7, 11, 5, 12}
								  {9, 10, 5, 8}, //3+5{9, 10, 11, 5, 12, 8}
								  {7, 8, 6, 9}//, //5+3{7, 8, 10, 6, 11, 9}
	};

	int resA[LIST_NUM - 10 + 1][2] = { {9,8}, //1+2{9, 8, 7, 10, 11, 12}
								  { 9,10}, //2+1{10, 9, 11, 7, 8, 12}
								  { 9,10}, //1+3{9, 8, 10, 7, 11, 12}
								  { 9,10}, //3+1{10, 8, 9, 7, 11, 12}
								  { 11, 12}, //1+E{11, 8, 9, 11, 12, 7}
								  {13,10}, //E+1{10, 8, 9, 11, 13, 7}
								  {9,6}, //2+3{8, 9, 6, 5, 11, 12}
								  {7,10}, //3+2{9, 10, 7, 5, 11, 12}
								  {9,10}, //2+4{8, 9, 6, 7, 5, 12}
								  {11,10}, //4+2{9, 10, 7, 11, 5, 12}
								  {11,12}, //3+5{9, 10, 11, 5, 12, 8}
								  {11,10},//, //5+3{7, 8, 10, 6, 11, 9}
								  {1,20} //dummy
	};
	// list to check
	Init(&list);
	FillList(&list, listA[0],LIST_LEN);
	// res list
	Init(&res);
	// list2 to check
	Init(&list2);
	for (int i = 0;i < LIST_LEN - 2;i++)
	{
		list2A[i] = listA[0][i];
	}
	list2A[LIST_LEN - 2] = resA[0][1] - resA[0][0];
	//calcs
	if (list2A[LIST_LEN - 2] < 0) list2A[LIST_LEN - 2] = list2A[LIST_LEN - 2] *(-1);
	list2A[LIST_LEN - 1] = resA[0][0];
	list2A[LIST_LEN] = (resA[0][0] + resA[0][1]) / 2;
	list2A[LIST_LEN + 1] = resA[0][1];
	list2A[LIST_LEN + 2] = resA[0][0] + resA[0][1];
	FillList(&list2, list2A,LIST_LEN+3);
	
	// student list to check
	Init(&listStudent);
	// empty list
	Init(&resStudent);

	// run on all lists
	for (int k = 0; k < LIST_NUM; k++)
	{
		int f = 0;
		int j=0;
		int i = k;
		// clear the old list
		FreeList(&listStudent);
		resStudent = NULL;
		// student list to check
		FillList(&listStudent, a[i], LIST_LEN);

		// fill the check lists
		FreeList(&list);
		FreeList(&res);
		FreeList(&list2);
		// until 10 check according to Fun
		// after it - res is a dummy
		if (i < LIST_NUM - 10)
		{
			FillList(&list, listA[i], LIST_LEN-2);
			FillList(&res, resA[i], 2);
			// prepare list2
			for (j = 0;j < LIST_LEN - 2;j++)
			{
				list2A[j] = listA[i][j];
			}//j=LIST_LEN - 2

		}
		// the faulty lists should remain intact - and res is a dummy
		else //if (i >= LIST_NUM - 10)
		{
			FillList(&list, a[i], LIST_LEN);
			// prepare list2
			for (j = 0;j < LIST_LEN;j++)
			{
				list2A[j] = a[i][j];
			}//j=LIST_LEN

			// for dummy res
			i = LIST_NUM - 10;
			FillList(&res, resA[i], 2);
		}

		// fill the rest of list2 from j
		list2A[j] = resA[i][1] - resA[i][0];
		if (list2A[j] < 0) list2A[j] *= (-1);
		j++;
		list2A[j++] = resA[i][0];
		list2A[j++] = (resA[i][0] + resA[i][1]) / 2;
		list2A[j++] = resA[i][1];
		list2A[j++] = resA[i][0] + resA[i][1];
		FillList(&list2, list2A, j);

		//return i to real test number (it may have changed)
		i = k;
	
		printf("******** %d **************\n", i);
		PrintList(listStudent);
		printf("\n");
	
		// run Fun
		f = Fun(&listStudent, &resStudent);

		// Compare lists //(res will be checked along with list2 after MoreFun)
		// check and count failures

		// ok lists (until test 12):
		if (k < LIST_NUM - 10)
		{
			// if faulty failed
			if (f == 1)
			{
				bad++;
				badWhich[i]++;
				PrintList(listStudent);
				printf(" === why bad?\n");
			}
			// check if ok
			else
			{
				if (!CheckList(list, listStudent) || !CheckList(res, resStudent)) {
					printf("\nFun NOT OK");
					printf("\nSHOULD BE: ");PrintList(list);
					printf("\nYour list: ");PrintList(listStudent);
					printf("\nFun failed test %d\n", k);
					// mark which test number failed
					badWhich[k]++;
					// count fails
					bad++;
				}
				else
					printf("Fun %d OK\n", i);
				// Check More Fun
				printf("list:");
				PrintList(listStudent);
				printf(" res:");
				PrintList(resStudent);
			}
		}

	// from 12 and on all are bad lists
		else
		{
		// if not detected that the list is faulty - n g
			if (f != 1)
			{
				bad++;
				badWhich[k]++;
			}
			else
			{
				printf(" detected faulty list V\n");
			}
		}

		// now for more fun!
		// run More fun
		// for faulty detected lists use dummy res ===>
		// false faulty detection results in an empty resStudent...
		// therefore not checking!
		if ((k < LIST_NUM - 10) && f)
		{
			printf("faulty faulty\n");
		}
		else if ((k >= LIST_NUM - 10) && !f)
		{
			printf("You have not detected a faulty list!!\n");
		}
		else if (k < LIST_NUM - 10)
		{
			//********* choose *************************
			// choose according to your code:     //****
			MoreFun(listStudent, &resStudent);	  //****
			//MoreFun(&listStudent, &resStudent); //****
			//********* choose *************************

			// might "fail" in case max was subtracted from min
			if (resStudent && (resStudent->info < 0))
			{
				resStudent->info *= -1;
			}
			if (res->info < 0)
			{
				res->info *= -1;
			}
		}
		// compare to the concat list(2), count failures
		if (i >= LIST_NUM - 10)
		{
			// check if student kept the faulty lists
			if (!CheckList(list, listStudent))
			{
				printf("\nEnd list is NOT OK\n");
				bad++;
			}
			else
				printf("\nEnd list is OK\n");
		}
		//good lists
		else
		{
			if (!CheckList(list2, listStudent)) {
				printf("\nEnd list is NOT OK\n");
				printf("well,,, SHOULD BE:\n");PrintList(list2);printf("\n");
				PrintList(listStudent);
				if (i < LIST_NUM - 10)
					printf("\nMoreFun %d failed\n", k);
				bad++;
				badWhich[i]++;
			}
			else
				printf("\nMoreFun %d passed\n", k);
		}

		printf("list:");
		PrintList(listStudent);
		printf("\n************************\n");
	}
	
	printf("********* *********** ***********\n");
	// All passed
	if(bad==10)
		printf("10 tests fail you might have not kept the list??\n");
	if (!bad)
	{
		printf("All tests passed\n");
	}
	else
	{
		printf("%d tests failed: \n", bad);
		for (int i = 0;i < LIST_NUM;i++)
		{
			// print the lists that returned a wrong result
			if (badWhich[i])
			{
				printf("%d . list failed: { ", i);
				for (int j = 0;j < LIST_LEN;j++)
				{
					printf("%d->", a[i][j]);
				}
				printf("\n");
			}
		}
	}
}

void FreeList(Node** list)
{
	while (*list)
	{
		Node* pos;
		while (*list)
		{
			pos = *list;
			*list = (*list)->next;
			free(pos);
		}
	}
}

// fill list from array
void FillList(Node** list, int* a, int len)
{
	int i;
	InsertToHead(list, a[0]);
	for(i = len-1 ; i > 0; i--)
	{
		InsertAfter(*list, a[i]);
	}
}

// Check that two lists are identical
// 1 ok ; 0 fail
int CheckList(Node* list1, Node* listStudent) {
	// both lists and info is the same
	while (listStudent) {
		// not same info - fail
		if (list1->info != listStudent->info)
			return 0;
		// traverse
		list1 = list1->next;
		listStudent = listStudent->next;
	}
	// student list wrong length - fail
	if (list1 || listStudent)
	{
		printf("length doesnt match\n");
		return 0;
	}
	// all went well - success
	return 1;
}