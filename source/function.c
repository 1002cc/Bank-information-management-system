#include "../include/function.h"

bool system_login() //管理员登陆
{
    int count = N;
    char getaccount[20] = {"chen"};
    char getpassword[20] = {"123456"};
    int count_one = 0, count_two = 0, number = 0;
    char input_account[20] = {0};
    char input_password[20] = {0};
    for (int i = 0; i < count; i++)
    {
        printf("请输入账号：\n");
        scanf("%s", input_account);
        printf("请输入密码：\n");
        scanf("%s", input_password);
        count_one = strcmp(input_account, getaccount);
        count_two = strcmp(input_password, getpassword);
        if (count_one == 0 && count_two == 0)
        {
            printf("正在登陆----\n");
            printf("--登陆成功！--\n");
            return true;
            break;
        }
        else
        {
            printf("账号或密码错误，请重新输入！！！！\n");
            number++;
            if (number >= 3)
            {
                printf("密码输入错误三次，账号已被锁定！！\n");
                break;
            }
        }
    }
}

int open_an_account(P_BANK_DATABASE_T p_bank_database) //开户
{
    int count1 = 1, count = 1, count6 = 0;
    int result1 = 0, result2 = 0;
    char name[24] = {0}, phone[12] = {0}, password[7] = {0};

    for (int i = 0; i < count; i++)
    {
        int count3 = 1, count4 = 1, count5 = 1;
        printf("---------------------开户--------------------\n");
        for (int i = 0; i < count5; i++)
        {
            printf("请输入名字：\n");
            scanf("%s", name);
            for (int j = 0; j < (p_bank_database->user_number); j++)
            {
                result2 = strcmp(name, p_bank_database->user[j].name);
                if (result2 == 0)
                {
                    printf("该用户已注册\n");
                    printf("重名继续输入:1 重新输入:0\n");
                    scanf("%d", &count6);
                    if (count6 == 1)
                    {
                        break;
                    }
                    else
                    {
                        count5++;
                        break;
                    }
                }
            }
        }
        strcpy(p_bank_database->user[p_bank_database->user_number].name, name);

        for (int j = 0; j < count4; j++) //设置11位数手机号码
        {
            printf("请输入11位手机号:\n");
            scanf("%s", phone);
            if (strlen(phone) != 11)
            {
                printf("输入错误!请输入11位手机号\n");
                count4++;
            }
            else
            {
                for (int n = 0; n < p_bank_database->user_number; n++)
                {
                    result1 = strcmp(phone, p_bank_database->user[j].phone);
                    if (result1 == 0)
                    {
                        printf("该电话号码已注册\n");
                        count4++;
                        break;
                    }
                }
            }
        }
        strcpy(p_bank_database->user[p_bank_database->user_number].phone, phone);

        for (int j = 0; j < count3; j++)
        {
            printf("请输入六位数密码：\n");
            scanf("%s", password);
            if (strlen(password) != 6)
            {
                printf("输入错误！请输入六位数密码\n");
                count3++;
            }
            else
            {
                break;
            }
        }
        strcpy(p_bank_database->user[p_bank_database->user_number].password, password);
        getbank_card(p_bank_database);
        p_bank_database->user_number++;
        printf("继续输入请输入:1  返回请输入:0  \n");
        scanf("%d", &count1);
        if (count1 == 0)
        {
            return 1;
        }
        else
        {
            count++;
        }
    }
}

