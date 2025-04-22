/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:35:04 by mpoplow           #+#    #+#             */
/*   Updated: 2025/04/21 20:19:10 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**/
////	basic functions (no malloc used)
/**/
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_iswhtspc(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int find);
char	*ft_strrchr(const char *str, int find);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *str, int find, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *str, const char *substr, size_t len);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**/
////	file descriptor specific functions
/**/
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/**/
////	memory/malloc functions
/**/
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *str, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *src);
char	**ft_strstrdup(const char **src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *s1, char const *s2);

/**/
////	ft_printf
/**/
int		ft_printf(const char *str, ...);
int		cfound(char f, int *wrc);
int		sfound(char *f, int *wrc);
int		difound(int f, int *wrc);
int		ufound(unsigned int f, int *wrc);
int		lowxfound(int f, int *wrc);
int		capxfound(int f, int *wrc);
int		pfound(void *f, int *wrc);
int		percfound(int *wrc);

/**/
////	get_next_line;
/**/
char	*get_next_line(int fd);
size_t	nlstrlen(const char *s);
char	*buff_strjoin(char *endstr, char *stat);
int		move(char statarr[]);
int		nlcheck(char *str, char *statarr);
int		setstat(int fd, char *statarr);
char	*readerror(int x, char *endstr);
char	*ft_text_strjoin(char *endstr, char *stat);
char	*text_readerror(char *endstr);
char	*get_next_text(int fd);

#endif