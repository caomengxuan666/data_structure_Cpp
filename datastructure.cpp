#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"
#include"linked_list.hpp"
#include"Double_Linked.hpp"
#include"Circle_Double_Linked_list.hpp"
#include"stack_Array.hpp"
#include"stack_List.hpp"
#include<stack>
#include"Queue_Array.hpp"
#include"Queue_List.hpp"
#include"BinarySearchTree.hpp"


/// <summary>
/// ���Ա������
/// ��ʼ���������ȶ���һ�����飬�������ĩβend���Ϊ-1
/// insert:����Ԫ�أ���ʹ�ø�Ԫ���ұߵ�����Ԫ�ض������ƶ�һ��
///remove:ɾ��Ԫ�أ���ʹ�ø�Ԫ���ұߵ�����Ԫ�ض������ƶ�һ��
/// count:��¼Ԫ�صĸ������ж��ٸ�Ԫ�ؾ��ж��ٸ�����
/// add:��Ԫ�ظ���������ʱ�򣬽�����������ԭ�����������Ҹ���ԭ�������е�Ԫ�أ����ҽ�ԭ������ڴ��ͷ�
/// 
/// </summary>

/*void testSeq() {
	ElemType temp;
	ElemType elemArray[10];
	// ����˳��� 
	SeqList seqList;
	// ��ʼ��˳���
	initSeqList(&seqList);
	// ��������Ԫ��
// ��������Ԫ��
	elemArray[0].name = _strdup("����");
	elemArray[0].age = 13;
	elemArray[1].name = _strdup("����");
	elemArray[1].age = 14;
	elemArray[2].name = _strdup("����");
	elemArray[2].age = 15;

	//Ϊ˳�������һЩֵ
	printf("[##############��˳����0,1,2λ�ò���Ԫ��##############]\n");
	insertElem(&seqList, 0, elemArray[0]);
	insertElem(&seqList, 1, elemArray[1]);
	insertElem(&seqList, 2, elemArray[2]);
	printfSeqList(&seqList);
	printf("��ǰ˳�����Ϊ:%d\n", length(&seqList));
	//ɾ
	printf("[###################ɾ��index=1Ԫ��###################]\n");
	deleteElem(&seqList, 1, &temp);
	printf("ɾ����Ԫ��Ϊ��\n");
	printElem(temp);
	printf("˳���Ԫ��Ϊ��\n");
	printfSeqList(&seqList);
	//��
	printf("[###################����index=0Ԫ��###################]\n");
	temp.name = _strdup("˧˧");
	temp.age = 20;
	updateElem(&seqList, 0, temp);
	printf("˳���Ԫ��Ϊ��\n");
	printfSeqList(&seqList);
	//��
	printf("[###################�鿴index=1Ԫ��###################]\n");
	selectElem(&seqList, 1, &temp);
	printElem(temp);
	//����˳���
	destroySeqList(&seqList);
}
*/
/*void testLinked_List() {
	Initiate_Linked_List();
	searchAll();
	cout << endl;
	newNode(20);
	searchAll();
	cout << endl;
	newNode(40);
	searchAll();
	cout << endl;
	headInsertNode(50);
	searchAll();
	cout << endl;
	posInsert(100, 2);
	searchAll();
	cout << endl;
	posInsert(125, 1);
	searchAll();
	cout << endl;
	posInsert(150, 7);
	searchAll();
	cout << endl;
	delNode(5);
	searchAll();
	cout << endl;
	delNode(1); 
	searchAll();
	cout << endl;
	reverse();
	searchAll();
	cout << endl;
	rsearchAll();
}
*/
/*
void testClassLinked_List() {
	LinkedList a;
	a.newNode(10);
	a.newNode(20);
	a.newNode(30);
	a.searchAll();
	cout << endl;
	a.headInsertNode(5);
	a.searchAll();
	cout << endl;

	a.posInsert(15, 2);
	a.searchAll();
	cout << endl;

	a.delNode(3);
	a.searchAll();
	cout << endl;

	a.rSearchAll(a.head);
	a.searchAll();
	cout << endl;

	a.reverse();
	a.searchAll();
	cout << endl;

	a.recurse(a.head);
	a.searchAll();
	cout << endl;

	a.recurse(a.head, 20);
	a.searchAll();

}
*/
/*void testDoubleLinked_List() {
	DoubleLinked_List a;
	a.newNode(10);
	a.newNode(20);
	a.newNode(30);
	a.searchAll();
	cout << endl;
	a.headInsertNode(5);
	a.searchAll();
	cout << endl;

	a.posInsert(15, 2);
	a.searchAll();
	cout << endl;

	a.delNode(3);
	a.searchAll();
	cout << endl;

	a.rSearchAll(a.head);
	a.searchAll();
	cout << endl;

	a.reverse();
	a.searchAll();
	cout << endl;

}
*/
/*
void testCircle_Double_Linked_List() {
	Circle_Double_Linked_List a(10);
	a.searchAll();
	a.headInsertNode(10);
	cout << endl;
	a.headInsertNode(20);
	cout << endl;
	a.searchAll();
}
*/
/*
void testStack_Array() {
	stack_Array <>a;
	a.push(10);
	a.push(15);
	a.push(23);
	a.push(6);
	a.push(10);
	a.push(15);
	a.push(23);
	a.push(6);
	a.push(10);
	a.push(15);
	a.push(23);
	a.push(6);
	a.top();
	a.pop();
	a.top();
	a.pop();
	a.top();
	a.pop();
	a.top();
	a.pop();
	a.top();
	a.pop();
	a.top();
	a.pop();
	int temp=a.getSize();
	cout <<"The size of this stack is : " << temp << endl;
}
*/

