#include <windows.h>
#include <stdio.h>

// 获取星期几字符串
const char* getWeekdayName(int dayOfWeek) {
    const char* days[] = {
        "周日", "周一", "周二", "周三", "周四", "周五", "周六"
    };
    return days[dayOfWeek % 7];
}

// 拼接最终输出消息的函数
void buildMessage(const char* day, const char* name, char* output) {
    sprintf(output, "今天是%s！%s正在学习C语言，这是来自 MessageBox 的问候~", day, name);
}

int main() {
    // 获取系统当前时间
    SYSTEMTIME sysTime;
    GetLocalTime(&sysTime);

    // 得到星期几字符串
    const char* weekday = getWeekdayName(sysTime.wDayOfWeek);

    // 用户名（可以换成你自己的）
    char name[] = "大黑客吴康";

    // 构造输出消息
    char message[256];
    buildMessage(weekday, name, message);

    // 弹窗输出
    MessageBox(NULL, message, "红队初体验", MB_OK);

    return 0;
}

