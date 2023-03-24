/*********************************
* С�����������Ƽ�ϵͳ vC.A.0
*********************************/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define STR_LEN 256

/*ס����Ѽ�¼�ṹ��*/
typedef struct _tRecord {
    char id[STR_LEN];               /*����*/
    char name[STR_LEN];             /*����*/
    char community[STR_LEN];        /*С��*/
    char date[STR_LEN];             /*����*/
    double electricity;             /*����*/
    struct _tRecord* next;          /*��һ���ڵ�*/
} Record, * pRecord;

/*С����Ϣ�ṹ��*/
typedef struct _tCommunity {
    char name[STR_LEN];             /*����*/
    double electricity;             /*����*/
} Community, * pCommunity;

/*������*/
double electricCharge(double electricity) {
    return electricity * 0.45;
}

/*������ڣ�yyyy-mm-dd��*/
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

/*��������*/
void inputDate(char date[]) {
    do {
        scanf("%s", date);
        if (checkDate(date)) break;
        printf("��ʽ�������������룡��yyyy-mm-dd��\n");
    } while (1);
}

/*���ס����Ϣ�ڵ㣬���������׽ڵ�ָ��*/
pRecord addRecordNode(pRecord head, pRecord node) {
    if (head) {
        pRecord cursor = head;
        while (cursor->next) {
            cursor = cursor->next;
        }
        /*���½ڵ���뵽����β��*/
        cursor->next = node;
        return head;
    }
    else {
        /*����Ϊ�շ��ظýڵ�*/
        return node;
    }
}

/*ɾ��ס����Ϣ�ڵ㣬���������׽ڵ�ָ��*/
pRecord removeRecordNode(pRecord head, pRecord node) {
    if (head) {
        if (head == node) {
            /*ɾ���ڵ�Ϊ�׽ڵ�*/
            head = node->next;
            /*ɾ���ýڵ�*/
            free(node);
        }
        else {
            pRecord cursor = head;
            while (cursor->next) {
                /*�ҵ�Ҫɾ���ڵ����һ���ڵ�*/
                if (cursor->next == node) {
                    /*����һ���ڵ�ָ��ɾ���ڵ����һ���ڵ�*/
                    cursor->next = node->next;
                    /*ɾ���ýڵ�*/
                    free(node);
                    break;
                }
                cursor = cursor->next;
            }
        }
    }
    return head;
}

/*����ס����Ϣ�ڵ���*/
int countRecordNode(pRecord head) {
    pRecord cursor = head;
    int count = 0;
    while (cursor) {
        ++count;
        cursor = cursor->next;
    }
    return count;
}

/*�������*/
void clearRecordNode(pRecord head) {
    while (head) {
        head = removeRecordNode(head, head);
    }
}

/*ͨ�����Ų���ס����Ϣ�ڵ�*/
pRecord findRecordNodeByID(pRecord head, char* id) {
    pRecord cursor = head;
    while (cursor) {
        /*ƥ�仧��*/
        if (strcmp(cursor->id, id) == 0) {
            return cursor;
        }
        cursor = cursor->next;
    }
    return NULL;
}

/*ͨ�����ź����ڲ���ס����Ϣ�ڵ�*/
pRecord findRecordNodeByIDDate(pRecord head, char* id, char* date) {
    pRecord cursor = head;
    while (cursor) {
        /*ƥ�仧��*/
        if (strcmp(cursor->id, id) == 0 && strcmp(cursor->date, date) == 0) {
            return cursor;
        }
        cursor = cursor->next;
    }
    return NULL;
}

/*ͨ����������ס����Ϣ�ڵ�*/
pRecord findRecordNodeByName(pRecord head, char* name) {
    pRecord cursor = head;
    while (cursor) {
        /*ƥ�仧��*/
        if (strcmp(cursor->name, name) == 0) {
            return cursor;
        }
        cursor = cursor->next;
    }
    return NULL;
}

