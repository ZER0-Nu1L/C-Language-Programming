/*
�����ʽ:
����GPS��䣬ÿ�����Իس����н��������һ����END������д��ĸ��

����$GPRMC���ĸ�ʽ���£�
    $GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50
�������������һ���ı��У������Զ��š�,�����������ֶΣ�ÿ���ֶεĴ�С�����ȣ���һ�������ʾ��ֻ��һ�ֿ��ܣ���������Ϊ�ֶεĴ�С������������һ����
    �ֶ�0��$GPRMC�����ID�����������ΪRecommended Minimum Specific GPS/TRANSIT Data��RMC���Ƽ���С��λ��Ϣ
    �ֶ�1��UTCʱ�䣬hhmmss.sss��ʽ
    �ֶ�2��״̬��A=��λ��V=δ��λ
    �ֶ�3��γ��ddmm.mmmm���ȷָ�ʽ��ǰ��λ��������0��
    �ֶ�4��γ��N����γ����S����γ��
    �ֶ�5������dddmm.mmmm���ȷָ�ʽ��ǰ��λ��������0��
    �ֶ�6������E����������W��������
    �ֶ�7���ٶȣ��ڣ�Knots
    �ֶ�8����λ�ǣ���
    �ֶ�9��UTC���ڣ�DDMMYY��ʽ
    �ֶ�10����ƫ�ǣ���000 - 180���ȣ�ǰ��λ��������0��
    �ֶ�11����ƫ�Ƿ���E=��W=��
    �ֶ�16��У��ֵ
�����*��ΪУ���ʶ�������������λ��ΪУ��ͣ������ˡ�$���͡�*��֮�������ַ����������������ַ��������ֵ��ʮ������ֵ���������������У�����ʮ�����Ƶ�50��Ҳ����ʮ���Ƶ�80��
1\�����ҳ�$GPRMC���
2\����У��ͣ��ҳ�����У����ȷ
3\�����ֶ�2��ʾ�Ѷ�λ����䣬���м����ʱ�䣬����ɱ���ʱ��
4\�����һ�����õ��ı���ʱ����Ϊ��������
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_LEN 80
#define MAX_NUMBER 80
#define LEN_KEY 6
 
bool is_GPRMC(char str[]);
bool checkout(char str[]);
void find_fields();
void time_transform();

int main(void)
{
	char *gps[MAX_NUMBER];
	int i = 0;
	
	if(is_GPRMC("$GPRMC,sdfj"))
	{
		printf("!\n");
	}
	else
	{
		printf("?\n");
	}
	
//	while(1){
//		scanf(" %s", gps[i]);
//		if(strcpy(gps[i], "END") == 0){
//			break;
//		}
//		
//	}
		
	return 0;
}

//�����ҳ�$GPRMC��� 
bool is_GPRMC(char str[])
{
	char keyword[LEN_KEY+1];
	snprintf(keyword, LEN_KEY, str);
	printf("%s\n%s\n", keyword, keyword);
	if(strcpy(keyword, "$GPRMC") == 0)
	{
		printf("1\n");
		return true;
	}
	else
	{
		return false;
	}
}
//����У��ͣ��ҳ�����У����ȷ
bool checkout(char str[])
{
	
}
//�ҵ���λ�����
void find_fields()
{
	
}
//�Ӷ�λ������м����ʱ�䣬����ɱ���ʱ��
void time_transform()
{
	
}

