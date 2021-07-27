#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stddef.h>

int _printf(const char *format, ...);
void print_int(va_list list);
void print_char(va_list list);
void print_float(va_list list);
void print_string(va_list list);
/**
 * struct datatype - Structure for datatype
 * @type: Datatype of element to print
 * @func: Associated function
 */
typedef struct datatype
{
	char *type;
	void (*action)(va_list);
}datatype;
#endif
