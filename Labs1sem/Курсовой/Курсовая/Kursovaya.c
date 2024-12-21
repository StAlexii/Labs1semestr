#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_MICE 100

typedef struct {
    char manufacturer[50];
    bool isGaming;
    char connectionType[1];
    int hasLighting;
    char interface[20];
    int silentButtons;
    int buttonCount;
    char color[20];
    char type[20];
    char sensorType[20];
    int maxDPI;
} mouse_t;

int addMouse(mouse_t mice[], int* count) {

    printf("������� �������������: ");
    scanf("%s", mice[*count].manufacturer);

    printf("�������? (1 - ��, 0 - ���): ");
    scanf("%d", &mice[*count].isGaming);

    printf("������� ��� �����������: (1 - ���������, 2 - ������������): ");
    scanf("%s", mice[*count].connectionType);

    printf("������� ���������: (1 - ��, 0 - ���): ");
    scanf("%d", &mice[*count].hasLighting);

    printf("������� ��������� �����������: ");
    scanf("%s", mice[*count].interface);

    printf("��������� ������: (1 - ��, 0 - ���): ");
    scanf("%d", &mice[*count].silentButtons);

    printf("����� ���������� ������: ");
    scanf("%d", &mice[*count].buttonCount);

    printf("����: ");
    scanf("%s", mice[*count].color);

    printf("��� ����: ");
    scanf("%s", mice[*count].type);

    printf("��� �������: ");
    scanf("%s", mice[*count].sensorType);

    printf("������������ ���������� ������� (dpi): ");
    scanf("%d", &mice[*count].maxDPI);

    (*count)++;
    
    return 1;
}

int searchMouse(const mouse_t mice[], int count, mouse_t results[], char* color, char* interface, int searchOption) {
    int resultCount = 0;

    for (int i = 0; i < count; i++) {
        int mcolor = (searchOption == 1 || searchOption == 3) && strcmp(mice[i].color, color) == 0;
        int minterface = (searchOption == 2 || searchOption == 3) && strcmp(mice[i].interface, interface) == 0;

        if (searchOption == 1 && mcolor)
            results[resultCount++] = mice[i]; // ���������� ��������� �� ������
        else if (searchOption == 2 && minterface)
            results[resultCount++] = mice[i];
        else if (searchOption == 3 && mcolor && minterface)
            results[resultCount++] = mice[i];
    }

    return resultCount;// ������� ���������� ��������� ������� ����� ���������
}


int saveToTextFile(mouse_t mice[], int count, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        return 2;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%d,%s,%d,%s,%d,%d,%s,%s,%d,%s\n",
            mice[i].manufacturer,
            (int*)&mice[i].isGaming,
            mice[i].connectionType,
            mice[i].hasLighting,
            mice[i].interface,
            mice[i].silentButtons,
            mice[i].buttonCount,
            mice[i].color,
            mice[i].type,
            mice[i].maxDPI,
            mice[i].sensorType);
    }
    fclose(file);
    return 1;
}

int loadFromTextFile(mouse_t mice[], int* count, const char* filename) {
    FILE* file = fopen(filename, "r");

    *count = 0;
    while 
        (fscanf(file, "%49[^,],%d,%19[^,],%d,%19[^,],%d,%d,%19[^,],%19[^,],%d,%19[^\n]\n",
        mice[*count].manufacturer,
        &mice[*count].isGaming,
        mice[*count].connectionType,
        &mice[*count].hasLighting,
        mice[*count].interface,
        &mice[*count].silentButtons,
        &mice[*count].buttonCount,
        mice[*count].color,
        mice[*count].type,
        &mice[*count].maxDPI,
        mice[*count].sensorType) == 11) {
        (*count)++;
        if (*count >= MAX_MICE) {
            return 2;
            break;
        }
    }

    fclose(file);
    return 1;
}

int bubbleSort(mouse_t* mice, int count, int criterion) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int swapNeeded = 0;

            if (criterion == 1) {
                // ���������� �� �������
                if (mice[j].isGaming < mice[j + 1].isGaming) {
                    swapNeeded = 1;
                }
            }
            else if (criterion == 2) {
                // ���������� �� ���� �����������
                if (mice[j].connectionType > mice[j + 1].connectionType) {
                    swapNeeded = 1;
                }
            }
            else if (criterion == 3) {
                // ���������� �� ����� ���������
                if (mice[j].isGaming < mice[j + 1].isGaming ||
                    (mice[j].isGaming == mice[j + 1].isGaming &&
                        mice[j].connectionType > mice[j + 1].connectionType)) {
                    swapNeeded = 1;
                }
            }

            // ����� ���������
            if (swapNeeded) {
                mouse_t temp = mice[j];
                mice[j] = mice[j + 1];
                mice[j + 1] = temp;
            }
        }
    }
    return 1;
}

