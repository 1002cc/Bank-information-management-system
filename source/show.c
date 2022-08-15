#include "../include/show.h"

void admin_menu(void)
{
    printf("============银行系统(管理员)============\n");
    printf("---*           1.状态机            *---\n");
    printf("---*           2.开户              *---\n");
    printf("---*           3.销户              *---\n");
    printf("---*           4.登陆              *---\n");
    printf("---*           5.查询              *---\n");
    printf("---*           6.修改              *---\n");
    printf("---*           0.退出              *---\n");
    printf("=====================================\n\n");
}
void user_menu(void)
{
    printf("---------------银行系统(客户端)---------------\n");
    printf("---*         1.存钱      2.取钱           *---\n");
    printf("---*         3.转账      4.查询           *---\n");
    printf("---*         5.修改      0.退出           *---\n");
    printf("---------------------------------------------\n");
}

void frist_menu(void)
{
    char bank[8][20] = {"银", "行", "信", "息", "管", "理", "系", "统"};
    for (int i = 0; i < 13; i++)
    {
        printf("*");
        usleep(60000);
        fflush(stdout);
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%s", bank[i]);
        usleep(60000);
        fflush(stdout);
    }
    for (int i = 0; i < 13; i++)
    {
        printf("*");
        usleep(60000);
        fflush(stdout);
    }
    printf("\n");
    printf("****          1.管理员登陆            ****\n");
    usleep(60000);
    printf("****           2.客户端               ****\n");
    usleep(60000);
    printf("****            0.退出                ****\n");
    usleep(60000);
    for (int i = 0; i < 42; i++)
    {
        printf("*");
        usleep(60000);
        fflush(stdout);
    }
    printf("\n");
}
void change(void)
{
    printf("-----------------修改----------------\n");
    printf("---*           1.修改密码        *---\n");
    printf("---*          2.修改用户名       *---\n");
    printf("---*         3.修改电话号码      *---\n");
    printf("---*             0.退出         *---\n");
    printf("-------------------------------------\n");
}
