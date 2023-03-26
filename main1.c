#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 20  // 姓名最大长度
#define MAX_COMMUNITY_LEN 30  // 小区名最大长度



// 电费记录结构体
typedef struct Record {
    char id[10];  // 户号
    char name[MAX_NAME_LEN];  // 姓名
    char community[MAX_COMMUNITY_LEN];  // 小区名
    int peopleNum;  // 家庭人口数
    int year; // 年份
    int month;  // 月份
    float peakUsage;  // 峰时用电量
    float valleyUsage;  // 谷时用电量
    float totalUsage;  // 总用电量
    float price;  // 总电费
    int hasPeakValleyPrice;  // 是否参加峰谷计价政策，1为参加，0为不参加
    struct Record* next;
} Record, *pRecord;
//遍历链表
void traverseList(pRecord head);
/*按时间顺序排序链表*/
void sortRecordByTime(pRecord head);
/* 按户号大小排序 */
void sortRecordById(pRecord head);
//按户号搜索
pRecord searchRecord(pRecord head, char* id);
// 修改是否参加峰谷计价政策
void modifyPeakValleyPolicy(pRecord head,char *id);
// 修改指定月份的峰谷用电记录
void modifyPeakValleyUsage(pRecord head,char *id);
//删除
void deleteRecord(pRecord head);
// 计算电费
int calculatePrice(pRecord record);
//户号 姓名 小区名 家庭人口数 年份 月份 峰时用电量(kWh) 谷时用电量(kWh) 总用电量(kWh) 是否参加峰谷计价政策(1为参加，0为不参加)
// 从文件中读取电费记录，存入链表
pRecord readRecordsFromFile(char* fileName);
//主菜单
void menuMain(pRecord record_head);
/*住户电费记录管理*/
void manageRecord(pRecord head);
// 添加住户电费记录信息
void addRecord(pRecord head);
/*按户号查询电费记录信息*/
void findRecordById(pRecord head);
//按小区查询
void findRecordByCommunity(pRecord head);
//查找住户选项
void findRecordOption(pRecord head);
//户号修改
void modifyRecord(pRecord head);
// @brief 供电公司工作人员入口
// @param record_head 电费记录链表头指针
// 
void staffEnter(pRecord record_head);
int hasExpandedCommunity(pRecord head ,char *community);
void expandCommunity(pRecord head);
// @brief 已扩容小区名单
// @param head 电费记录链表头指针
// /
void priorityUnListCommunity(pRecord head);

// @brief 未扩容小区优先名单
// @param head 电费记录链表头指针
// /
void priorityListCommunity(pRecord head);

// @brief 急需扩容小区名单
// @param head 电费记录链表头指针
// /
void needpriorityListCommunityLen(pRecord head);


// 不急需扩容小区名单
void unneededpriorityListCommunityLevel(pRecord head);
//是否扩容
int hasExpandedCommunity(pRecord head,char *community) {
    pRecord curr = head;
    while (curr != NULL) {
        if (strcmp(curr->community, community) == 0 && curr->hasPeakValleyPrice == 1) {
            return 1; // 已经扩容
        }
        curr = curr->next;
    }
    return 0; // 没有扩容
}

//遍历链表

// void traverseList(pRecord head) {
//     pRecord p = head;
//     while (p->next!= NULL) {
//     printf("户号：%s 户名：%s 小区：%s 人数：%d 参加峰谷计价：%d\n", p->id, p->name, p->community, p->peopleNum, p->hasPeakValleyPrice);
//     printf("日期\t\t峰时用电量\t谷时用电量\t电费\n");
//     printf("%d年%d月\t%.2f度\t%.2f度\t\t%.2f元\n", p->year, p->month, p->peakUsage, p->valleyUsage, p->price);
//     pRecord q = p->next;
//     while (q != NULL && strcmp(q->id, p->id) == 0) {
//             printf("%d年%d月\t%.2f度\t%.2f度\t\t%.2f元\n", q->year, q->month, q->peakUsage, q->valleyUsage, q->price);
//             q = q->next;
//         }
//         p = q;
//     }
// }
// void traverseList(pRecord head) {
//     pRecord p = head;
//     while (p != NULL) {
//     printf("户号：%s 户名：%s 小区：%s 人数：%d 参加峰谷计价：%d\n", p->id, p->name, p->community, p->peopleNum, p->hasPeakValleyPrice);
//     printf("日期\t峰时用电量\t谷时用电量\t电费\n");
//     printf("%d年%d月\t%.2f度\t%.2f度\t%.2f元\n", p->year, p->month, p->peakUsage, p->valleyUsage, p->price);
//     // 计算年平均用电和月平均用电
//     float yearTotalUsage = p->totalUsage;
//     int yearCount = 1;
//     int prevMonth = p->month;
//     float monthTotalUsage = p->totalUsage;
//     int monthCount = 1;

