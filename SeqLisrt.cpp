#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

/**
* func:��ʼ��������һ��������������ݷ���һ��������
* @seqList��˳���
* @elemArray��������ݵ�����
* @length��elemArray���������ݵĳ���
*/
void initSeqList(SeqList* seqList) {
	// ��˳���ĳ�������Ϊ0���������������ֵ
	seqList->length = 0;
	// Ϊ˳���̬��������
	seqList->datas = (ElemType*)malloc(MAX_ISZE * sizeof(ElemType));
}


/**
* func:����˳���
* @seqList��˳���
*/
void destroySeqList(SeqList* seqList) {
	seqList->length = 0;
	if (seqList->datas != NULL) {
		free(seqList->datas);
		seqList->datas = NULL;
	}
}


/**
* func:����˳���ĳ���
* @seqList��˳���
*/
int length(SeqList* seqList) {
	return seqList->length;
}


/**
* func:��̬������˳����������ÿ���������ϴ�����������
* @seqList��˳���
*/
void enlarge(SeqList* seqList) {
	ElemType* temp = seqList->datas;
	// ��̬���ٿռ�Ϊԭ������������
	printf("�ռ䲻��������һ�οռ䣬��СΪ��%d\n", seqList->length * 2);
	seqList->datas = (ElemType*)malloc(seqList->length * 2 * sizeof(ElemType));
	// ��Ԫ�ظ��Ƶ��µ�������
	for (int i = 0; i < seqList->length; i++)
		seqList->datas[i] = temp[i];
	// �ֶ��ͷ������ڴ�
	free(temp);
	temp = NULL;
}

/**
* func:������ָ���±괦���Ԫ��
* @seqList��˳���
* @index��ָ�����±�
* @elemType��Ҫ�����Ԫ��
*/
bool insertElem(SeqList* seqList, int index, ElemType elemType) {
	// 1. �жϴ�����±��Ƿ�Ϸ�
	if (index<0 || index>MAX_ISZE) {
		printf("��������±�Խ�磡\n");
		return false;
	}
	// 2. �ж�˳���ռ��Ƿ��㹻
	if (seqList->length + 1 > MAX_ISZE) {
		//˳���ռ䲻�㣬��̬��������
		enlarge(seqList);
	}
	// 3. ��index�ĺ���Ԫ�غ���
	for (int i = seqList->length - 1; i >= index; i--) {
		seqList->datas[i + 1] = seqList->datas[i];
	}
	// 4. �޸�index��������Ԫ��
	seqList->datas[index] = elemType;
	// 5. ˳����ȼ�+
	seqList->length++;
	return true;
}


/**
* func:����ɾ��ָ���±��Ԫ��
* @seqList��˳���
* @index��ָ�����±�
* @x����¼Ҫɾ����Ԫ��
*/
bool deleteElem(SeqList* seqList, int index, ElemType* x) {
	// 1. �жϴ�����±��Ƿ�Ϸ�
	if (index < 0 || index >= MAX_ISZE) {
		printf("��������±�Խ�磡\n");
		return false;
	}
	// 2. �ж�˳����Ƿ�Ϊ��
	if (0 == length(seqList)) {
		printf("˳���Ϊ�գ�\n");
		return false;
	}
	// 3. ���Ҫɾ����Ԫ��
	*x = seqList->datas[index];
	// 3. ��index�ĺ���Ԫ��ǰ��
	for (int i = index; i < seqList->length - 1; i++) {
		seqList->datas[i] = seqList->datas[i + 1];
	}
	// 4. ���Ա��ȼ�1
	seqList->length--;
	return true;
}


/**
* func:�����޸�ĳ���±��Ԫ��
* @seqList��˳���
* @index��ָ�����±�
* @elemType��Ҫ�޸ĳɵ�Ԫ��
*/
bool updateElem(SeqList* seqList, int index, ElemType elemType) {
	// 1. �жϴ�����±��Ƿ�Ϸ�
	if (index < 0 || index >= MAX_ISZE) {
		printf("��������±�Խ�磡\n");
		return false;
	}
	// 2. �ж�˳����Ƿ�Ϊ��
	if (0 == length(seqList)) {
		printf("˳���Ϊ��, �޷�����Ԫ�أ�\n");
		return false;
	}
	// 2. �޸�˳���index����Ԫ��
	seqList->datas[index] = elemType;
	return true;
}


/**
* func:�������ĳ���±��Ԫ��
* @seqList��˳���
* @index��ָ�����±�
*/
bool selectElem(SeqList* seqList, int index, ElemType* x) {
	// 1. �жϴ�����±��Ƿ�Ϸ�
	if (index < 0 || index >= MAX_ISZE) {
		printf("��������±�Խ�磡\n");
		return false;
	}
	// 2. �ж�˳����Ƿ�Ϊ��
	if (0 == length(seqList)) {
		printf("˳���Ϊ��, �޷��鿴Ԫ�أ�\n");
		return false;
	}
	*x = seqList->datas[index];
	return true;
}

/**
* func:��ӡ˳��������Ԫ��
* @seqList��˳���
* @index��ָ�����±�
*/
void printfSeqList(SeqList* seqList) {
	for (int i = 0; i < seqList->length; i++) {
		printElem(seqList->datas[i]);
	}
}

/**
* func:��ӡһ��ElemType���͵�Ԫ��
* @elem��Ҫ��ӡ��Ԫ��
*/
void printElem(ElemType elem) {
	printf("������%s, ���䣺%d\n", elem.name, elem.age);
}



