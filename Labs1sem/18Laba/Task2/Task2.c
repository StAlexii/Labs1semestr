#include<stdio.h>
#include<locale.h>
#include<time.h>
#include <string.h>

void center(const char* message) {
	int length = strlen(message);
	int padding = (80 - length) / 2;
	for (int i = 0; i < padding; i++)
	{
		printf("*");
	}
	printf("%*s", length, message);
	for (int i = 0; i < padding; i++)
	{
		printf("*");
	}
	printf("\n");
}

void main(){

	system("color F0");
	setlocale(LC_ALL, "RUS");

	struct tm* mytime;
	time_t t;
	t = time(NULL);
	mytime = localtime(&t);
	for (int i = 0; i < 80; i++)
	{
		printf("*");
	}
	printf("\n");
	char array[200];
	sprintf(array, "Время в Москве %02d:%02d:%02d", mytime->tm_hour, mytime->tm_min, mytime->tm_sec);
	center(array);
	switch (mytime->tm_wday)
	{
	case 0:
	{
		sprintf(array, "Сегодня воскресенье");
		center(array);
		break;
	}
	case 1:
	{
		sprintf(array, "Сегодня понедельник");
		center(array);
		break;
	}
	case 2:
	{
		sprintf(array, "Сегодня вторник");
		center(array);
		break;
	}
	case 3:
	{
		sprintf(array, "Сегодня среда");
		center(array);
		break;
	}
	case 4:
	{
		sprintf(array, "Сегодня четверг");
		center(array);
		break;
	}
	case 5:
	{
		sprintf(array, "Сегодня пятница");
		center(array);
		break;
	}
	case 6:
	{
		sprintf(array, "Сегодня суббота");
		center(array);
		break;
	}
	}

	sprintf(array, "%d.%d.%d", mytime->tm_mday, mytime->tm_mon, mytime->tm_year - 100 + 2000);
	center(array);
	switch (mytime->tm_mon)
	{
	case 0:
	{
		printf("%d Января", mytime->tm_mday);
		break;
	}
	case 1:
	{
		sprintf(array, "%d Февраля", mytime->tm_mday);
		center(array);
		break;
	}
	case 2:
	{
		sprintf(array, "%d Марта", mytime->tm_mday);
		center(array);
		break;
	}
	case 3:
	{
		sprintf(array, "%d Апреля", mytime->tm_mday);
		center(array);
		break;
	}
	case 4:
	{
		sprintf(array, "%d Мая", mytime->tm_mday);
		center(array);
		break;
	}
	case 5:
	{
		sprintf(array, "%d Июня", mytime->tm_mday);
		center(array);
		break;
	}
	case 6:
	{
		sprintf(array, "%d Июля", mytime->tm_mday);
		center(array);
		break;
	}
	case 7:
	{
		sprintf(array, "%d Августа", mytime->tm_mday);
		center(array);
		break;
	}
	case 8:
	{
		sprintf(array, "%d Сентября", mytime->tm_mday);
		center(array);
		break;
	}
	case 9:
	{
		sprintf(array, "%d Октября", mytime->tm_mday);
		center(array);
		break;
	}
	case 10:
	{
		sprintf(array, "%d Ноября", mytime->tm_mday);
		center(array);
		break;
	}
	case 11:
	{
		sprintf(array, "%d Декабря", mytime->tm_mday);
		center(array);
		break;
	}

	}

	sprintf(array, "Сегодня %d день %d года", mytime->tm_yday, mytime->tm_year - 100 + 2000);
	center(array);
	sprintf(array, "До воскресенья осталось %d дней и %d часов", 6 - mytime->tm_wday, 23 - mytime->tm_hour);
	center(array);
	sprintf(array, "С первой пары прошло %d часов и %d минут", mytime->tm_hour - 9, mytime->tm_min - 30);
	center(array);
	sprintf(array, "До Нового года осталось %d месяцев и %d дней", 11 - mytime->tm_mon, 31 - mytime->tm_mday);
	center(array);
	sprintf(array, "До конца пары осталось %d минут и %d секунд", 90 - mytime->tm_min, 59 - mytime->tm_sec);                          //??
	center(array);
	sprintf(array, "До конца месяца %d дней, до конца года %d месяцев", 31 - mytime->tm_mday, 11 - mytime->tm_mon);
	center(array);

	switch (mytime->tm_mon)
	{
	case 0:
	{
		sprintf(array, "Месяц I, год - %d", mytime->tm_year + 1900);
		center(array);
		break;
	}
	case 1:
	{
		sprintf(array, "Месяц II, год - %d", mytime->tm_year + 1900);
		center(array);
		break;
	}
	case 2:
	{
		sprintf(array, "Месяц III, год - %d", mytime->tm_year + 1900);
		center(array);
		break;
	}
	case 3:
	{
		sprintf(array, "Месяц IV, год - %d", mytime->tm_year + 1900);
		center(array);
		break;
	}
	case 4:
	{
		sprintf(array, "Месяц V, год - %d", mytime->tm_year + 1900);
		center(array);
		break;
	}
	case 5:
	{
		sprintf(array, "Месяц VI, год - %d", mytime->tm_year + 1900);
		center(array);
		break;
	}
	case 6:
	{
		sprintf(array, "Месяц VII, год - %d", mytime->tm_year + 1900);
		center(array);
		break;
	}
	case 7:
	{
		sprintf(array, "Месяц VIII, год - %d", mytime->tm_year + 1900);
		center(array);
		break;
	}
	case 8:
	{
		sprintf(array, "Месяц IX, год - %d", mytime->tm_year + 1900);
		center(array);
		break;
	}
	case 9:
	{
		sprintf(array, "Месяц X, год - %d", mytime->tm_year + 1900);
		center(array);
		break;
	}
	case 10:
	{
		sprintf(array, "Месяц XI, год - %d", mytime->tm_year + 1900);
		center(array);
		break;
	}
	case 11:
	{
		sprintf(array, "Месяц XII, год - %d", mytime->tm_year + 1900);
		center(array);
		break;
	}

	}
	switch (mytime->tm_mon)
	{
	case 0:
	case 1:
	{
		sprintf(array, "Зима %d года", mytime->tm_year - 100);
		center(array);
		break;
	}
	case 2:
	case 3:
	case 4:
	{
		sprintf(array, "Весна %d года", mytime->tm_year - 100);
		center(array);
		break;
	}
	case 5:
	case 6:
	case 7:
	{
		sprintf(array, "Лето %d года", mytime->tm_year - 100);
		center(array);
		break;
	}
	case 8:
	case 9:
	case 10:
	{
		sprintf(array, "Осень %d года", mytime->tm_year - 100);
		center(array);
		break;
	}
	case 11:
	{
		sprintf(array, "Зима %d года", mytime->tm_year - 100);
		center(array);
		break;
	}
	}

	switch (mytime->tm_mon)
	{
	case 8:
	{
		sprintf(array, "Идет %d день осени", mytime->tm_mday);
		center(array);
		break;
	}
	case 9:
	{
		sprintf(array, "Идет %d день осени", mytime->tm_mday + 30);
		center(array);
		break;
	}
	case 10:
	{
		sprintf(array, "Идет %d день осени", mytime->tm_mday + 61);
		center(array);
		break;
	}
	case 11:
	{
		sprintf(array, "Идет %d день зимы", mytime->tm_mday);
		center(array);
		break;
	}
	}

	for (int i = 0; i < 80; i++)
	{
		printf("*");
	}




}