//     pRecord q = p->next;
//     while (q != NULL && strcmp(q->id, p->id) == 0) {
//         printf("%d年%d月\t%.2f度\t%.2f度\t%.2f元\n", q->year, q->month, q->peakUsage, q->valleyUsage, q->price);
        
//         // 计算年平均用电和月平均用电
//         yearTotalUsage += q->totalUsage;
//         yearCount++;
//         if (q->month == prevMonth) {
//             monthTotalUsage += q->totalUsage;
//             monthCount++;
//         } else {
//             printf("%d年%d月平均用电量：%.2f度\n", p->year, prevMonth, monthTotalUsage / monthCount);
//             monthTotalUsage = q->totalUsage;
//             monthCount = 1;
//         }
//         prevMonth = q->month;

//         q = q->next;
//     }
//     printf("%d年%d月平均用电量：%.2f度\n", p->year, prevMonth, monthTotalUsage / monthCount);
//     printf("%d年平均用电量：%.2f度\n", p->year, yearTotalUsage / yearCount);

//     p = q;
// }
// }
void traverseList(pRecord head) {
    pRecord p = head;
    while (p->next != NULL) {
        printf("户号：%s 户名：%s 小区：%s 人数：%d 参加峰谷计价：%d\n", p->id, p->name, p->community, p->peopleNum, p->hasPeakValleyPrice);
        printf("日期\t\t峰时用电量\t谷时用电量\t电费\n");
        printf("%d年%d月\t%.2f度\t%.2f度\t%.2f元\n", p->year, p->month, p->peakUsage, p->valleyUsage, p->price);

        // 计算年平均用电和月平均用电
        float yearTotalUsage = p->totalUsage;
        int yearCount = 1;
        int prevMonth = p->month;
        float monthTotalUsage = p->totalUsage;
        int monthCount = 1;
        int currentYear = p->year;

        pRecord q = p->next;
        while (q != NULL && strcmp(q->id, p->id) == 0) {
            printf("%d年%d月\t%.2f度\t%.2f度\t%.2f元\n", q->year, q->month, q->peakUsage, q->valleyUsage, q->price);
            
            // 计算年平均用电和月平均用电
            yearTotalUsage += q->totalUsage;
            yearCount++;
            if (q->year == currentYear && q->month == prevMonth) {
                monthTotalUsage += q->totalUsage;
                monthCount++;
            } else {
                // printf("%d年%d月平均用电量：%.2f度\n", currentYear, prevMonth, monthTotalUsage / monthCount);
                monthTotalUsage = q->totalUsage;
                monthCount = 1;
            }
            prevMonth = q->month;
            currentYear = q->year;

            q = q->next;
        }
        // printf("%d年%d月平均用电量：%.2f度\n", currentYear, prevMonth, monthTotalUsage / monthCount);
        printf("%d年总月平均用电量：%.2f度\n", p->year, yearTotalUsage / yearCount);
        printf("%d年平均用电量：%.2f度\n" , p->year,yearTotalUsage);

        p = q;
    }
} 


/*按时间顺序排序链表*/
void sortRecordByTime(pRecord head) {
    if (head == NULL || (head)->next == NULL) {
        return;
    }
    pRecord prev, curr, temp;
    prev = head;
    curr = prev->next;
    prev->next = NULL;
    while (curr) {
        temp = curr->next;
        if (prev->year > curr->year || (prev->year == curr->year && prev->month >= curr->month)) {
            curr->next = prev;
            head = curr;
        } else {
            pRecord p = head;
            while (p->next != NULL && (p->next->year < curr->year || (p->next->year == curr->year && p->next->month < curr->month))) {
                p = p->next;
            }
            curr->next = p->next;
            p->next = curr;
        }
        curr = temp;
    }
}