int account_cancellation(P_BANK_DATABASE_T p_bank_database) //销户
{
    printf("---------------------销户--------------------\n");
    for (int i = 0; i < p_bank_database->user_number; i++)
    {
        printf("-------------------------------------------------------------\n");
        printf("第%d位用户\n用户名:%s\n", i + 1, (p_bank_database->user[i].name));
        printf("-------------------------------------------------------------\n");
    }
    int result = 0, k = 1, count = 1;
    char delete_account[24] = {0};
    for (int j = 0; j < count; j++)
    {
        printf("请输入要删除的用户：\n");
        result = scanf("%s", delete_account);
        if (result == 0)
        {
            while ((result = getchar()) != '\n')
                ;
            printf("输入错误，请重新输入！\n");
            count++;
        }
        for (int i = 0; i < p_bank_database->user_number; i++)
        {
            if ((strcmp(delete_account, (p_bank_database->user[i].name))== 0)||(strcmp(delete_account, (p_bank_database->user[i].phone))== 0))
            {
                printf("正在删除----\n");
                for (int j = 0; j < 100; j++)
                {
                    strcpy((p_bank_database->user[i].name), (p_bank_database->user[i + 1].name)); //*p[0]
                    strcpy((p_bank_database->user[i].password), (p_bank_database->user[i + 1].password));
                    strcpy((p_bank_database->user[i].phone), (p_bank_database->user[i + 1].phone));
                    strcpy((p_bank_database->user[i].bank_card), (p_bank_database->user[i + 1].bank_card));
                    strcpy((p_bank_database->user[i].money), (p_bank_database->user[i + 1].money));
                    i++;
                }
                k = 0;
                (p_bank_database->user_number)--;
                printf("删除完成\n");
            }
        }
        if (k == 1)
        {
            printf("没有找到该用户!!\n");
        }
    }
    return 1;
}

int search(P_BANK_DATABASE_T p_bank_database) //查询用户
{
    printf("-------------------查看用户------------------\n");
    int count1 = 0;
    printf("当前用户数:%d\n", p_bank_database->user_number);
    for (int i = 0; i < p_bank_database->user_number; i++)
    {
        printf("-------------------------------------------------------------\n");
        printf("第%d个用户名是:%s\n电话号码是:%s\n 密码是:%s\n银行卡号:%s\n", i + 1,
               (p_bank_database->user[i].name), (p_bank_database->user[i].phone),
               (p_bank_database->user[i].password), (p_bank_database->user[i].bank_card));
        printf("-------------------------------------------------------------\n");
    }
    printf("返回:0\n");
    scanf("%d", &count1);
    if (count1 == 0)
    {
        return 1;
    }
}

int change_all(P_BANK_DATABASE_T p_bank_database) //选择
{
    int result = 0, count = 0, count1 = 1;
    int result1 = 0;
    int flag = 0, flag1 = 0;
    char change_user_name[24] = {0};
    printf("-----------------修改------------------\n");
    printf("请输入用户名：");
    scanf("%s", change_user_name);
    for (int i = 0; i < p_bank_database->user_number; i++)
    {
        result1 = strcmp(change_user_name, p_bank_database->user[i].name);
        if (result1 == 0)
        {
            do
            {
                change();
                printf("请输入：");
                result = scanf("%d", &count);
                if (result != 1)
                {
                    while ((result = getchar()) != '\n')
                        ;
                    printf("输入错误，请重新输入！\n");
                }
                switch (count)
                {
                case 0:
                    count1 = 0;
                    break;
                case 1:
                    change_password(p_bank_database,i);
                    break;
                case 2:
                    change_name( p_bank_database,i);
                    break;
                case 3:
                    change_phone( p_bank_database,i);
                    break;
                default:
                    printf("没有这个选择！\n");
                    break;
                }
            } while (count1);
            break;
        }
        else if (result1 != 0 && i + 1 == p_bank_database->user_number)
        {
            printf("没有该用户！\n");
            break;
        }
    }
    return 1;
}

void change_two_all(P_BANK_DATABASE_T p_bank_database, int *xianzai)
{
    int result = 0;
    int count = 0, count1 = 1;
    while (count1)
    {
        change();
        printf("请输入：");
        result = scanf("%d", &count);
        if (result != 1)
        {
            while ((result = getchar()) != '\n')
                ;
            printf("输入错误，请重新输入！\n");
        }
        switch (count)
        {
        case 0:
            count1 = 0;
            break;
        case 1:
            change_password(p_bank_database, *xianzai);
            break;
        case 2:
            change_name(p_bank_database, *xianzai);
            break;
        case 3:
            change_phone(p_bank_database, *xianzai);
            break;
        default:
            printf("没有这个选择！\n");
            break;
        }
    }
}