/*void testStack_List() {
	stack_List a;
	a.push(10);
	a.top();
	a.push(20);
	a.top();
	a.push(30);
	a.top();
	a.pop();
	a.top();
	a.pop();
	a.top();
	a.pop();
	a.top();
	a.pop();

}
*/
/*
void reverseByStack(char *c,int n) {
	stack_Array <char>s;
	for (int i = 0; i < n; i++) {
		s.push(c[i]);
	}

	for (int i = 0; i < n; i++) {
		c[i] = s.top();
		s.pop();
	}

}

void reverseByStack_Linked_List(char*c,int n) {
        stack_List s;
		for (int i = 0; i < n; i++) {
			s.push(c[i]);
		}

		while (s.isEmpty()==false) {
			s.top();
			s.pop();
		}
}

void testReverseWithStack_Array() {
	char c[51];
	cout << "Please enter a string" << endl;
	cin >> c;
	reverseByStack(c, strlen(c));//ʵ�������Ž�Ӧ������˫ָ��ʵ�ַ�ת���ռ临�Ӷȸ��ͣ�����Ҫ�õ�ջ����ռ�
}

void testReverseWithStack_List() {
	char c[51];
	cout << "Please enter a string" << endl;
	cin >> c;
	reverseByStack(c, strlen(c));//ʵ�������Ž�Ӧ������˫ָ��ʵ�ַ�ת���ռ临�Ӷȸ��ͣ�����Ҫ�õ�ջ����ռ�
}
*/

/*bool CheckBalancedParenthesis(string str) {
	stack<char> a;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			a.push(str[i]);
		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			if (a.empty()) {
				return false;
			}
			char top = a.top();
			if ((str[i] == ')' && top == '(') ||
				(str[i] == ']' && top == '[') ||
				(str[i] == '}' && top == '{')) {
				a.pop();
			}
			else {
				return false;
			}
		}
	}
	return a.empty();
}

void CheckBalancedParenthesis_test() {
	string str = "{[()]}";
	bool isBalanced = CheckBalancedParenthesis(str);
	if (isBalanced) {
		cout << "The parentheses are balanced." << endl;
	}
	else {
		cout << "The parentheses are not balanced." << endl;
	}
}

*/
/*
size_t EvaluatePostfix(string& exp) {
	stack_Array<size_t> s;

	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/') {
			size_t op = exp[i] - '0';
			s.push(op);
		}
		else {
			size_t op2 = s.top();
			s.pop();
			size_t op1 = s.top();
			s.pop();
			size_t result;
			if (exp[i] == '+') {
				result = op1 + op2;
			}
			else if (exp[i] == '-') {
				result = op1 - op2;
			}
			else if (exp[i] == '*') {
				result = op1 * op2;
			}
			else if (exp[i] == '/') {
				result = op1 / op2;
			}
			else {
				cout << "ERROR: Wrong input" << endl;
				break;
			}
			s.push(result);
		}
	}
	return s.top();
}


void TestEvaluatePostfix() {
	string str = "23*54*+9-";
	size_t ans = EvaluatePostfix(str);
	cout << "The answer is: " << ans << endl;
}
*/