/* 按户号大小排序 */
void sortRecordById(pRecord head) {
    pRecord p, q, end, pre;
    pre = NULL;
    end = NULL;
    while(pre != NULL){
		getchar();
	}
    while (head->next != end) {
        p = head;
        q = p->next;
        while (q->next != end) {
            if (strcmp(q->id, q->next->id) > 0) {
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = q;
                q = p->next;
            }
            p = p->next;
            q = p->next;
        }
        end = q;
        pre = head;
    }
}
//按户号搜索
pRecord searchRecord(pRecord head, char* id) {
    pRecord p = head;
    while (p != NULL && strcmp(p->id, id) != 0) {
        p = p->next;
    }
    return p;
}
// 修改是否参加峰谷计价政策
void modifyPeakValleyPolicy(pRecord head,char *id) {
  
    pRecord p = searchRecord(head,id);
    if (p == NULL)
    {
        printf("未找到该户号的电费记录信息。\n");
        return ;
    }

    int hasPolicy;
    printf("请输入是否参加峰谷计价政策，1为参加，0为不参加：");
    scanf("%d", &hasPolicy);
    p->hasPeakValleyPrice = hasPolicy;
    printf("修改成功！\n");
}

// 修改指定月份的峰谷用电记录
void modifyPeakValleyUsage(pRecord head,char *id) {
    pRecord p = searchRecord(head,id);
    if (p == NULL) {
        printf("未找到指定户号的电费记录！\n");
        return;
    }
    int year, month;
    printf("请输入要修改的年份和月份：");
    scanf("%d%d", &year, &month);
    if (year != p->year || month != p->month) {
        printf("未找到指定月份的用电记录！\n");
        return;
    }
    printf("请输入峰时用电量和谷时用电量：");
    scanf("%f%f", &p->peakUsage, &p->valleyUsage);
    p->totalUsage = p->peakUsage + p->valleyUsage;
    p->price = p->totalUsage * (p->hasPeakValleyPrice ? 0.6 : 1.0);
    printf("修改成功！\n");
}

void deleteRecord(pRecord head) {
    char id[10];
    int year, month;

    printf("请输入要删除的户号 ");
    scanf("%s", id);
    int flag;
    pRecord current = head;
    pRecord previous = NULL;
    while (current != NULL) {
        if (strcmp(current->id, id) == 0) {
            if (current->next != NULL && strcmp(current->next->id, id) == 0) {
                printf("找到此户号的多条记录。输入要删除的记录的年份和月份。\n");
                printf("年份: ");
                scanf("%d", &year);
                printf("月份: ");
                scanf("%d", &month);

            }
            if (current != NULL && strcmp(current->id, id)== 0 && current->year == year && current->month == month) {
                if (previous != NULL) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                free(current);
                printf("删除成功！.\n");
                return;
            }
            else
            {
                printf("没有该日期的电费记录请重新输入\n");
            }
        }
        previous = current;
        current = current->next;
    }

    printf("未找到该户号的电费记录信息。\n");
}


// 计算电费
int calculatePrice(pRecord record) {
    float totalUsage = record->totalUsage;  // 总用电量
    float peakUsage = record->peakUsage;  // 峰时用电量
    float valleyUsage = record->valleyUsage;  // 谷时用电量
    float price;  // 总电费
    int peopleNum = record->peopleNum;  // 家庭人口数
    int hasPeakValleyPrice = record->hasPeakValleyPrice;  // 是否参加峰谷计价政策，1为参加，0为不参加
    // 根据月用电量档次计算总电费
    if (totalUsage <= 230) {
        price = totalUsage * (hasPeakValleyPrice ? (peakUsage * 0.5583 + valleyUsage * 0.3583) : 0.5283);
    } else if (totalUsage <= 400) {
        price = 230 * (hasPeakValleyPrice ? (peakUsage * 0.5583 + valleyUsage * 0.3583) : 0.5283) +
                (totalUsage - 230) * (hasPeakValleyPrice ? (peakUsage * 0.6083 + valleyUsage * 0.4083) : 0.5783);
    } else {
        price = 230 * (hasPeakValleyPrice ? (peakUsage * 0.5583 + valleyUsage * 0.3583) : 0.5283) +
                170 * (hasPeakValleyPrice ? (peakUsage * 0.6083 + valleyUsage * 0.4083) : 0.5783) +
                (totalUsage - 400) * (hasPeakValleyPrice ? (peakUsage * 0.8583 + valleyUsage * 0.6583) : 0.8283);
    }

    // 根据家庭人口数增加阶梯电价基数
    if (peopleNum >= 5) {
        if (peopleNum < 7) {
            price += 100;
        } else {
            price += 200;
        }
    }

    return price/100;
}

