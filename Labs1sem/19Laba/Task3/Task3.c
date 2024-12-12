#include <stdio.h>
#include <string.h>
#include <locale.h>
#define numFlights 2

struct Flight {
    int flightNumber;
    char departureTime[6];
    char arrivalTime[6];
    char destination[50];
    char aircraftModel[50];
    int distance;
};

void fillFlight(struct Flight* flight) {
    printf("Введите номер авиарейса: ");
    scanf("%d", &flight->flightNumber);

    printf("Введите время вылета (HH:MM): ");
    scanf("%s", flight->departureTime);

    printf("Введите время прилета (HH:MM): ");
    scanf("%s", flight->arrivalTime);

    printf("Введите направление: ");
    scanf("%s", flight->destination);

    printf("Введите марку самолета: ");
    scanf("%s", flight->aircraftModel);

    printf("Введите расстояние: ");
    scanf("%d", &flight->distance);

    int departureMinutes = timeToMinutes(flight->departureTime);
    int arrivalMinutes = timeToMinutes(flight->arrivalTime);
    int flightDuration = arrivalMinutes - departureMinutes;
}

int writefile(char* filename, struct Flight* fly, int size) {
    FILE* file = fopen("Flight.txt", "w");

    for (int i = 0; i < size; i++)
        fprintf(file, " Номер_рейса:%d; Время_вылета:%s; Время_прилета:%s; Направление:%s; Марка_самолета:%s; Расстояние:%d\n", 
              fly[i].flightNumber, fly[i].departureTime, fly[i].arrivalTime, 
              fly[i].destination, fly[i].aircraftModel, fly[i].distance);
    fclose(file);
    return 1;
}

int main() {
    setlocale(LC_ALL, "ru");
    system("color F0");
    struct Flight flights[numFlights];
    char filename = "Flight.txt";

    for (int i = 0; i < numFlights; i++) {
        printf("\nВведите данные для авиарейса %d:\n", i + 1);
        fillFlight(&flights[i]);
    }
    writefile(filename, flights, 2);
}