/*size_t EvaluateInfix(string& exp) {
	stack_Array<char>s;

	for (int i = exp.size() ; i >=0; i--) {
		if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/') {
			size_t op = exp[i] - '0';
			s.push(op);
		}
		else {
			size_t op1 = s.top();
			s.pop();
			size_t op2 = s.top();
			s.pop();
			size_t result;

			if (exp[i] == '+') {
				result = op1 + op2;
			}
			else if (exp[i] == '-') {
				result = op1 - op2;
			}
			else if (exp[i] == '*') {
				result = op1 * op2;
			}
			else if (exp[i] == '/') {
				result = op1 / op2;
			}
			else {
				cout << "ERROR: Wrong input" << endl;
				break;
			}
			s.push(result);
		}
	}
	return s.top();
}

void TestEvaluateInfix() {
	string str;
	str.assign("-+*23*549");
	size_t ans = EvaluateInfix(str);
	cout << "The answer is: " << ans << endl;
}
*/
/*
int GetPrecedence(char oper) {
	if (oper == '*' || oper == '/')
		return 2;
	else if (oper == '+' || oper == '-')
		return 1;
	else
		return 0;
}

bool HasHigherPrec(char topOper, char oper) {
	int prec1 = GetPrecedence(topOper);
	int prec2 = GetPrecedence(oper);
	return prec1 >= prec2;
}

string InfixToPostfix(const string& exp) {
	stack_Array<char> s;
	string res;

	for (int i = 0; i < exp.size(); i++) {
		if (exp[i] >= '0' && exp[i] <= '9') {
			res += exp[i];
		}
		else if (exp[i] == '(') {
			s.push(exp[i]);
		}
		else if (exp[i] == ')') {
			while (!s.isEmpty() && s.top() != '(') {
				res += s.top();
				s.pop();
			}
			if (!s.isEmpty() && s.top() == '(')
				s.pop();
		}
		else {
			while (!s.isEmpty() && s.top() != '(' && HasHigherPrec(s.top(), exp[i])) {
				res += s.top();
				s.pop();
			}
			s.push(exp[i]);
		}
	}

	while (!s.isEmpty()) {
		res += s.top();
		s.pop();
	}

	return res;
}

void TestInfixToPostfix() {
	string str = "5+4*3+1/2";
	string ans = InfixToPostfix(str);
	cout << "The answer is: " << ans << endl;
}
*/

/*
void testQueue() {
	Queue_Array<>q1;
	q1.Enqueue(10);
	q1.Enqueue(20);
	q1.front();
	q1.end();
	q1.Dequeue();
	q1.front();
	q1.end();
}
*/
/*
void testQueue_List() {
	Queue_List q;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.PrintFront();
	q.PrintEnd();
	q.Dequeue();
	q.PrintFront();
	q.PrintEnd();
}
*/

/*
void testBinarySearchTree() {
	BST t1;
	BST_Node* root = t1.getNode();
	t1.Insert(15);
	t1.Insert(10);
	t1.Insert(20);
	t1.Insert(25);
	t1.Insert(8);
	t1.Insert(12);
	//t1.Insert(30);
	t1.Insert(101);
	t1.Insert(102);
	t1.Insert(105);

	int count;
	cout << "Enter numbers be searched" << endl;
	cin >> count;
	if (t1.Search(count) == true)cout << "Found" << endl;
	else cout << "Not Found" << endl;
	int max=t1.SearchMax();
	int min=t1.SearchMin();
	cout << "Max=" << max << endl;
	cout << "Min=" << min << endl;
	int height = t1.SearchHeight();
	cout << "Height=" << height << endl;
	t1.LevelOrder();
	t1.Preorder();
	t1.Inorder();
	t1.Postorder();
	bool flag=t1.IsBinarySearchTree();
	if (flag) {
		cout << "It is a Binary Search Tree" << endl;
	}
	else cout << "It is not a Binary Search Tree" << endl;

	t1.Delete(105);
	t1.LevelOrder();
	t1.Delete(8);
	t1.LevelOrder();
	t1.Delete(102);
	t1.LevelOrder();
	t1.Delete(15);
	t1.LevelOrder();
    flag = t1.IsBinarySearchTree();
}
*/

int main() { 
	//testSeq();
	//testLinked_List();
	//testClassLinked_List();
	//testDoubleLinked_List();
	//testCircle_Double_Linked_List();
	//testStack_Array();
	//testStack_List();
	//testReverseWithStack_Array();
	//testReverseWithStack_List();
	//CheckBalancedParenthesis_test();+
	//TestEvaluatePostfix();
	//TestEvaluateInfix();
	//TestInfixToPostfix();
	//testQueue();
	//testQueue_List();
	//testBinarySearchTree();

}  