//户号 姓名 小区名 家庭人口数 年份 月份 峰时用电量(kWh) 谷时用电量(kWh) 总用电量(kWh) 是否参加峰谷计价政策(1为参加，0为不参加)
// 从文件中读取电费记录，存入链表
pRecord readRecordsFromFile(char* fileName) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("文件打开失败\n");
        return NULL;
    }

    char line[1024];
    pRecord head = NULL;
    pRecord tail = NULL;

    while (fgets(line, 1024, fp)) {
        pRecord record = (pRecord)malloc(sizeof(Record));
        sscanf(line, "%s %s %s %d %d %d %f %f %f %d", record->id, record->name, record->community, &record->peopleNum,&record->year, &record->month, &record->peakUsage, &record->valleyUsage, &record->totalUsage, &record->hasPeakValleyPrice);
        record->price = calculatePrice(record);  // 根据电费记录计算电费
        record->next = NULL;

        if (head == NULL) {
            head = tail = record;
        } else {
            tail->next = record;
            tail = record;
        }
    }

    fclose(fp);
    return head;
}


// @param record_head 电费记录链表头指针
// 主菜单
void menuMain(pRecord record_head) {
    int choice = -1;

    while (choice != 0) {
        system("cls"); // 清屏，适用于Linux/MacOS，Windows可以改为system("cls");

        printf("********** 电费管理系统 **********\n\n");
        printf("[1] 电费数据统计员\n");
        printf("[2] 供电公司工作人员\n");
        printf("[0] 返回\n\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                manageRecord(record_head);
                break;
            case 2:
                staffEnter(record_head);
                break;
            case 0:
                printf("\n返回主菜单...\n");
                break;
            default:
                printf("\n输入有误，请重新输入...\n");
                break;
        }
        printf("\n按回车键继续...");
        getchar(); // 清除输入缓冲区
        getchar();
    }
}




// @brief 住户电费记录管理菜单
// @param head 电费记录链表头指针
/*住户电费记录管理*/
void manageRecord(pRecord head) {
    int option;
    do {
        printf("\n=============== 电费数据统计员 ===============\n");
        printf("[1] 查询电费记录信息\n");
        printf("[2] 添加住户电费记录信息\n");
        printf("[3] 删除住户电费记录信息\n");
        printf("[4] 修改住户电费记录信息\n");
        printf("[0] 返回\n");
        printf("请输入选项: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                // 查询电费记录信息
                findRecordOption(head);
                break;
            case 2:
                // 添加住户电费记录信息
                addRecord(head);
                break;
            case 3:
                // 删除住户电费记录信息
                deleteRecord(head);
                break;
            case 4:
                // 修改住户电费记录信息
                modifyRecord(head);
                break;
            case 0:
                printf("返回上级菜单\n");
                break;
            default:
                printf("无效选项，请重新输入\n");
                break;
        }
    } while (option != 0);
}
// 添加住户电费记录信息
void addRecord(pRecord head) {
    char community[MAX_COMMUNITY_LEN];
    printf("请输入小区名：");
    scanf("%s", community);
    // // 查询该小区是否已扩容
    // // 如果未扩容，提示无法添加新的住户电费记录
    // // 如果已扩容，则进行添加操作
    // // 这里假设查询已扩容的操作在另外一个函数中实现，返回查询结果为1表示已扩容，为0表示未扩容
    // int hasExpanded = hasExpandedCommunity(head,community);
    // if (hasExpanded == 0) {
    //     printf("该小区未扩容，无法添加新的住户电费记录。\n");
    //     return;
    // }
    pRecord p1 = head->next;

    while (p1->next!=NULL) 
    {
        if (strcmp(p1->community, community) == 0) {
            break;
        }
        p1 = p1->next;
    }
    if (p1->next==NULL)
    {
        int flag;
        printf("该小区是否已扩容(输入1表示已扩容,输入0表示未扩容)\n");
        scanf("%d",&flag);
    }
    char id[10];
    printf("请输入户号：");
    scanf("%s", id);

    // 查询是否已存在该户号的住户电费记录
    // 如果已存在，则提示用户，让用户确认是否覆盖原有记录
    // 如果不存在，则进行添加操作
    pRecord p = searchRecord(head, id);
    if (p != NULL) {
        printf("已存在该户号的住户电费记录，是否覆盖原有记录？(Y/N)\n");
        char confirm;
        scanf(" %c", &confirm);
        if (confirm == 'N' || confirm == 'n') {
            return;
        }
    } else {
        p = (pRecord)malloc(sizeof(Record));
        strcpy(p->id, id);
        p->next = head->next;
        head->next = p;
    }

    printf("请输入户名：");
    scanf("%s", p->name);

    printf("请输入家庭人数：");
    scanf("%d", &(p->peopleNum));

    printf("是否参加峰谷计价？(1为参加，0为不参加)：");
    scanf("%d", &(p->hasPeakValleyPrice));

    // 添加每个月的电费记录
    while (1) {
        printf("请输入年份：");
        scanf("%d", &(p->year));
        printf("请输入月份：");
        scanf("%d", &(p->month));
        printf("请输入峰时用电量：");
        scanf("%f", &(p->peakUsage));
        printf("请输入谷时用电量：");
        scanf("%f", &(p->valleyUsage));
        p->totalUsage = p->peakUsage + p->valleyUsage;
        p->price = 0; 
		p->price = calculatePrice(p);
      
        printf("已添加%d年%d月的电费记录。\n", p->year, p->month);
        printf("是否继续添加？(Y/N)\n");
        char confirm;
        scanf(" %c", &confirm);
        if (confirm == 'N' || confirm == 'n') {
            break;
        }
    }
}


