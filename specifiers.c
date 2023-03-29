#include "main.h"

/**
 * get_specifier - Calls a specifier function to print specified identifier
 * @s: pointer to string
 * Return: Returns afunction pointer
 */
int (*get_specifier(char *s))(va_list ap, ps_t *params)
{
	int i = 0;
	pf_t specs_array[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"k", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	while (i < 14 && *s != *(specs_array[i].str)
	       && specs_array[i].str != NULL)
		i++;
	return (specs_array[i].func);

}
