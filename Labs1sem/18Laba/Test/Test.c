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

    printf("Введите номер поезда: ");
    scanf_s("%d", &train->rideNumber);

    printf("Введите время отбытия: ");
    scanf("%s", train->departureTime);

    printf("Введите время прибытия: ");
    scanf("%s", train->arrivalTime);

    printf("Введите направление: ");
    scanf("%s", train->direction);

    printf("Введите расстояние(в км): ");
    scanf_s("%f", &train->distance);

    float distance = train->distance * 1000;
    int arrivalTime = definitionTime(train->arrivalTime);
    printf("%d\n", arrivalTime);
    int departureTime = definitionTime(train->departureTime);
    printf("%d\n", departureTime);
    int timeTrail = arrivalTime - departureTime;
    printf("Расстояние - %f\n", distance);
    printf("Время - %d\n", timeTrail);
    
}

void printTrain(struct Train* train) {
    printf("Номер поезда: %d", train->rideNumber);
    printf("Время прибытия: %s", train->arrivalTime);
    printf("Время отбытия: %s", train->departureTime);
    printf("Направление движения: %s", train->direction);
    printf("Расстояние: %f", train->distance);
}

void main() {
    setlocale(LC_ALL, "Rus");
    struct Train train[quantity];

    for (int i = 0; i < quantity; i++) {
        printf("Заполните информацию о поезде %d.\n", i + 1);
        recordRide(&train[i]);
        printf("Средняя скорость поезда %d равна %f м/с.\n", i + 1, train->averageSpeed);
    }
}