int editMouse(mouse_t mice[], int count, const char* manufacturer) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(mice[i].manufacturer, manufacturer) == 0) {
            found = 1;
            printf("�������������� ������ ��� ������������� %s\n", manufacturer);

            int choice;
            do {
                printf("\n�������� ���� ��� ���������:\n");
                printf("1. ������� (1 - ��, 0 - ���)\n");
                printf("2. ��� ����������� (1 - ���������, 2 - ������������): \n");
                printf("3. ��������� (1 - ��, 0 - ���)\n");
                printf("4. ��������� �����������\n");
                printf("5. ��������� ������ (1 - ��, 0 - ���)\n");
                printf("6. ����� ���������� ������\n");
                printf("7. ����\n");
                printf("8. ��� ����\n");
                printf("9. ������������ ���������� ������� (dpi)\n");
                printf("10. ��� �������\n");
                printf("0. �����\n");
                printf("��� �����: ");
                scanf("%d", &choice);

                switch (choice) {
                case 1:
                    printf("�������? (1 - ��, 0 - ���): ");
                    scanf("%d", &mice[i].isGaming);
                    break;
                case 2:
                    printf("������� ����� ��� �����������: (1 - ���������, 2 - ������������) ");
                    scanf("%s", &mice[i].connectionType);
                    break;
                case 3:
                    printf("��������� (1 - ��, 0 - ���): ");
                    scanf("%d", &mice[i].hasLighting);
                    break;
                case 4:
                    printf("������� ����� ��������� �����������: ");
                    scanf("%s", mice[i].interface);
                    break;
                case 5:
                    printf("��������� ������ (1 - ��, 0 - ���): ");
                    scanf("%d", &mice[i].silentButtons);
                    break;
                case 6:
                    printf("������� ����� ����� ���������� ������: ");
                    scanf("%d", &mice[i].buttonCount);
                    break;
                case 7:
                    printf("������� ����� ����: ");
                    scanf("%s", mice[i].color);
                    break;
                case 8:
                    printf("������� ����� ��� ����: ");
                    scanf("%s", mice[i].type);
                    break;
                case 9:
                    printf("������� ����� ������������ ���������� ������� (dpi): ");
                    scanf("%d", &mice[i].maxDPI);
                    break;
                case 10:
                    printf("������� ����� ��� �������: ");
                    scanf("%s", mice[i].sensorType);
                    break;
                case 0:
                    printf("����� �� ������ ��������������.\n");
                    break;
                default:
                    printf("�������� �����. ���������� �����.\n");
                }

                if (choice != 0) {
                    return 1;
                }
            } while (choice != 0);

            return 0;
        }
    }
    if (!found) {
        printf("������ �� �������.\n");
    }
}

int deleteMouse(mouse_t mice[], int* count, const char* manufacturer) {
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(mice[i].manufacturer, manufacturer) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return 0;
    }
    // ����� ������� ��� �������� ������
    for (int i = index; i < *count - 1; i++) {
        mice[i] = mice[i + 1];
    }
    (*count)--;
    return 1;
}


