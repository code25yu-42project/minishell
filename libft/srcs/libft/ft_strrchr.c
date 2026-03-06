char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if ((char) c == 0)
		return ((char *) str + i);
	while (i >= 0)
	{
		if (str[i] == (char) c)
			return ((char *) str + i);
		i--;
	}
	return (0);
}
