/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** lib
*/

int 	my_strcmp(char *cmp, char *ind)
{
	int cmpl = -1;
	int indl = -1;
	int e = 0;

	if (!cmp || !ind)
		return (1);
	while (cmp[++cmpl] != '\0');
	while (ind[++indl] != '\0');
	if (cmpl != indl) {
		return (1);
	}
	while (cmp[e] == ind[e] && e < cmpl)
		e++;
	if (e != cmpl)
		return (1);
	return (0);
}