void change_password(P_BANK_DATABASE_T p_bank_database, int flang) //修改密码
{
    int result = 0, k = 1, count6 = 1, count7 = 1;
    int count1 = 0;
    char changepassword1[1024] = {0};
    char changepassword2[1024] = {0};
    char name[1024] = {0};
    printf("--------------------修改---------------------\n");
    printf("用户：%s\n", (p_bank_database->user[flang].name));
    printf("原密码：%s\n", (p_bank_database->user[flang].password));
    do
    {
        for (int j = 0; j < count6; j++)
        {
            printf("请输入六位数密码：\n");
            scanf("%s", changepassword1);
            if (strlen(changepassword1) != 6)
            {
                printf("输入错误！请输入六位数密码\n");
                count6++;
            }
        }
        for (int j = 0; j < count7; j++)
        {
            printf("请再次输入密码：\n");
            scanf("%s", changepassword2);
            if (strlen(changepassword2) != 6)
            {
                printf("输入错误！请输入六位数密码\n");
                count7++;
            }
        }
        if (strcmp(changepassword1, changepassword2) != 0)
        {
            printf("两次密码不一致，请重新输入\n");
            k = 3;
            count1 = 1;
        }
        else
        {
            strcpy((p_bank_database->user[flang].password), changepassword2);
            k = 0;
            printf("修改密码成功！！\n");
            count1 = 0;
        }

    } while (count1);
}

void change_name(P_BANK_DATABASE_T p_bank_database,int flang) //修改用户名
{
    int count5 = 1, result2 = 0, count6 = 0;
    char change_user_name[24] = {0};
    printf("-----------------修改用户名------------------\n");
    printf("原用户名：%s\n", (p_bank_database->user[flang].name));
    for (int i = 0; i < count5; i++)
    {
        printf("请输入名字：\n");
        scanf("%s", change_user_name);
        for (int j = 0; j < p_bank_database->user_number; j++)
        {
            result2 = strcmp(change_user_name, (p_bank_database->user[j].name));
            if (result2 == 0)
            {
                printf("该用户已注册\n");
                printf("重名继续:1 重新输入:0\n");
                scanf("%d", &count6);
                if (count6 == 1)
                {
                    break;
                }
                else
                {
                    count5++;
                    break;
                }
            }
        }
        strcpy((p_bank_database->user[flang].name), change_user_name);
        printf("修改成功！\n");
    }
}

void change_phone(P_BANK_DATABASE_T p_bank_database,int flang) //修改电话号码
{
    char name[24] = {0}, newphone[12] = {0};
    int result = 0, count6 = 1, result1 = 0, result2 = 0, result3 = 0, count4 = 0, k = 0;
    printf("-----------------修改电话号码------------------\n");
    printf("用户：%s\n", (p_bank_database->user[flang].name));
    printf("原电话号码:%s\n", (p_bank_database->user[flang].phone));
    for (int j = 0; j < count6; j++)
    {
        printf("请输入新电话号码:\n");
        scanf("%s", newphone);
        if (strlen(newphone) != 11)
        {
            printf("输入错误!请输入11位数电话号码\n");
            count6++;
        }
        else
        {
            for (int n = 0; n < p_bank_database->user_number; n++)
            {
                result3 = strcmp(newphone, (p_bank_database->user[n].phone));
                if (result3 == 0)
                {
                    printf("该电话号码已注册\n");
                    k = 1;
                    break;
                }
            }
            if (k == 0)
            {
                strcpy((p_bank_database->user[flang].phone), newphone);
                printf("修改成功\n");
            }
        }
    }
}
bool login(P_BANK_DATABASE_T p_bank_database,int *xianzai) //登陆
{
    int bnm = 0, i = 0, lop = 2;
    do
    {
        int count_one = 0, count_two = 0, count_four = 0;
        char input_account[20] = {0};
        char input_password[20] = {0};
        printf("-------------------登陆--------------------\n");
        printf("请输入用户名或手机号:\n");
        scanf("%s", input_account);
        printf("请输入密码：\n");
        scanf("%s", input_password);
        for (i = 0; i < p_bank_database->user_number; i++)
        {
            count_one = (strcmp(input_account, p_bank_database->user[i].name));
            count_four = (strcmp(input_account, (p_bank_database->user[i].phone)));
            count_two = (strcmp(input_password, (p_bank_database->user[i].password)));
            if ((count_one == 0 || count_four == 0) && count_two == 0)
            {
                bnm = 0;
                lop = 1;
                *xianzai = i;
                printf("正在登陆----\n");
                printf("--登陆成功！--\n");
                return true;
                break;
            }
            else
            {
                lop = 0;
            }
        }
        if (lop == 0)
        {
            printf("密码错误，请重新输入！！！！\n");
            bnm++;
            if (bnm >= 3)
            {
                printf("输入错误三次，账号已被冻结\n");
                bnm = 0;
            }
        }
    } while (bnm);
}

