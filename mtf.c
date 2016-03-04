#include "mtf.h"
#include <stdio.h>  /* fprintf() */
#include <stdlib.h> /* exit() */
#include <malloc.h> /* malloc() */
#include <memory.h> /* memcpy() */

#define MTF_CHAR_NUM 256

void mtf_init_char_list(char * char_list, int len) 
{
	int i;
	for (i = 0; i < len; i++) {
		char_list[i] = (char) i;
	}
}

int mtf_find_index_from_list(char c, char * char_list, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		if (c == char_list[i])
			return i;
	}
	fprintf(stderr, "Bad char %c for findIndexFormList()!\n", c);
	exit(1);
}

void mtf(int index, char * char_list, int len)
{
	char c = char_list[index];
	int i;
	for (i = index; i > 0; i--) {
		char_list[i] = char_list[i-1];
	}
	char_list[0] = c;
}

void mtf_transform(char * chs, int len)
{
	char char_list[MTF_CHAR_NUM];
	mtf_init_char_list(char_list, MTF_CHAR_NUM);
	mtf_transform1(chs, len, char_list, MTF_CHAR_NUM);
}

void mtf_transform1(char * chs, int chs_len, char * char_list, int list_len)
{
	char * char_list_tmp = (char*) malloc(sizeof(char) * list_len);
	memcpy(char_list_tmp, char_list, sizeof(char) * list_len);
	char c;
	int i, index;
	for (i = 0; i < chs_len; i++) {
		c = chs[i];
		index = mtf_find_index_from_list(c, char_list_tmp, list_len);
		mtf(index, char_list_tmp, list_len);
		chs[i] = (char) index;
	}
	free(char_list_tmp);
}

void mtf_transform2(char * chs, int chs_len, char * char_list, int list_len)
{
	char * char_list_tmp = (char*) malloc(sizeof(char) * list_len);
	memcpy(char_list_tmp, char_list, sizeof(char) * list_len);
	char c;
	int i, index;
	for (i = 0; i < chs_len; i++) {
		c = chs[i];
		index = mtf_find_index_from_list(c, char_list_tmp, list_len);
		mtf(index, char_list_tmp, list_len);
		chs[i] = char_list[index];
	}
	free(char_list_tmp);
}

void mtf_reverse(char * chs, int len)
{
	char char_list[MTF_CHAR_NUM];
	mtf_init_char_list(char_list, MTF_CHAR_NUM);
	mtf_reverse1(chs, len, char_list, MTF_CHAR_NUM);
}

void mtf_reverse1(char * chs, int chs_len, char * char_list, int list_len)
{
	char * char_list_tmp = (char*) malloc(sizeof(char) * list_len);
	memcpy(char_list_tmp, char_list, sizeof(char) * list_len);
	int i, index;
	for (i = 0; i < chs_len; i++) {
		index = chs[i];
		chs[i] = char_list_tmp[index];
		mtf(index, char_list_tmp, list_len);
	}
	free(char_list_tmp);
}

void mtf_reverse2(char * chs, int chs_len, char * char_list, int list_len)
{
	char * char_list_tmp = (char*) malloc(sizeof(char) * list_len);
	memcpy(char_list_tmp, char_list, sizeof(char) * list_len);
	int i, index;
	for (i = 0; i < chs_len; i++) {
		index = mtf_find_index_from_list(chs[i], char_list, list_len);
		chs[i] = char_list_tmp[index];
		mtf(index, char_list_tmp, list_len);
	}
	free(char_list_tmp);
}
