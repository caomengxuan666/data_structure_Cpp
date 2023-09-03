//����˳������󳤶�
#define MAX_ISZE 2

// 1. ��������Ԫ��
typedef struct {
	int age;
	char* name;
} ElemType;

// 2. ����˳���
typedef struct {
	ElemType* datas;
	int length;
} SeqList;


/**
* func:��ʼ��˳���
* @seqList��˳���
*/
void initSeqList(SeqList* seqList);


/**
* func:����˳���
* @seqList��˳���
*/
void destroySeqList(SeqList* seqList);


/**
* func:��̬������˳����������ÿ���������ϴ�����������
* @seqList��˳���
*/
void enlarge(SeqList* seqList);


/**
* func:������ָ���±괦���Ԫ��
* @seqList��˳���
* @index��ָ�����±�
* @elemType��Ҫ�����Ԫ��
*/
bool insertElem(SeqList* seqList, int index, ElemType elemType);


/**
* func:����ɾ��ָ���±��Ԫ��
* @seqList��˳���
* @index��ָ�����±�
*/
bool deleteElem(SeqList* seqList, int index, ElemType* x);


/**
* func:�����޸�ĳ���±��Ԫ��
* @seqList��˳���
* @index��ָ�����±�
* @elemType��Ҫ�޸ĳɵ�Ԫ��
*/
bool updateElem(SeqList* seqList, int index, ElemType elemType);


/**
* func:�������ĳ���±��Ԫ��
* @seqList��˳���
* @index��ָ�����±� 
*/
bool selectElem(SeqList* seqList, int index, ElemType* x);


/**
* func:��ӡ˳��������Ԫ��
* @seqList��˳���
* @index��ָ�����±�
*/
void printfSeqList(SeqList* seqList);


/**
* func:��ӡһ��ElemType���͵�Ԫ��
* @elem��Ҫ��ӡ��Ԫ��
*/
void printElem(ElemType elem);


/**
* func:����˳���ĳ���
* @seqList��˳���
*/
int length(SeqList* seqList);