int main() {
    setlocale(LC_ALL, "ru");
    system("color F0");
    mouse_t* mice = (mouse_t*)malloc(MAX_MICE * sizeof(mouse_t));
    int count = 0;
    int choice;
    char filename[] = "data_base.txt";
    int sortCr = 0;
    int cnt;

    do {
        printf("����:\n");
        printf("1. �������� ����� ������\n");
        printf("2. ����� ������ �� ����� ��� ���������� �����������\n");
        printf("3. ��������� ������ � ����\n");
        printf("4. ��������� ������ �� �����\n");
        printf("5. �������� ��� ������\n");
        printf("6. �������� ������ �� �������������\n");
        printf("7. ����������� ������\n");
        printf("8. �������� ������\n");
        printf("0. �����\n");
        printf("�������� �����: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            printf("������� ������� ��������?\n");
            scanf("%d", &cnt);
            for (int i = 0; i < cnt; i++) {
                printf("������ %d\n", i+1);
                int result1 = addMouse(mice, &count);
                if (result1 == 1)
                    printf("\n������ ���������.\n");
                else
                    printf("\n������ ���������� ������\n");
            }
            break;
        }
        case 2: {
            int searchOption;
            printf("�������� ������� ������:\n1. �� �����\n2. �� ���������� �����������\n3. �� ����� � ���������� �����������\n");
            scanf("%d", &searchOption);

            char color[20];
            char connectionType[20];

            if (searchOption == 1 || searchOption == 3) {
                printf("������� ����: ");
                scanf("%19s", color);
            }

            if (searchOption == 2 || searchOption == 3) {
                printf("������� ��������� �����������: ");
                scanf("%19s", connectionType);
            }
            mouse_t results[MAX_MICE];
            int foundCount = searchMouse(mice, count, results, color, connectionType, searchOption);

            if (foundCount > 0) {
                printf("������� %d �������:\n", foundCount);
                for (int i = 0; i < foundCount; i++) {
                    printf("�������������: %s, �������: %d, ��������� �����������: %s, ����: %s\n", results[i].manufacturer, results[i].isGaming, results[i].interface, results[i].color);
                }
            }
            else {
                printf("������ �� �������.\n");
            }

            break;
        }
        case 3: {
            int result3 = saveToTextFile(mice, count, filename);
            if (result3 == 1)
                printf("\n������ ������� ��������� � ��������� ����.\n");
            else if (result3 == 2)
                printf("������: ���������� ������� ���� ��� ������.\n");
            else
                printf("\n������ ���������� ������\n");
            break;
        }
        case 4: {
            int result4 = loadFromTextFile(mice, &count, filename);
            if (result4 == 1)
                printf("\n������ ������� ��������� �� ���������� �����.\n");
            else if (result4 == 2)
                printf("\n���������� ������������ ���������� �������.\n");
            else
                printf("\n������ ���������� ������\n");

            break;
        }
        case 5:
            for (int i = 0; i < count; i++) {
                printf("�������������: %s, �������: %s, ��� �����������: %s, ���������: %s, ���������: %s, ����� ������: %s, ���������� ������: %d, ����: %s, ��� ����: %s, ��� �������: %s, ���������� �������: %d dpi\n", mice[i].manufacturer, ((mice[i].isGaming == 1) ? "��" : "���"),
                    ((mice[i].connectionType[0] == '1') ? "���������" : "������������"), ((mice[i].hasLighting == 1) ? "�������" : "�����������"), mice[i].interface,
                    ((mice[i].silentButtons == 1) ? "��" : "���"), mice[i].buttonCount, mice[i].color, mice[i].type,
                    mice[i].sensorType, mice[i].maxDPI);
            }
            break;
        case 6: {
            char manufacturer[50];
            printf("������� ������������� ��� ��������������: ");
            scanf("%s", manufacturer);
            int result6 = editMouse(mice, count, manufacturer);
            if (result6 == 1)
                printf("���� ������� ���������.\n");
            else
                printf("\n������ ���������� ����\n");
            break;
        }
        case 7: {
            printf("�������� �������� ����������:\n1. ������� ��� ���\n2. ��� ����������� \n3. �� ����� ���������\n");
            scanf("%d", &sortCr);

            int result7 = bubbleSort(mice, count, sortCr);
            if (result7 == 1) {
                printf("������ ����� ����������:\n");
                for (int i = 0; i < count; i++) {
                    printf("�������������: %s, �������: %d, ��� �����������: %s, ����: %s\n", mice[i].manufacturer, mice[i].isGaming, (mice[i].connectionType[0] == '1') ? "���������" : "������������", mice[i].color);
                }
            }
            break;
        }
        case 8:
        {
            char manufacturer[50];
            printf("������� ������������� ��� ��������: ");
            scanf("%49s", manufacturer);

            int result = deleteMouse(mice, &count, manufacturer);

            if (result == 1) {
                printf("������ ������� �������.\n");
            }
            else {
                printf("������ � ��������� �������������� �� �������.\n");
            }

            break;
        }
        case 0:
            printf("����� �� ���������.\n");
            break;
        default:
            printf("�������� �����.\n");
        }
    } while (choice != 0);
}