#include <windows.h>   // 引入 Windows API
#include <stdio.h>

// 函数定义：拼接字符串
//C语言语法基础（变量/函数/指针）	编写简单函数并用 MessageBox 输出
void buildMessage(char *day, char * name, char *output) {
    sprintf(output, "今天是%s！%s正在学习C语言这是来自 MessageBox 的问候~", day,name);
}

int main() {
	SYSTEMTIME sysTime;
    GetLocalTime(&sysTime);
    
    char name[] = "大黑客吴康";        // 变量：字符串
    char day[] =getWeekdayName(sysTime.wDayOfWeek); 
    char message[100];                // 变量：用于保存拼接结果
    char *p = name;                   // 指针：指向 name
    char *q = day; 

    buildMessage(q,p,message);        // 调用函数：传入指针和输出数组

    // Windows 弹窗输出信息
    MessageBox(NULL, message, "红队初体验", MB_OK);

    return 0;
}


