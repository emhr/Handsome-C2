#include <windows.h>   // ���� Windows API
#include <stdio.h>

// �������壺ƴ���ַ���
//C�����﷨����������/����/ָ�룩	��д�򵥺������� MessageBox ���
void buildMessage(char *day, char * name, char *output) {
    sprintf(output, "������%s��%s����ѧϰC������������ MessageBox ���ʺ�~", day,name);
}

int main() {
	SYSTEMTIME sysTime;
    GetLocalTime(&sysTime);
    
    char name[] = "��ڿ��⿵";        // �������ַ���
    char day[] =getWeekdayName(sysTime.wDayOfWeek); 
    char message[100];                // ���������ڱ���ƴ�ӽ��
    char *p = name;                   // ָ�룺ָ�� name
    char *q = day; 

    buildMessage(q,p,message);        // ���ú���������ָ����������

    // Windows ���������Ϣ
    MessageBox(NULL, message, "��ӳ�����", MB_OK);

    return 0;
}


