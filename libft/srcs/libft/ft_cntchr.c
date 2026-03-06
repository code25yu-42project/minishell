int	ft_cntchr(const char *str, char chr)
{
	int	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		if (*str == chr)
			cnt++;
		str++;
	}
	return (cnt);
}
