int	ft_isinstr(int c, char *str)
{
	while(*str)
	{
		if (c == *str)
		{
			return (1);
		}
		str++;
	}
	return (0);
}