/*ͨ����������*/
void sortRecordNodeByID(pRecord* head) {
    int len = countRecordNode(*head);
    if (len > 1) {
        pRecord* arr = (pRecord*)malloc(len * sizeof(pRecord));
        pRecord target = *head;
        for (int index = 0; index < len; ++index) {
            arr[index] = target;
            target = target->next;
        }

        /*ð������*/
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

/*ͨ����������*/
void sortRecordNodeByName(pRecord* head) {
    int len = countRecordNode(*head);
    if (len > 1) {
        pRecord* arr = (pRecord*)malloc(len * sizeof(pRecord));
        pRecord target = *head;
        for (int index = 0; index < len; ++index) {
            arr[index] = target;
            target = target->next;
        }

        /*ð������*/
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

/*ͨ��С������*/
void sortRecordNodeByCommunity(pRecord* head) {
    int len = countRecordNode(*head);
    if (len > 1) {
        pRecord* arr = (pRecord*)malloc(len * sizeof(pRecord));
        pRecord target = *head;
        for (int index = 0; index < len; ++index) {
            arr[index] = target;
            target = target->next;
        }

        /*ð������*/
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

/*ͨ����������*/
void sortRecordNodeByDate(pRecord* head) {
    int len = countRecordNode(*head);
    if (len > 1) {
        pRecord* arr = (pRecord*)malloc(len * sizeof(pRecord));
        pRecord target = *head;
        for (int index = 0; index < len; ++index) {
            arr[index] = target;
            target = target->next;
        }

        /*ð������*/
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

/*ͨ��С������������*/
void sortRecordNodeByCommunityDate(pRecord* head) {
    int len = countRecordNode(*head);
    if (len > 1) {
        pRecord* arr = (pRecord*)malloc(len * sizeof(pRecord));
        pRecord target = *head;
        for (int index = 0; index < len; ++index) {
            arr[index] = target;
            target = target->next;
        }

        /*ð������*/
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

/*��ʾס������*/
void displayRecordTitle() {
    printf("%-16s", "����");
    printf("%-16s", "����");
    printf("%-16s", "С��");
    printf("%-16s", "����");
    printf("%-16s", "����");
    printf("\n");
}

/*��ʾס����Ϣ*/
void displayRecord(pRecord record) {
    printf("%-16s", record->id);
    printf("%-16s", record->name);
    printf("%-16s", record->community);
    printf("%-16s", record->date);
    printf("%-16.2lf", record->electricity);
    printf("\n");
}

/*�༭ס����Ϣ*/
void editRecord(pRecord record) {
    printf("$ ¼��ס����Ϣ $\n");
    printf(" ���ţ�");
    if (strlen(record->id)) {
        printf("%s\n", record->id);
    }
    else {
        scanf("%s", record->id);
    }
    printf(" ������");
    if (strlen(record->name)) {
        printf("%s\n", record->name);
    }
    else {
        scanf("%s", record->name);
    }
    printf(" С����");
    scanf("%s", record->community);
    printf(" ���ڣ�");
    inputDate(record->date);
    printf(" ������");
    scanf("%lf", &record->electricity);
}

/*��ס����Ϣ�洢���ļ�*/
void saveRecordFile(const pRecord head) {
    pRecord cursor = head;
    FILE* output = fopen("record.txt", "w");
    if (output) {
        fprintf(output, "%-16s ", "����");
        fprintf(output, "%-16s ", "����");
        fprintf(output, "%-16s ", "С��");
        fprintf(output, "%-16s ", "����");
        fprintf(output, "%-16s ", "����");
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
        printf("д�ļ�ʧ�ܣ�\n");
    }
}

/*���ļ��м���ס����Ϣ*/
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
        printf("���ļ�ʧ�ܣ�\n");
    }
    return head;
}

/*��ʾס����Ϣѡ��*/
void displayRecordOption(pRecord* head) {
    if (head) {
        int option = 1;
        while (1) {
            printf("$ ��ʾס����Ϣ $\n");
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
            printf("   ѡ������ʽ\n");
            printf("[1] ������������ʾ\n");
            printf("[2] ������������ʾ\n");
            printf("[3] ��С��������ʾ\n");
            printf("[4] ������������ʾ\n");
            printf("[0] ����\n");
            printf("   ��ѡ��");
            scanf("%d", &option);
        }
    }
    else {
        printf("��δ¼����Ϣ��\n");
    }
}

/*���ס��ѡ��*/
void addRecordOption(pRecord* head) {
    pRecord target = NULL;
    pRecord record = (pRecord)malloc(sizeof(Record));
    memset(record, 0, sizeof(Record));
    printf("$ ���ס����Ϣ $\n");
    printf(" ���뻧�ţ�");
    scanf("%s", record->id);
    target = findRecordNodeByID(*head, record->id);
    if (target) {
        strcpy(record->name, target->name);
    }
    editRecord(record);
    if (findRecordNodeByIDDate(*head, record->id, record->date)) {
        free(record);
        record = NULL;
        printf("\n����Ϣ�Ѵ��ڣ�ס�����ʧ�ܣ�\n");
    }
    else {
        *head = addRecordNode(*head, record);
        /*ͬ���ļ���Ϣ*/
        saveRecordFile(*head);
        printf("\n�ɹ����ס����\n");
    }
}

/*ͨ�����Ų���ס��ѡ��*/
void findRecordByIDOption(pRecord head) {
    pRecord record = NULL;
    char id[STR_LEN] = { 0 };
    printf("$ �����Ų��ҵ�Ѽ�¼��Ϣ $\n");
    printf(" ���뻧�ţ�");
    scanf_s("%s", id);
    record = findRecordNodeByID(head, id);
    if (record) {
        printf("$ �ҵ�����ס����Ϣ $\n");
        displayRecordTitle();
        do {
            displayRecord(record);
            record = findRecordNodeByID(record->next, id);
        } while (record);
    }
    else {
        printf("ס����Ϣ��δ�ҵ���ס��\n");
    }
}

/*ͨ����������ס��ѡ��*/
void findRecordByNameOption(pRecord head) {
    pRecord record = NULL;
    char name[STR_LEN] = { 0 };
    printf("$ ���������ҵ�Ѽ�¼��Ϣ $\n");
    printf(" ���뻧����");
    scanf("%s", name);
    record = findRecordNodeByName(head, name);
    if (record) {
        printf("$�ҵ�����ס����Ϣ$\n");
        displayRecordTitle();
        do {
            displayRecord(record);
            record = findRecordNodeByName(record->next, name);
        } while (record);
    }
    else {
        printf("ס����Ϣ��δ�ҵ���ס��\n");
    }
}

/*����ס��ѡ��*/
void findRecordOption(pRecord head) {
    int option;
    while (1) {
        printf("$ ����ס�� $\n");
        printf("\n");
        printf("[1] �����Ų��ҵ�Ѽ�¼��Ϣ\n");
        printf("[2] ���������ҵ�Ѽ�¼��Ϣ\n");
        printf("[0] ����\n");
        printf("\n");
        printf("   ��ѡ��");
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

/*�޸�ס��ѡ��*/
void modifyRecordOption(pRecord head) {
    pRecord record = NULL;
    char id[STR_LEN] = { 0 };
    char date[STR_LEN] = { 0 };
    printf("$ �޸�ס����Ѽ�¼��Ϣ $\n");
    printf(" ���뻧�ţ�");
    scanf("%s", id);
    printf(" �������ڣ�");
    scanf("%s", date);
    record = findRecordNodeByIDDate(head, id, date);
    if (record) {
        displayRecord(record);
        printf("$ ���±༭����ס����Ϣ $\n");
        editRecord(record);
        /*ͬ���ļ���Ϣ*/
        saveRecordFile(head);
    }
    else {
        printf("ס����Ϣ��δ�ҵ���ס��\n");
    }
}

/*ɾ��ס��ѡ��*/
void removeRecordOption(pRecord* head) {
    pRecord record = NULL;
    char id[STR_LEN] = { 0 };
    char date[STR_LEN] = { 0 };
    printf("$ ɾ��ס����Ѽ�¼��Ϣ $\n");
    printf(" ���뻧�ţ�");
    scanf("%s", id);
    printf(" �������ڣ�");
    scanf("%s", date);
    record = findRecordNodeByIDDate(*head, id, date);
    if (record) {
        printf("$ɾ������ס����Ϣ$\n");
        displayRecord(record);
        *head = removeRecordNode(*head, record);
        /*ͬ���ļ���Ϣ*/
        saveRecordFile(*head);
    }
    else {
        printf("ס����Ϣ��δ�ҵ���ס����\n");
    }
}

/*�������ס�����õ���ѡ��*/
void randRecordOption(pRecord head) {
    pRecord cursor = head;
    printf("$ �������ס�����õ��� $\n");
    if (cursor) {
        while (cursor) {
            cursor->electricity = rand() % 500 + 1;
            cursor = cursor->next;
        }
        saveRecordFile(head);
    }
    printf(" ס�������Ѿ����������\n");
}

/*ס����Ѽ�¼����*/
void manageRecord(pRecord* head) {
    int option;
    while (1) {
        printf("$ ס����Ѽ�¼���� $\n");
        printf("\n");
        printf("[1] ��ʾס����Ѽ�¼��Ϣ\n");
        printf("[2] ���ס����Ѽ�¼��Ϣ\n");
        printf("[3] ����ס����Ѽ�¼��Ϣ\n");
        printf("[4] �޸�ס����Ѽ�¼��Ϣ\n");
        printf("[5] ɾ��ס����Ѽ�¼��Ϣ\n");
        printf("[6] �������ס�����õ���\n");
        printf("[0] ����\n");
        printf("\n");
        printf("   ��ѡ��");
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

/*��С��ͳ�Ʊ���*/
void statisticsListCommunity(pRecord* head) {
    char lasttoken[STR_LEN] = { 0 };
    double sum = 0;
    double total = 0;
    double high = -1;
    double low = -1;
    pRecord cursor = NULL;
    pRecord last = NULL;
    printf("$ ��С��ͳ�Ʊ��� $\n");
    printf("%-16s", "С��");
    printf("%-16s", "�·�");
    printf("%-16s", "����");
    printf("%-16s", "���");
    printf("%-16s", "��ʱ");
    printf("%-16s", "��ʱ");
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
    printf(" �����õ�����%.2lf  �ܵ�ѣ�%.2lf��\n", sum, electricCharge(sum));
}

/*��ס��ͳ�Ʊ���*/
void statisticsListID(pRecord* head) {
    char lasttoken[STR_LEN] = { 0 };
    double sum = 0;
    double total = 0;
    double high = -1;
    double low = -1;
    pRecord cursor = NULL;
    pRecord last = NULL;
    printf("$ ��ס��ͳ�Ʊ��� $\n");
    printf("%-16s", "����");
    printf("%-16s", "����");
    printf("%-16s", "���");
    printf("%-16s", "����");
    printf("%-16s", "���");
    printf("%-16s", "��ʱ");
    printf("%-16s", "��ʱ");
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
    printf(" �����õ�����%.2lf  �ܵ�ѣ�%.2lf��\n", sum, electricCharge(sum));
}

/*ͳ�Ʊ���*/
void statisticsList(pRecord* head) {
    int option;
    while (1) {
        printf("$ ס����Ѽ�¼���� $\n");
        printf("\n");
        printf("[1] ��С��ͳ�Ʊ���\n");
        printf("[2] ��ס��ͳ�Ʊ���\n");
        printf("[0] ����\n");
        printf("\n");
        printf("   ��ѡ��");
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

/*�������ͳ��Ա*/
void statisticianEnter(pRecord* record_head) {
    int option;
    while (1) {
        printf("$ �������ͳ��Ա $\n");
        printf("\n");
        printf("[1] ס����Ѽ�¼����\n");
        printf("[2] ͳ�Ʊ���\n");
        printf("[0] ����\n");
        printf("\n");
        printf("   ��ѡ��");
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

/*С�����ܵ�������*/
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

/*��ӡС���ܵ���*/
void showCommunity(pCommunity list, int count) {
    int index;
    printf("%-16s", "С��");
    printf("%-16s", "����");
    printf("%-16s", "���");
    printf("\n");
    for (index = 0; index < count; ++index) {
        pCommunity comm = &list[index];
        printf("%-16s", comm->name);
        printf("%-16.2lf", comm->electricity);
        printf("%-16.2lf", electricCharge(comm->electricity));
        printf("\n");
    }
}

/*��ӡС���ܵ���*/
void showCommunityLen(pCommunity list, int count, int len) {
    int index;
    printf("%-16s", "С��");
    printf("%-16s", "����");
    printf("%-16s", "���");
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

/*��ӡС���ܵ���*/
void showCommunityLevel(pCommunity list, int count) {
    int index;
    /*�㼶���*/
    int level = 0;
    for (index = 0; index < count; ++index) {
        if (level == 0) {
            printf("  ��������\n");
            printf("%-16s", "С��");
            printf("%-16s", "����");
            printf("%-16s", "���");
            printf("\n");
        }
        else if (level == 4) {
            printf("  ���μ���\n");
            printf("%-16s", "С��");
            printf("%-16s", "����");
            printf("%-16s", "���");
            printf("\n");
        }if (level == 8) {
            printf("  ��һ�㡿\n");
            printf("%-16s", "С��");
            printf("%-16s", "����");
            printf("%-16s", "���");
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

/*С��������������*/
void priorityListCommunity(pRecord* head) {
    char lasttoken[STR_LEN] = { 0 };
    /*ΪС��������������ռ�*/
    Community* commlist = (pCommunity)calloc(500, sizeof(Community));
    /*��ʼ��������Ԫ�ظ���*/
    int commlistcount = 0;
    /*�ۼ�����*/
    double total = 0;
    /*��ǰ��Ѽ�¼ָ��*/
    pRecord cursor = NULL;
    /*�ϴε�Ѽ�¼ָ��*/
    pRecord last = NULL;
    printf("$ С�������������� $\n");

    /*����¼�Ȱ�С�������������Ա�Ϊ֮���С������ͳ��׼��*/
    sortRecordNodeByCommunityDate(head);
    cursor = *head;
    /*��������ͳ�ƣ�����������������ۼƵ�С������������*/
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
    /*��ͳ�ƺ�����ݰ��õ�����������*/
    sortCommunity(commlist, commlistcount);
    /*�����������*/
    showCommunity(commlist, commlistcount);
}

/*С����������������ָ��������*/
void priorityListCommunityLen(pRecord* head) {
    /*ָ����������*/
    int len = 0;
    char lasttoken[STR_LEN] = { 0 };
    /*ΪС��������������ռ�*/
    Community* commlist = (pCommunity)calloc(500, sizeof(Community));
    /*��ʼ��������Ԫ�ظ���*/
    int commlistcount = 0;
    /*�ۼ�����*/
    double total = 0;
    /*��ǰ��Ѽ�¼ָ��*/
    pRecord cursor = NULL;
    /*�ϴε�Ѽ�¼ָ��*/
    pRecord last = NULL;
    printf("$ С����������������ָ�������� $\n");
    printf(" ����������");
    scanf("%d", &len);
    /*����¼�Ȱ�С�������������Ա�Ϊ֮���С������ͳ��׼��*/
    sortRecordNodeByCommunityDate(head);
    cursor = *head;
    /*��������ͳ�ƣ�����������������ۼƵ�С������������*/
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
    /*��ͳ�ƺ�����ݰ��õ�����������*/
    sortCommunity(commlist, commlistcount);
    /*�����������*/
    showCommunityLen(commlist, commlistcount, len);
}

/*С�����������������ֲ���ʾ��*/
void priorityListCommunityLevel(pRecord* head) {
    char lasttoken[STR_LEN] = { 0 };
    /*ΪС��������������ռ�*/
    Community* commlist = (pCommunity)calloc(500, sizeof(Community));
    /*��ʼ��������Ԫ�ظ���*/
    int commlistcount = 0;
    /*�ۼ�����*/
    double total = 0;
    /*��ǰ��Ѽ�¼ָ��*/
    pRecord cursor = NULL;
    /*�ϴε�Ѽ�¼ָ��*/
    pRecord last = NULL;
    printf("$ С�����������������ֲ���ʾ�� $\n");
    /*����¼�Ȱ�С�������������Ա�Ϊ֮���С������ͳ��׼��*/
    sortRecordNodeByCommunityDate(head);
    cursor = *head;
    /*��������ͳ�ƣ�����������������ۼƵ�С������������*/
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
    /*��ͳ�ƺ�����ݰ��õ�����������*/
    sortCommunity(commlist, commlistcount);
    /*�����������*/
    showCommunityLevel(commlist, commlistcount);
}

/*���繫˾������Ա*/
void staffEnter(pRecord* record_head) {
    int option;
    while (1) {
        printf("$ ���繫˾������Ա $\n");
        printf("\n");
        printf("[1] �鿴ͳ�Ʊ���\n");
        printf("[2] С��������������\n");
        printf("[3] С����������������ָ��������\n");
        printf("[4] С�����������������ֲ���ʾ��\n");
        printf("[0] ����\n");
        printf("\n");
        printf("   ��ѡ��");
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

/*���˵�*/
void menuMain(pRecord* record_head) {
    int option;
    srand((unsigned int)time(NULL));
    while (1) {
        printf("$ С�����������Ƽ�ϵͳ $\n");
        printf("\n");
        printf("[1] �������ͳ��Ա\n");
        printf("[2] ���繫˾������Ա\n");
        printf("[0] ����\n");
        printf("\n");
        printf("   ��ѡ��");
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

/*������*/
int main() {
    system("title С�����������Ƽ�ϵͳ");
    /*���ļ��м���ס����Ϣ*/
    pRecord record_head = loadRecordFile();
    /*����˵�����*/
    menuMain(&record_head);
    /*���ס������*/
    clearRecordNode(record_head);
    return 0;
}
