int	ft_toupper(int c)
{
	if (c < 'a' || c > 'z')
		return (c);
	else
		return (c + 'A' - 'a');
}
