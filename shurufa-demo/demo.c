#include <stdio.h>

int i,j,k; 
unsigned char incode[3]="��"; //Ҫ�����ĺ��� 
unsigned char qh,wh; 
unsigned long offset; 

int main(void)
{
	//ռ�����ֽ�, ȡ����λ�� 
	qh = incode[0] - 0xa0; //�������
	wh = incode[1] - 0xa0; //���λ��
	offset = (94*(qh-1)+(wh-1))*32;
	/*�õ�ƫ��λ��*/

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
	
	//��ʾ
	for(j=0;j<16;j++)
	{
		for(i=0;i<2;i++)
		{	
			for(k=0;k<8;k++)
			{
				if(mat[j][i]&(0x80>>k)) //����Ϊ1��λ������ʾ
					printf("%s",'#');
				else 
					printf("%s",'-');
			}
		}
	}
	fclose(HZK);
	fclose(fp)
}
