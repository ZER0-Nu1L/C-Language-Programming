/*
	��Ҫ������̬����ķ���
	�Լ�����һ����С�ɱ�����飺 
	1.�ɱ���
	2.֪����Ŀǰ�Ĵ�С
	3.�ܹ��������еĵ�Ԫ 
*/

#ifndef _ARRAY_H
#define _ARRAY_H

typedef struct {
	int *array;//int������ 
	int size;
}Array;

Array a;

Array array_create(int inti_size);//������ʼ������ 
void array_free(Array *a);			//�ͷſռ� 
int array_size(const Array *a);   	//����Ŀǰ�Ĵ�С 
int *array_at(Array *a, int index); //����ָ���ĵ�Ԫ 
void array_inflate(Array *a, int more_size);//�����鳤�� 

#endif
