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
    float distance;
    float speed; 
};

int timeToMinutes(const char* time) {
    int hours, minutes;
    sscanf(time, "%d:%d", &hours, &minutes);
    return hours * 60 + minutes;
}

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
    scanf("%f", &flight->distance);

    int departureMinutes = timeToMinutes(flight->departureTime);
    int arrivalMinutes = timeToMinutes(flight->arrivalTime);
    int flightDuration = arrivalMinutes - departureMinutes;
    if (flightDuration > 0) {
        flight->speed = flight->distance / (flightDuration / 60.0); 
    }
    else {
        flight->speed = 0;
    }
}

void printFlight(const struct Flight* flight) {
    printf("Номер авиарейса: %d\n", flight->flightNumber);
    printf("Время вылета: %s\n", flight->departureTime);
    printf("Время прилета: %s\n", flight->arrivalTime);
    printf("Направление: %s\n", flight->destination);
    printf("Марка самолета: %s\n", flight->aircraftModel);
    printf("Расстояние: %.2f км\n", flight->distance);
    printf("Скорость: %.2f км/ч\n", flight->speed);
}

struct Flight findMaxSpeedFlight(struct Flight flights[], int count) {
    struct Flight maxSpeedFlight = flights[0];
    for (int i = 1; i < count; i++) {
        if (flights[i].speed > maxSpeedFlight.speed) {
            maxSpeedFlight = flights[i];
        }
    }
    return maxSpeedFlight;
}

int main() {
    setlocale(LC_ALL, "ru");
    system("color F0");
    struct Flight flights[numFlights];

    for (int i = 0; i < numFlights; i++) {
        printf("\nВведите данные для авиарейса %d:\n", i + 1);
        fillFlight(&flights[i]);
    }

    struct Flight maxSpeedFlight = findMaxSpeedFlight(flights, numFlights);

    printf("\nАвиарейс с максимальной скоростью:\n");
    printFlight(&maxSpeedFlight);

    return 0;
}
