#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "holberton.h"
/**
 * print_int - Prints integer
 * @va_list: list of argments
 * Return: the value pointed by va_list
 */
void print_int(va_list list)
{
	int value; 
	int *ptr;

	value = (va_arg(list, int));
	ptr = &value;
	write(1, ptr, 1);
}
/**
 * print_char - Prints character
 * @va_list: list of argments
 * Return: the value pointed by va_list
 */ 
void print_char(va_list list)
{
	putchar((char)va_arg(list, int));
}
/**
 * print_string - Prints string
 * @va_list: list of argments
 * Return: the value pointed by va_list
 */ 
void print_string(va_list list)
{
	int i = 0;
	char *s;

	s = va_arg(list, char *);
	if (s != NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
			putchar(s[i]);
	}
}

/**
 * _printf - Prints arguments passed in the function
 * @format: First argument
 * Return: NOTHING
 */

int _printf(const char *format, ...)
{
	va_list content;
	unsigned int i = 0, j;

	datatype func[] = {
		{ "c", print_char},
		{ "d", print_int},
		{ "s", print_string},
		{NULL, NULL}
	};
	va_start(content, format);

	while (format && format[i])
	{
		if(format[i] == '%')
		{
			j = 0;
			while(j < 3)
			{
				if(*func[j].type == format[i + 1])
					func[j].action(content);
				j++;
			}
			if(format[i + 1] == '%')
			{
				write(1,&format[i + 1], 1);
			}
			i += 2;
			continue;
		}
		write(1,&format[i], 1);
		i++;
	}
	va_end(content);
	return (i);
	
}
