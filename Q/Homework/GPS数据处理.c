/*
输入格式:
多条GPS语句，每条均以回车换行结束。最后一行是END三个大写字母。

其中$GPRMC语句的格式如下：
    $GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50
这里整条语句是一个文本行，行中以逗号“,”隔开各个字段，每个字段的大小（长度）不一，这里的示例只是一种可能，并不能认为字段的大小就如上述例句一样。
    字段0：$GPRMC，语句ID，表明该语句为Recommended Minimum Specific GPS/TRANSIT Data（RMC）推荐最小定位信息
    字段1：UTC时间，hhmmss.sss格式
    字段2：状态，A=定位，V=未定位
    字段3：纬度ddmm.mmmm，度分格式（前导位数不足则补0）
    字段4：纬度N（北纬）或S（南纬）
    字段5：经度dddmm.mmmm，度分格式（前导位数不足则补0）
    字段6：经度E（东经）或W（西经）
    字段7：速度，节，Knots
    字段8：方位角，度
    字段9：UTC日期，DDMMYY格式
    字段10：磁偏角，（000 - 180）度（前导位数不足则补0）
    字段11：磁偏角方向，E=东W=西
    字段16：校验值
这里，“*”为校验和识别符，其后面的两位数为校验和，代表了“$”和“*”之间所有字符（不包括这两个字符）的异或值的十六进制值。上面这条例句的校验和是十六进制的50，也就是十进制的80。
1\从中找出$GPRMC语句
2\计算校验和，找出其中校验正确
3\并且字段2表示已定位的语句，从中计算出时间，换算成北京时间
4\以最后一条语句得到的北京时间作为结果输出。
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

//从中找出$GPRMC语句 
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
//计算校验和，找出其中校验正确
bool checkout(char str[])
{
	
}
//找到定位的语句
void find_fields()
{
	
}
//从定位的语句中计算出时间，换算成北京时间
void time_transform()
{
	
}

