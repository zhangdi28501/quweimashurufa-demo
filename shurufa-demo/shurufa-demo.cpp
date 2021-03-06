// shurufa-demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>

int main(void)
{
	char chs[32];
	FILE *fp;
	int i, j;
	unsigned long offset;
	unsigned char hz[] = "计";
	unsigned char qh, wh;

	qh = hz[0] - 0xa0;//获取区码
	wh = hz[1] - 0xa0;//获取位码

	//int a = hz[0];
	//int b = hz[1];
	//printf("%x %x", a, b);
	//hz[0] hz[1]分别为汉字的机内码
	//offset = ((hz[0] - 0xa1) * 94 + (hz[1] - 0xa1)) * 32;//注意0xa1十进制数为161

	offset = ((qh - 1) * 94 + (wh - 1)) * 32;//根据内码找出汉字在HZK16中的偏移位置
	if ((fp = fopen("HZK16", "r")) == NULL)
		return 1;
	
	fseek(fp, offset, SEEK_SET);
	fread(chs, 32, 1, fp);
	
	for (i = 0; i < 32; i++)
	{
		if (i % 2 == 0)
			printf("\n");   //每行两字节,16X16点阵
		for (j = 7; j >= 0; j--)
		{
			if (chs[i] & (0x01 << j))
				/*
				  chs[i] & 0x80 判断第7位
				  chs[i] & 0x40 判断第6位
				  chs[i] & 0x20 判断第5位
				  chs[i] & 0x10 判断第4位
				  chs[i] & 0x08 判断第3位
				  chs[i] & 0x04 判断第2位
				  chs[i] & 0x02 判断第1位
				  chs[i] & 0x01 判断第0位
				  */
				printf("计"); //由高到低,为1则输出'字',反之输出' ';
			else
				printf("  ");
		}
	}

	fclose(fp);
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
