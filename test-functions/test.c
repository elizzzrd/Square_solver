#include <stdio.h>
#include <math.h>

int main(void)
{
    

    double c = 1e-12;
    printf("%lf", c);
    return 0;
}


//брать только первый вводимый символ
/* char get_first(void)
{
	int ch;
	ch = getchar();
	while (ch == ' ') // не сохраняем пробел
		ch = getchar();
	while (getchar() != '\n') //отбрасываем (не сохр) оставш символы до enter
		continue;
	return ch;
} */

/* int get_n(int n,char *buffer) {
	char ch;
	int i = 0;
	while (i < n && (ch = getchar()) != EOF)
		buffer[i++] = (char)ch;
	return i; // возращает значение реально прочитанных символов
} */

/* int get_int(void)
{
    int input;
    char ch;
    while (scanf_s("%ld", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" не является целым числом.\n");
        printf("Введите целое число: ");

    }
    return input;
} */


/*

int peek_next_char() {
    int c = getch();
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
} // если в буфере есть символы, то берем оттуда, нет - из станд ввода

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too much symbols\n");
    else
        buf[bufp++] = c;
}

int getint(int *pn)
{
    int c, sign;

    // Пропуск пробелов
    while (isspace(c = getch()))
        ;

    // Проверка на нечисловой символ
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    // Обработка знака
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int sign_char = c; // Сохраняем знак для возможного возврата
        c = getch();
        if (!isdigit(c)) {
            if (c != EOF) ungetch(c);
            ungetch(sign_char);
            return 0;
        }
    }

    // Сбор числа
    *pn = 0;
    while (isdigit(c)) {
        *pn = 10 * (*pn) + (c - '0');
        c = getch();
    }
    *pn *= sign;

    // Возврат последнего символа
    if (c != EOF) {
        ungetch(c);
    }

    return 1;
}

 */
