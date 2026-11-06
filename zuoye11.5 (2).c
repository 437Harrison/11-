#include <stdio.h>
#include <windows.h>
int jkdk()
{
    float temp;
    int i;
    float tempz = 0;
    int ss,sz;
    int sleep;
    for(i=1;i<=3;i++)
    {
        printf("请输入第%d次体温:( ℃)",i);
        scanf("%f",&temp);
        tempz+=temp;
    }
    printf("请输入收缩压与舒张压:(mmHg)\n");
    scanf("%d%d",&ss,&sz);
    printf("请输入睡眠时长:(小时)\n");
    scanf("%d",&sleep);
    printf("----------------------------\n");
    printf("  健康报告\n");
    printf("体温平均值:%f  ℃ 收缩压:%d mmHg  舒张压:%d mmHg  睡眠时长:%d 小时\n",tempz/3.0,ss,sz,sleep);
    return 1;
}
int ill()
{   int ad;
    int cd;
    int bd;
    printf("请选择主要症状\n");
    printf("1  头痛    2  胃痛\n");
    printf("请输入你的症状:\n");
    scanf("%d",&ad);
    switch(ad)
    {
        case 1:
        printf("请选择次要要症状\n");
        printf("1  没发烧  2  有发烧\n");
        scanf("%d",&cd);
        switch(cd)
        {
            case 1:
                printf("头痛 没发烧：注意休息、多喝水；持续加重请及时就医\n");
                break;
            case 2:
                printf("头痛 有发烧：尽快就医、按时吃药\n");
                break;
        }
            break;
        case 2:
        printf("请选择次要要症状\n");
        printf("1  没发烧  2  有发烧\n");
        scanf("%d",&bd);
        switch(bd)
        {
            case 1:
                printf("胃痛没发烧：清淡饮食、少食多餐；剧烈疼痛请及时就医\n");
                break;
            case 2:
                printf("胃痛有发烧：尽快就医\n");
                break;
        }
        default:
        printf("您输入的数据有误\n");
        return 1;
    }
    return 1;
}
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
    if(scanf("%d",&ch)!=1)
    {
        return 0;
    }
    switch(ch)
    {
    case 0:
        return 0;
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
    while(caidan());
    printf("欢迎您下次使用\n");
    return 0;
}