int double_menu(P_BANK_DATABASE_T p_bank_database)
{
    bool login_user = false;
    int xianzai = 0; //判断现在登陆的用户是谁
    login_user = login(p_bank_database, &xianzai);
    if (login_user == true)
    {
        int chi = 1;
        do
        {
            int choose1 = 0, result = 0;
            user_menu();
            while (1)
            {
                result = scanf("%d", &choose1);
                if (result != 1)
                {
                    while ((result = getchar()) != '\n')
                        ; /*清空缓冲区*/

                    printf("数据输入错误，请重新输入!\n");
                }
                else
                {
                    break;
                }
            }
            switch (choose1)
            {
            case 0:
                chi = 0;
                break;
            case 1:
                save_money(p_bank_database, &xianzai);
                break;
            case 2:
                draw_money(p_bank_database, &xianzai);
                break;
            case 3:
                transfer_accounts(p_bank_database, &xianzai);
                break;
            case 4:
                search_money(p_bank_database, &xianzai);
                break;
            case 5:
                change_two_all(p_bank_database, &xianzai);
                break;
            default:
                printf("没有这个选择\n");
                break;
            }
        } while (chi);
    }
    else
    {
        printf("登陆失败\n");
    }
}

int save_money(P_BANK_DATABASE_T p_bank_database, int *xincon) //存钱
{
    int money = 0;
    int money2 = 0;
    char money1[1024] = {0};
    char money3[1024] = {0};
    int n = 0, i = 0, j = 0;
    printf("-------------------存钱--------------------\n");
    printf("你的余额为：%s\n", (p_bank_database->user[*xincon].money));
    printf("请输入你要存的金额：\n");
    scanf("%d", &money);
    strcpy(money1, (p_bank_database->user[*xincon].money));
    sscanf(money1, "%d", &money2);
    money2 += money;
    while (money2 > 0)
    {
        money1[n] = (money2 % 10) + '0';
        money2 = money2 / 10;
        n++;
    }
    int length = strlen(money1);
    reverse(money1, money1 + length - 1);
    strcpy((p_bank_database->user[*xincon].money), money1);
    printf("当前余额为：%s\n", (p_bank_database->user[*xincon].money));
}

int draw_money(P_BANK_DATABASE_T p_bank_database, int *xincon) //取钱
{
    int money = 0;
    int money2 = 0;
    char money1[1024] = {0};
    char money3[1024] = {0};
    int n = 0, i = 0, j = 0;
    // printf("%d\n", *xincon);
    printf("-------------------取钱--------------------\n");
    printf("你的余额为：%s\n", (p_bank_database->user[*xincon].money));
    printf("请输入你要取的金额：\n");
    scanf("%d", &money);
    strcpy(money3, (p_bank_database->user[*xincon].money));
    sscanf(money3, "%d", &money2);
    // printf("%d\n", money2);
    if (money > money2)
    {
        printf("余额不足\n");
    }
    else
    {
        money2 = money2 - money;
        if (money2 == 0)
        {
            memset(money1, 48, 1);
        }
        else
        {
            while (money2 > 0) //将int型数据赋值给char数组，但数据是倒过来的
            {
                money1[n] = (money2 % 10) + '0';
                money2 = money2 / 10;
                n++;
            }
            int length = strlen(money1);
            reverse(money1, money1 + length - 1);
        }
        strcpy((p_bank_database->user[*xincon].money), money1); //最后赋值给*(p[4] + *xincon)
        printf("当前余额为：%s\n", (p_bank_database->user[*xincon].money));
    }
}