/**

@brief 按户号查找住户记录选项菜单
@param head 电费记录链表头指针
*/
/*按户号查询电费记录信息*/
void findRecordById(pRecord head) {
    char id[10];
    printf("请输入要查询的户号：");
    scanf("%s", id);
    pRecord p = head->next;
    while (p) {
        if (strcmp(p->id, id) == 0) {
            printf("户号：%s\n", p->id);
            printf("姓名：%s\n", p->name);
            printf("小区：%s\n", p->community);
            printf("家庭人口数：%d\n", p->peopleNum);
            printf("年份：%d\n", p->year);
            printf("月份：%d\n", p->month);
            printf("总用电量：%.2f\n", p->totalUsage);
            printf("总电费：%.2f\n", p->price);
            printf("峰时用电量：%.2f\n", p->peakUsage);
            printf("谷时用电量：%.2f\n", p->valleyUsage);
            printf("是否参加峰谷计价政策：%s\n", p->hasPeakValleyPrice ? "是" : "否");
            return;
        }
        p = p->next;
    }
    printf("没有找到该户号的电费记录！\n");
}
//按小区查询
void findRecordByCommunity(pRecord head) {
    char community[MAX_COMMUNITY_LEN];
    int choice;
    printf("请输入小区名：");
    scanf("%s", community);
    pRecord p = head->next;
    pRecord tempHead = (pRecord)malloc(sizeof(Record));
    tempHead->next = NULL;
    while (p) {
        if (strcmp(p->community, community) == 0) {
            pRecord temp = (pRecord)malloc(sizeof(Record));
            *temp = *p;
            temp->next = tempHead->next;
            tempHead->next = temp;

        }
        p = p->next;
    }
    if (tempHead->next == NULL) {
        printf("该小区无用电记录！\n");
        return;
    }

    do {
    printf("请选择排序方式：\n");
    printf("1.按日期顺序显示\n");
    printf("2.按户号顺序显示\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                sortRecordByTime(tempHead);
                traverseList(tempHead->next);
                break;
            case 2:
                sortRecordById(tempHead);
                traverseList(tempHead->next);
                break;
            case 0:
                break;
            default:
                printf("输入有误，请重新选择\n");
                break;
        }
    } while (choice != 0);
}

// @brief 查找住户记录选项菜单
// @param head 电费记录链表头指针
//查找住户选项
void findRecordOption(pRecord head) {
    int option;
    do {
        printf("\n[1] 按户号查询\n");
        printf("[2] 按小区查询\n");
        printf("[0] 返回\n");
        printf("请选择要进行的操作：");
        scanf("%d", &option);
        switch (option) {
            case 1:
                findRecordById(head);
                break;
            case 2:
                findRecordByCommunity(head);
                break;
            case 0:
                break;
            default:
                printf("输入有误，请重新选择\n");
                break;
        }
    } while (option != 0);
}

void modifyRecord(pRecord head){
    //按户号搜索
     char id[10];
    printf("请输修改的入户号：");
    scanf("%s", id);
    pRecord p = searchRecord(head, id);
    if (p == NULL) {
        printf("没有该用户");
        return;
    }

    int option;
    do {
        printf("\n[1] 修改是否参加峰谷计价政策\n");
        printf("[2] 修改某月的峰谷用电记录\n");
        printf("[0] 返回\n");
        printf("请选择要进行的操作：");
        scanf("%d", &option);
        switch (option) {
            case 1:
                modifyPeakValleyPolicy(head,id);
                break;
            case 2:
                modifyPeakValleyUsage(head,id);
                break;
            case 0:
                break;
            default:
                printf("输入有误，请重新选择\n");
                break;
        }
    } while (option != 0);
}


