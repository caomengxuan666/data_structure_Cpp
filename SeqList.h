//声明顺序表的最大长度
#define MAX_ISZE 2

// 1. 定义数据元素
typedef struct {
	int age;
	char* name;
} ElemType;

// 2. 定义顺序表
typedef struct {
	ElemType* datas;
	int length;
} SeqList;


/**
* func:初始化顺序表
* @seqList：顺序表
*/
void initSeqList(SeqList* seqList);


/**
* func:销毁顺序表
* @seqList：顺序表
*/
void destroySeqList(SeqList* seqList);


/**
* func:动态的扩充顺序表的容量，每次扩充是上次容量的两倍
* @seqList：顺序表
*/
void enlarge(SeqList* seqList);


/**
* func:定义在指定下标处添加元素
* @seqList：顺序表
* @index：指定的下标
* @elemType：要插入的元素
*/
bool insertElem(SeqList* seqList, int index, ElemType elemType);


/**
* func:定义删除指定下标的元素
* @seqList：顺序表
* @index：指定的下标
*/
bool deleteElem(SeqList* seqList, int index, ElemType* x);


/**
* func:定义修改某个下标的元素
* @seqList：顺序表
* @index：指定的下标
* @elemType：要修改成的元素
*/
bool updateElem(SeqList* seqList, int index, ElemType elemType);


/**
* func:定义查找某个下标的元素
* @seqList：顺序表
* @index：指定的下标 
*/
bool selectElem(SeqList* seqList, int index, ElemType* x);


/**
* func:打印顺序表的所有元素
* @seqList：顺序表
* @index：指定的下标
*/
void printfSeqList(SeqList* seqList);


/**
* func:打印一个ElemType类型的元素
* @elem：要打印的元素
*/
void printElem(ElemType elem);


/**
* func:返回顺序表的长度
* @seqList：顺序表
*/
int length(SeqList* seqList);



