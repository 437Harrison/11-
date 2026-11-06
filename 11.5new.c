#define _CRT_SECURE_NO_WARNINGS   /* 用 VS 时关掉 scanf 的安全警告，gcc 下无影响 */
#include <stdio.h>
#include <windows.h>

/* 把当前行剩下的字符读掉（包括回车），避免残留输入影响下一次 scanf */
void qingli()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/* 健康打卡：返回 1 表示回菜单，返回 0 表示输入结束、要退出程序 */
int jkdk()
{
    float temp;
    int i;
    float tempz = 0;
    int ss, sz;
    int sleep;

    for (i = 1; i <= 3; i++)
    {
        printf("请输入第%d次体温:", i);          /* 原来写成 %.1f，i 是 int，应为 %d */
        while (scanf("%f", &temp) != 1)          /* 原来写成 "%.1f"，scanf 不支持精度 */
        {
            if (feof(stdin))                     /* Ctrl+Z 或输入结束 */
                return 0;
            printf("输入有误，请重新输入第%d次体温:", i);
            qingli();
        }
        qingli();
        tempz += temp;
    }

    printf("请输入收缩压与舒张压:(mmHg)\n");
    while (scanf("%d%d", &ss, &sz) != 2)
    {
        if (feof(stdin))
            return 0;
        printf("输入有误，请重新输入收缩压与舒张压:(mmHg)\n");
        qingli();
    }
    qingli();

    printf("请输入睡眠时长:(小时)\n");
    while (scanf("%d", &sleep) != 1)
    {
        if (feof(stdin))
            return 0;
        printf("输入有误，请重新输入睡眠时长:(小时)\n");
        qingli();
    }
    qingli();

    printf("----------------------------\n");
    printf("  健康报告\n");
    printf("体温平均值:%.1f  收缩压:%d mmHg  舒张压:%d mmHg  睡眠时长:%d 小时\n",
           tempz / 3.0, ss, sz, sleep);

    return 1;
}

/* 快速自诊：返回 1 表示回菜单，返回 0 表示输入结束、要退出程序 */
int ill()
{
    int ad;

    printf("请选择主要症状\n");
    printf("1  头痛    2  胃痛\n");
    printf("请输入你的症状:\n");

    if (scanf("%d", &ad) != 1)
    {
        if (feof(stdin))
            return 0;
        printf("您输入的数据有误\n");
        qingli();
        return 1;
    }
    qingli();

    switch (ad)
    {
        case 1:
            printf("头痛：注意休息、多喝水；持续加重请及时就医\n");
            break;
        case 2:
            printf("胃痛：清淡饮食、少食多餐；剧烈疼痛请及时就医\n");
            break;
        default:
            printf("您输入的数据有误\n");
            break;
    }

    return 1;
}

/* 主菜单：返回 1 表示继续循环，返回 0 表示退出程序 */
int caidan()
{
    SetConsoleOutputCP(65001);

    int ch;
    printf("----------------------------\n\n");
    printf("  欢迎来到讯飞晓医  v 3.0 \n\n");
    printf("  您的健康问诊助手  \n\n");
    printf("----------------------------\n");
    printf("  请选择:\n");
    printf("  1. 健康打卡\n");
    printf("  2. 快速自诊\n");
    printf("  0.  退出\n");

    if (scanf("%d", &ch) != 1)          /* 读失败就回菜单重来，绝不死循环 */
    {
        if (feof(stdin))
            return 0;
        printf("您输入的数据有误\n");
        qingli();
        return 1;
    }
    qingli();

    switch (ch)
    {
    case 0:
        return 0;                        /* 0 = 退出，交给 main 结束循环 */
    case 1:
        return jkdk();
    case 2:
        return ill();
    default:
        printf("您输入的数据有误\n");
        return 1;
    }
}

int main()
{
    while (caidan())
    ;                     /* caidan 返回 0 时循环结束 */
    printf("已退出，祝您健康！\n");
    return 0;
}