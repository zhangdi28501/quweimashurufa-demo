#include <stdio.h>

int i,j,k; 
unsigned char incode[3]="我"; //要读出的汉字 
unsigned char qh,wh; 
unsigned long offset; 

int main(void)
{
	//占两个字节, 取其区位号 
	qh = incode[0] - 0xa0; //获得区码
	wh = incode[1] - 0xa0; //获得位码
	offset = (94*(qh-1)+(wh-1))*32;
	/*得到偏移位置*/

	struct FILE *HZK;
	char mat[32];
	HZK=fopen("hzk16", "rb");

	if(HZK == NULL) 
	{ 
		printf("Can't Open hzk16\n"); 
		exit(0); 
	} 
	fseek(HZK, offset, SEEK_SET); 
	fread(mat, 32, 1, HZK);
	
	//显示
	for(j=0;j<16;j++)
	{
		for(i=0;i<2;i++)
		{	
			for(k=0;k<8;k++)
			{
				if(mat[j][i]&(0x80>>k)) //测试为1的位置则显示
					printf("%s",'#');
				else 
					printf("%s",'-');
			}
		}
	}
	fclose(HZK);
	fclose(fp)
}
