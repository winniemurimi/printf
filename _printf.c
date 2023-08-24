#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */

int _printf(const char *format, ...)
{
	int count;
	va_list arguments;

	if (format == NULL)
	{
		return -1;
	}

	va_start(arguments, format);

	while (*format)
	{
		if (*format != '%')
		{
			write (1, format, 1);
			chara_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write (1, format, 1);
				chara_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_of_args, int);
				write (1, &c, 1);
				chara_print++;

			}
			else if (*format == '$')
			{
				char *str = va_arg(list_of_args, char*);
				int str_len = 0;

				while (str[str_len] != '\0' )
					str_len++;

				write (1, str, str_len);
				chara_print += str_len;
			}

			format++;
	}

	va_end(list_of_args);

	return chara_print;
}

int main(){

	_printf("Leo\n")
	_printf("%c\n", 'v');
	_printf("%s\n", "String");
	_printf("%%\n");
	return 0;

}
