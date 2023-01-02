#include "push_swap.h"

size_t	ft_strlen(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	len;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	len = 0;
	if (!dstsize)
		return (srclen);
	while (src[len] && (dstlen + len) < (dstsize - 1))
	{
		dst[dstlen + len] = src[len];
		len++;
	}
	dst[dstlen + len] = '\0';
	if (dstlen > dstsize)
		return (srclen + dstsize);
	return (srclen + dstlen);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	len;

	srcsize = ft_strlen(src);
	len = 0;
	if (dstsize != 0)
	{
		while (src[len] && len < (dstsize - 1))
		{
			dst[len] = src[len];
			len++;
		}
        dst[len] = ' ';
		dst[len + 1] = '\0';
	}
	return (srcsize);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*ptr;
	int		x;

	len = ft_strlen(s);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	x = 0;
	while (s[x])
	{
		ptr[x] = s[x];
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;

	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 2);
	ft_strlcat(ptr, s2, ft_strlen(s1) + ft_strlen(s2) + 2);
	free(s1);
	return (ptr);
}

