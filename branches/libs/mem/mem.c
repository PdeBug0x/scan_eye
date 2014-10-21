/**********************************************************************************
 *功能： 自定义内存分配模块，完成内存分配
 *时间： 2014-10-18 12：14
 *作者： PdeBug0x
 **********************************************************************************/

#include <stdlib.h>
#include <string.h>
#include "mem.h"

//#define _MEM_TEST_
#define _MEM_DEBUG_

/*
void* mem_calloc(size_t count, size_t size)
{
#ifdef _MEM_DEBUG_
  size_t suffix_count = 0;
  size_t size_tmp     = size;

  //多分陪两个是为了将在头部的头四个字接记录分配内存大小，尾部的头四个字节记录
  if(size < CHUNK_SIZE)
  {
	  while(size_tmp < CHUNK_SIZE) //保存足够的头尾空间
	  {
		  suffix_count++;
		  size_tmp = (size_tmp << 1);
	  }
  }
  void* ptr = calloc(count + suffix_count, size);
  *((size_t *)(ptr)) = (count + suffix_count) * size;
  //尾部size个字节留做按bit记录模块内存分配用
  return (void *)(((char *)ptr) + size);

#else
  return calloc(count, size);
#endif

}
*/

void* mem_malloc(size_t size)
{
#ifdef _MEM_DEBUG_
	void *ptr = malloc(size + (CHUNK_SIZE << 1));
	*((size_t *)(ptr)) = size;
	return (void *)(((char *)ptr) + CHUNK_SIZE);
#else
  return malloc(size);
#endif
}

void mem_free(void *ptr)
{
#ifdef _MEM_DEBUG_
	void *ptr_ = (void *)(((char *)(ptr)) - CHUNK_SIZE);
	free(ptr_);
	ptr = NULL;
#else
  free(ptr);
  ptr = NULL;
#endif
}


char* mem_strdup(const char *str)
{
  return strdup(str);
}


char* mem_strndup(const char *str, size_t n)
{
  return strndup(str, n);
}

#ifdef _MEM_TEST_
#include <unistd.h>

int main(int argc, char *argv[])
{
	size_t* size_arr = NULL;
	int index = 0;
	for( ; index < (1 << 20); index ++)
	{
		size_arr = mem_malloc(4);
		printf("malloc_size=%d\n", *((size_t *)(((char *)size_arr) - CHUNK_SIZE)));
		mem_free(size_arr);
		sleep(5);
	}
}
#endif

