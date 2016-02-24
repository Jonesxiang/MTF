#include "mtf.h"
#include <stdio.h>  /* fprintf() */
#include <stdlib.h> /* exit() */

#define NO_OF_CHAR 256

void initCharList(char * char_list, int len) 
{
	int i;
	for (i = 0; i < len; i++) {
		char_list[i] = (char) i;
	}
}

int findIndexFromList(char c, char * char_list, int len)
{
	int i;
	for (i = 0; i < len; i++) {
		if (c == char_list[i])
			return i;
	}
	fprintf(stderr, "Bad char %c for findIndexFormList()!\n", c);
	exit(1);
}

void moveToFront(int index, char * char_list, int len)
{
	char c = char_list[index];
	int i;
	for (i = index; i > 0; i--) {
		char_list[i] = char_list[i-1];
	}
	char_list[0] = c;
}

void transform(char * chs, int len)
{
	char char_list[NO_OF_CHAR];
	initCharList(char_list, NO_OF_CHAR);
	transform1(chs, len, char_list, NO_OF_CHAR);
}

void reverse(char * chs, int len)
{
	char char_list[NO_OF_CHAR];
	initCharList(char_list, NO_OF_CHAR);
	reverse1(chs, len, char_list, NO_OF_CHAR);
}

void transform1(char * chs, int chs_len, char * char_list, int list_len)
{
	char c;
	int i, index;
	for (i = 0; i < chs_len; i++) {
		c = chs[i];
		index = findIndexFromList(c, char_list, list_len);
		chs[i] = (char) index;
		moveToFront(index, char_list, list_len);
	}
}

void reverse1(char * chs, int chs_len, char * char_list, int list_len)
{
	int i, index;
	for (i = 0; i < chs_len; i++) {
		index = chs[i];
		chs[i] = char_list[index];
		moveToFront(index, char_list, list_len);
	}
}
