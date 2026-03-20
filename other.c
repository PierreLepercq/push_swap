#include <stddef.h>
#include <limits.h>

t_stack	*new_stack_node(int id, int value, t_stack *prev)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->id = id;
	new->value = value;
	new->prev = prev;
	if (prev != NULL)
		prev->next = new;
	return (new);
}

int	check_atoi(const char *s)
{
	int		i;
	size_t	len;
	char	sign;

	i = 0;
	len = 0;
	sign = '+';
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-')
		sign = s[i++];
	while (s[i + len] != '\0')
	{
		if (s[i + len] < '0' && s[i] > '9')
			return (0);
		len++;
	}
	if (len > 10)
		return (0);
	if (len == 10 && sign == '+' && ft_strncmp(s + i, "2147483647", 10) > 0)
		return (0);
	if (len == 10 && sign == '-' && ft_strncmp(s + i, "2147483648", 10) > 0)
		return (0);
	return (1);
}
