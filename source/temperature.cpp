#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define READINGS_PER_DAY 6

//用链表储存温度值
struct LinkedList {
	struct LinkedList *pnext;
	float daily_temperature[READINGS_PER_DAY];
	float average;
	int count_num;
};

float average_degree(float *InPutNumber);	/*进行平均温度计算 */

int main(void)
{
	struct LinkedList *first = NULL;
	struct LinkedList *current = NULL;
	struct LinkedList *previous = NULL;
	bool keep = true;	/*是否继续输入 */
	int count_day = 1;	/*记录总共输入了多少天 */

	printf("\nType some tmptemperature:");
	printf
	    ("\nType a letter at the fist temperature of a new day to the end of input \n");
	printf("\nMUST HAVE SIX TIMES A DAY\n\n");
	while (true) {
		//输入温度值
		printf("The next day:\n");
		float tmptemperature[READINGS_PER_DAY] = { 0 };
		for (int i = 0; i < READINGS_PER_DAY; ++i) {
			//在第一天的第一个温度值输入一个字母或符号退出输入
			if (i == 0) {
				keep = scanf("%f", &tmptemperature[i]);
				if (!keep) {
					break;
				}
			} else {
				scanf("%f", &tmptemperature[i]);
			}
		}
		if (!keep) {
			break;
		}
		count_day++;
		current = (struct LinkedList *) calloc(1, sizeof(struct LinkedList));	/*为链表分配内存 */
		if (current == NULL) {
			printf("calloc failed\n");
			exit(1);
		}
		if (first == NULL) {
			first = current;
		}
		if (previous != NULL) {
			previous->pnext = current;
		}
		//将一天的温度值存入链表
		current->average = average_degree(tmptemperature);	/*调用计算平均数的函数并存入平均值 */
		for (int j = 0; j < READINGS_PER_DAY; ++j) {
			current->daily_temperature[j] = tmptemperature[j];	/*将每天的六个温度存入 */
		}
		current->pnext = NULL;
		previous = current;
	}
	float average[count_day];
	//开始读取和输出数据（遍历链表）
	current = first;
	int count_day_print = 1;	/*用于输出第几天 */
	printf("\n\nDaily temperature\n\n");
	while (current != NULL) {
		printf("Days %d: ", count_day_print);
		for (int i = 0; i < READINGS_PER_DAY; ++i) {
			printf("%.2f  ", current->daily_temperature[i]);
		}
		printf("\n");
		average[count_day_print - 1] = current->average;
		//释放内存
		previous = current;
		current = current->pnext;
		free(previous);
		count_day_print++;	/*下一天 */
	}

	printf("\nAverage temperature\n");
	for (int i = 0; i < count_day - 1; ++i) {
		if (i % 3 == 0) {
			printf("\n");
		}
		printf("Days %d: %.1f  ", i + 1, average[i]);
	}
	return 0;
}

float average_degree(float *tmptemperature)
{
	float average = 0;
	for (int i = 0; i < READINGS_PER_DAY; ++i) {
		average += *(tmptemperature + i);
	}
	return average / READINGS_PER_DAY;
}
