#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<string.h>]
#define quantity 2
struct Train {
    int rideNumber;
    char arrivalTime[6];
    char departureTime[6];
    char direction[10];
    float distance;
    float averageSpeed;
};
int definitionTime(char* time) {
    int hours, minutes;
    scanf_s(time, "%d:%d", &hours, &minutes);
    int retime = hours * 60 + minutes;
    return retime;
}

void recordRide(struct Train* train) {

    printf("������� ����� ������: ");
    scanf_s("%d", &train->rideNumber);

    printf("������� ����� �������: ");
    scanf("%s", train->departureTime);

    printf("������� ����� ��������: ");
    scanf("%s", train->arrivalTime);

    printf("������� �����������: ");
    scanf("%s", train->direction);

    printf("������� ����������(� ��): ");
    scanf_s("%f", &train->distance);

    float distance = train->distance * 1000;
    int arrivalTime = definitionTime(train->arrivalTime);
    printf("%d\n", arrivalTime);
    int departureTime = definitionTime(train->departureTime);
    printf("%d\n", departureTime);
    int timeTrail = arrivalTime - departureTime;
    printf("���������� - %f\n", distance);
    printf("����� - %d\n", timeTrail);
    
}

void printTrain(struct Train* train) {
    printf("����� ������: %d", train->rideNumber);
    printf("����� ��������: %s", train->arrivalTime);
    printf("����� �������: %s", train->departureTime);
    printf("����������� ��������: %s", train->direction);
    printf("����������: %f", train->distance);
}

void main() {
    setlocale(LC_ALL, "Rus");
    struct Train train[quantity];

    for (int i = 0; i < quantity; i++) {
        printf("��������� ���������� � ������ %d.\n", i + 1);
        recordRide(&train[i]);
        printf("������� �������� ������ %d ����� %f �/�.\n", i + 1, train->averageSpeed);
    }
}