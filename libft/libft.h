/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:46:27 by yewen             #+#    #+#             */
/*   Updated: 2017/08/18 23:39:09 by yewen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdarg.h>
# include "ft_list.h"
# include "get_next_line.h"
# include "lst.h"
# include "rb.h"
# include "ft_array.h"
# define FT_MIN(a, b)	(((a) < (b)) ? (a) : (b))
# define FT_MAX(a, b)	(((a) > (b)) ? (a) : (b))
# define FT_ABS(x)		(((x) < 0) ? -(x) : (x))
# define FT_TODIGIT(c)	((c) - '0')
# define FT_ISDIGIT(c)	((unsigned)FT_TODIGIT(c) <= 9)
# define FT_TOCHAR(n)	((n) + '0')
# define FT_ISSPACE(c)	(((c) >= 0x09 && (c) <= 0x0d) || (c) == 0x20)

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strncat(char *dst, const char *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s, const char *find);
char	*ft_strnstr(const char *s, const char *find, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);
int		ft_asprintf(char **strp, const char *fmt, ...);
int		ft_vdprintf(int fd, const char *fmt, va_list ap);
int		ft_vasprintf(char **strp, const char *fmt, va_list ap);

char	*ft_strndup(const char *s, size_t n);
size_t	ft_strnlen(const char *s, size_t maxlen);
void	ft_strsplit_free(char **tab);
char	*ft_strrev(char *str);
void	ft_qsort(void *base, size_t n, size_t width,
		int (*cmp)(const void *, const void *));
size_t	ft_wcslen(const wchar_t *s);
int		ft_isint(char *str);
int		ft_count_chars(char *str, char c);
void	*try(size_t size);
void	ft_del(void *ptr, size_t size);
void	ft_pushback(void **data, size_t size, int count, void *o);
char	*ft_trim(char **s);
void	ft_deltab(char **tab);
t_list	*ft_lstend(t_list *ls);
size_t	ft_lstsize(t_list *root);
void	ft_lstadd_end(t_list **alst, t_list *new);
char	*ft_strjoinfree(char const *s1, char const *s2, int mask);
void	ft_endian(void *p, int size);

#endif
