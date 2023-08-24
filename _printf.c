#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{

	va_list args;
	va_start(args, format);
	int printed_chars = 0;

	while (*format != '\0')
	{
	if (*format == '%')
	{
		format++;
		if (*format == 'c')
		{
			int ch = va_arg(args, int);
			putchar(ch);
			printed_chars++;

		} else if (*format == 's')
		{
			char *str = va_arg(args, char *);

			while (*str != '\0')
			{
				putchar(*str);
				str++;
				printed_chars++;
			}
		} else if (*format == '%')
		{
			putchar('%');
			printed_chars++;
		}
	} else
	{
		putchar(*format);
		printed_chars++;
	}

	format++;
	}

	va_end(args);

	return (printed_chars);
}

int main(void) 
{
	_printf("Hello, %s! The character is %c and the percentage is %%.\n", "World", 'A');
	return 0;
}