int reverse(char *p_left, char *p_right) //处理数据
{
    while (p_left < p_right)
    {
        (*p_left) ^= (*p_right);
        (*p_right) ^= (*p_left);
        (*p_left) ^= (*p_right);

        p_left++;
        p_right--;
    }

    return 0;
}

int transfer_accounts(P_BANK_DATABASE_T p_bank_database, int *xincon) //转账
{
    char transfer_name[1024] = {0}; //转账账号输入
    int money = 0;                  //转账金额输入
    int money2 = 0;
    int money5 = 0;
    int result1 = 0, result2 = 0, result3 = 0, result4 = 0;
    int n = 0, n1 = 0, i = 0, j = 0, flag = 0;
    char money1[1024] = {0};
    char money6[1024] = {0};
    printf("-------------------转账--------------------\n");
    printf("请输入转账用户名/电话号码:");
    scanf("%s", transfer_name);
    for (int k = 0; k < p_bank_database->user_number; k++)
    {
        result1 = strcmp(transfer_name, (p_bank_database->user[k].name));
        result3 = strcmp(transfer_name, (p_bank_database->user[k].phone));
        result4 = strcmp(transfer_name, (p_bank_database->user[*xincon].phone));
        result2 = strcmp(transfer_name, (p_bank_database->user[*xincon].name));
        if ((result1 == 0 || result3 == 0) && result2 != 0)
        {
            flag = 1; // /判断是否找到用户
            printf("转账用户名：%s\n", (p_bank_database->user[k].name));
            printf("请输入转账金额：\n");
            scanf("%d", &money);
            strcpy(money1, (p_bank_database->user[*xincon].money));
            sscanf(money1, "%d", &money2);
            strcpy(money6, (p_bank_database->user[k].money));
            sscanf(money6, "%d", &money5);
            if (money > money2)
            {
                printf("余额不足\n");
                printf("转账失败！\n");
            }
            else
            {
                printf("正在转账-----\n");
                money5 += money;
                while (money5 > 0)
                {
                    money6[n] = (money5 % 10) + '0';
                    money5 = money5 / 10;
                    n++;
                }
                int length4 = strlen(money6);
                reverse(money6, money6 + length4 - 1);
                strcpy((p_bank_database->user[k].money), money6);
                money2 = money2 - money;
                if (money2 == 0)
                {
                    memset(money1, 48, 1);
                }
                else
                {
                    while (money2 > 0) //将int型数据赋值给char数组，但数据是倒过来的
                    {
                        money1[n1] = (money2 % 10) + '0';
                        money2 = money2 / 10;
                        n1++;
                    }
                    int length = strlen(money1);
                    reverse(money1, money1 + length - 1);
                }
                strcpy((p_bank_database->user[*xincon].money), money1); //最后赋值给*(p[4] + *xincon)
                printf("转账成功！\n");
                printf("当前余额为：%s\n", (p_bank_database->user[*xincon].money));
                break;
            }
        }
        else if (result2 == 0 && k + 1 == p_bank_database->user_number)
        {
            printf("不能给自己账号转账！，请重新输入\n");
        }
        else if (flag == 0 && k + 1 == p_bank_database->user_number)
        {
            printf("没有找到！\n");
        }
    }
}

int search_money(P_BANK_DATABASE_T p_bank_database,int *xincon) //查看钱
{
    printf("-------------------查询--------------------\n");
    printf("用户名:%s\n电话号码:%s\n银行卡号:%s\n", (p_bank_database->user[*xincon].name), (p_bank_database->user[*xincon].phone), (p_bank_database->user[*xincon].bank_card));
    printf("你的余额为：%s\n", (p_bank_database->user[*xincon].money));
}