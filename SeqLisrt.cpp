#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

/**
* func:初始化链表，将一个数组的所有数据放入一个链表中
* @seqList：顺序表
* @elemArray：存放数据的数组
* @length：elemArray数组存放数据的长度
*/
void initSeqList(SeqList* seqList) {
	// 将顺序表的长度设置为0，否则回随机分配个值
	seqList->length = 0;
	// 为顺序表动态分配数组
	seqList->datas = (ElemType*)malloc(MAX_ISZE * sizeof(ElemType));
}


/**
* func:销毁顺序表
* @seqList：顺序表
*/
void destroySeqList(SeqList* seqList) {
	seqList->length = 0;
	if (seqList->datas != NULL) {
		free(seqList->datas);
		seqList->datas = NULL;
	}
}


/**
* func:返回顺序表的长度
* @seqList：顺序表
*/
int length(SeqList* seqList) {
	return seqList->length;
}


/**
* func:动态的扩充顺序表的容量，每次扩充是上次容量的两倍
* @seqList：顺序表
*/
void enlarge(SeqList* seqList) {
	ElemType* temp = seqList->datas;
	// 动态开辟空间为原来两倍的数组
	printf("空间不够，分配一次空间，大小为：%d\n", seqList->length * 2);
	seqList->datas = (ElemType*)malloc(seqList->length * 2 * sizeof(ElemType));
	// 将元素复制到新的数组中
	for (int i = 0; i < seqList->length; i++)
		seqList->datas[i] = temp[i];
	// 手动释放数组内存
	free(temp);
	temp = NULL;
}

/**
* func:定义在指定下标处添加元素
* @seqList：顺序表
* @index：指定的下标
* @elemType：要插入的元素
*/
bool insertElem(SeqList* seqList, int index, ElemType elemType) {
	// 1. 判断传入的下标是否合法
	if (index<0 || index>MAX_ISZE) {
		printf("您传入的下标越界！\n");
		return false;
	}
	// 2. 判断顺序表空间是否还足够
	if (seqList->length + 1 > MAX_ISZE) {
		//顺序表空间不足，动态开辟数组
		enlarge(seqList);
	}
	// 3. 将index的后续元素后移
	for (int i = seqList->length - 1; i >= index; i--) {
		seqList->datas[i + 1] = seqList->datas[i];
	}
	// 4. 修改index处的数据元素
	seqList->datas[index] = elemType;
	// 5. 顺序表长度加+
	seqList->length++;
	return true;
}


/**
* func:定义删除指定下标的元素
* @seqList：顺序表
* @index：指定的下标
* @x：记录要删除的元素
*/
bool deleteElem(SeqList* seqList, int index, ElemType* x) {
	// 1. 判断传入的下标是否合法
	if (index < 0 || index >= MAX_ISZE) {
		printf("您传入的下标越界！\n");
		return false;
	}
	// 2. 判断顺序表是否为空
	if (0 == length(seqList)) {
		printf("顺序表为空！\n");
		return false;
	}
	// 3. 存放要删除的元素
	*x = seqList->datas[index];
	// 3. 将index的后续元素前移
	for (int i = index; i < seqList->length - 1; i++) {
		seqList->datas[i] = seqList->datas[i + 1];
	}
	// 4. 线性表长度加1
	seqList->length--;
	return true;
}


/**
* func:定义修改某个下标的元素
* @seqList：顺序表
* @index：指定的下标
* @elemType：要修改成的元素
*/
bool updateElem(SeqList* seqList, int index, ElemType elemType) {
	// 1. 判断传入的下标是否合法
	if (index < 0 || index >= MAX_ISZE) {
		printf("您传入的下标越界！\n");
		return false;
	}
	// 2. 判断顺序表是否为空
	if (0 == length(seqList)) {
		printf("顺序表为空, 无法更改元素！\n");
		return false;
	}
	// 2. 修改顺序表index处的元素
	seqList->datas[index] = elemType;
	return true;
}


/**
* func:定义查找某个下标的元素
* @seqList：顺序表
* @index：指定的下标
*/
bool selectElem(SeqList* seqList, int index, ElemType* x) {
	// 1. 判断传入的下标是否合法
	if (index < 0 || index >= MAX_ISZE) {
		printf("您传入的下标越界！\n");
		return false;
	}
	// 2. 判断顺序表是否为空
	if (0 == length(seqList)) {
		printf("顺序表为空, 无法查看元素！\n");
		return false;
	}
	*x = seqList->datas[index];
	return true;
}

/**
* func:打印顺序表的所有元素
* @seqList：顺序表
* @index：指定的下标
*/
void printfSeqList(SeqList* seqList) {
	for (int i = 0; i < seqList->length; i++) {
		printElem(seqList->datas[i]);
	}
}

/**
* func:打印一个ElemType类型的元素
* @elem：要打印的元素
*/
void printElem(ElemType elem) {
	printf("姓名：%s, 年龄：%d\n", elem.name, elem.age);
}