// @brief 供电公司工作人员入口
// @param record_head 电费记录链表头指针
// 
void staffEnter(pRecord head) {
    int choice = -1;
    while (choice != 0) {
        system("cls");
        printf("供电公司工作人员\n");
        printf("[1] 显示所有电费记录信息\n");
        printf("[2] 扩容管理\n");
        printf("[0] 返回\n");
        printf("请选择操作：");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                traverseList(head);
                system("pause");
                break;
            case 2:
                expandCommunity(head);
                system("pause");
                break;
            case 0:
                break;
            default:
                printf("无效的输入，请重新选择！\n");
                system("pause");
            break;
        }
    }
}

// 小区已扩容名单
void priorityUnListCommunity(pRecord head) {
	printf("已扩容小区列表：\n");
	pRecord p = head->next;
	while (p) {
		if (p->hasPeakValleyPrice) {
			printf("%s\n", p->community);
		}
		p = p->next;
	}
}

// 小区未扩容优先名单
void priorityListCommunity(pRecord head) {
	printf("未扩容小区优先列表：\n");
	pRecord p = head->next;
	// 遍历一遍获取所有小区的信息
	int count = 0;
	while (p) {
		if (!p->hasPeakValleyPrice) {
			count++;
	}
	p = p->next;
}
	// 创建一个数组，存储未扩容小区的信息
	pRecord arr[count];
	p = head->next;
	int index = 0;
	while (p) {
		if (!p->hasPeakValleyPrice) {
		arr[index++] = p;
		}
		p = p->next;
	}
	// 对未扩容小区进行按人均月用电量排序，从高到低
	for (int i = 0; i < count; i++) {
	for (int j = i + 1; j < count; j++) {
	float avg1 = arr[i]->totalUsage / (arr[i]->peopleNum * 1.0);
	float avg2 = arr[j]->totalUsage / (arr[j]->peopleNum * 1.0);
	if (avg1 < avg2) {
		pRecord tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		}	
	}
	}
	// 输出未扩容小区的信息
	for (int i = 0; i < count; i++) {
	printf("%s（%d）\n", arr[i]->community, arr[i]->peopleNum);
	}
}

// 小区急需扩容名单
void needpriorityListCommunityLen(pRecord head) {
    printf("急需扩容小区：\n");
    pRecord p = head->next;
    int len;
    while (p) {
        if (p->hasPeakValleyPrice == 0) {
            len = 0;
                for (int i = 0; i < p->peopleNum; i++) {
                    if (p->peakUsage + p->valleyUsage > 300) {
                    len++;
                    }
                }
                    if (len * 2 > p->peopleNum) {
                    printf("%s\n", p->community);
            }
        }
        p = p->next;
    }
}

// 小区不急需扩容名单
void unneededpriorityListCommunityLevel(pRecord head) {
    printf("不急需扩容小区：\n");
    pRecord p = head->next;
    int len;
    while (p) {
        if (p->hasPeakValleyPrice == 0) {
            len = 0;
            for (int i = 0; i < p->peopleNum; i++) {
                if (p->peakUsage + p->valleyUsage > 300) {
                    len++;
                    }
                }
                if (len * 2 <= p->peopleNum) {
                    printf("%s\n", p->community);
            }
        }
        p = p->next;
    }
}

// 扩容管理
void expandCommunity(pRecord head) {
int choice;
while (true) {
    printf("扩容管理\n");
    printf("[1]查看已扩容小区\n");
    printf("[2]查看未扩容小区\n");
    printf("[3]查看急需扩容小区\n");
    printf("[4]查看不急需扩容小区\n");
    printf("[0]退出扩容管理\n");
    printf("请选择：");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            priorityUnListCommunity(head);
        break;
        case 2:
            priorityListCommunity(head);
        break;
        case 3:
            needpriorityListCommunityLen(head);
        break;
        case 4:
            unneededpriorityListCommunityLevel(head);
        break;
        case 0:
        return;
        default:
        printf("输入错误，请重新输入\n");
        break;
        }
    }
}


int main()
{
    char pathname[]="input.txt";
    pRecord head = readRecordsFromFile(pathname);
    menuMain(head);
    return 0;
}
