/*
	想要借助动态分配的方法
	自己创建一个大小可变的数组： 
	1.可变性
	2.知道它目前的大小
	3.能够访问其中的单元 
*/

#ifndef _ARRAY_H
#define _ARRAY_H

typedef struct {
	int *array;//int型数组 
	int size;
}Array;

Array a;

Array array_create(int inti_size);//创建初始的数组 
void array_free(Array *a);			//释放空间 
int array_size(const Array *a);   	//访问目前的大小 
int *array_at(Array *a, int index); //访问指定的单元 
void array_inflate(Array *a, int more_size);//让数组长大 

#endif
