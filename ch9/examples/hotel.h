/* hotel.h  -- константы и объявления для программы hotel.c */
#define QUIT 5
#define HOTEL1 180.0
#define HOTEL2 225.0
#define HOTEL3 255.0
#define HOTEL4 355.0
#define DISCOUNT 0.95
#define STARS "***************************************"

/* отображение списка возможных вариантов отелей */
int menu (void);

/* возвращает количество суток бронирования */
int getnights (void);

/* вычисляет стоимость в зависимости от расценок и количества суток */
void showprice (double rate, int nights);