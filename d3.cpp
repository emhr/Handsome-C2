#include <windows.h>
#include <stdio.h>

// ��ȡ���ڼ��ַ���
const char* getWeekdayName(int dayOfWeek) {
    const char* days[] = {
        "����", "��һ", "�ܶ�", "����", "����", "����", "����"
    };
    return days[dayOfWeek % 7];
}

// ƴ�����������Ϣ�ĺ���
void buildMessage(const char* day, const char* name, char* output) {
    sprintf(output, "������%s��%s����ѧϰC���ԣ��������� MessageBox ���ʺ�~", day, name);
}

int main() {
    // ��ȡϵͳ��ǰʱ��
    SYSTEMTIME sysTime;
    GetLocalTime(&sysTime);

    // �õ����ڼ��ַ���
    const char* weekday = getWeekdayName(sysTime.wDayOfWeek);

    // �û��������Ի������Լ��ģ�
    char name[] = "��ڿ��⿵";

    // ���������Ϣ
    char message[256];
    buildMessage(weekday, name, message);

    // �������
    MessageBox(NULL, message, "��ӳ�����", MB_OK);

    return 0;
}

