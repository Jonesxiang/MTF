#include "mtf.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char * argv[])
{
	printf("\n------------example 01-------------\n");
	char chs[] = "mvoe to front";
	int chs_len = strlen(chs);
	printf("origin:\n%s\n", chs);
	mtf_transform(chs, chs_len);
	printf("transformed:\n%s\n", chs);
	mtf_reverse(chs, chs_len);
	printf("reversed:\n%s\n", chs);

	printf("\n------------example 02-------------\n");
	char char_list[] = " efmnortv";
	int list_len = strlen(char_list);
	printf("origin:\n%s\n", chs);
	mtf_transform1(chs, chs_len, char_list, list_len);
	printf("transformed:\n%s\n", chs);
	mtf_reverse1(chs, chs_len, char_list, list_len);
	printf("reversed:\n%s\n", chs);

	printf("\n------------example 03-------------\n");
	printf("origin:\n%s\n", chs);
	mtf_transform2(chs, chs_len, char_list, list_len);
	printf("transformed:\n%s\n", chs);
	mtf_reverse2(chs, chs_len, char_list, list_len);
	printf("reversed:\n%s\n", chs);
	return 0;

}
