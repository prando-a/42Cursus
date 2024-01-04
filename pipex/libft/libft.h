/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prando-a <prando-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:19:02 by prando-a          #+#    #+#             */
/*   Updated: 2024/01/03 17:26:47 by prando-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4242
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"

// ENABLE ONLY IF WILLING TO USE LINKED LISTS
// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;

typedef struct quesiquierebolsa
{
	int		i;
	int		j;
	int		k;
}			t_indexes;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, int len);
void	ft_bzero(void *s, int n);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_memmove(void *dst, const void *src, int len);
int		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlcat(char *dst, const char *src, unsigned int dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	*ft_memchr(const void *s, int c, unsigned int n);
int		ft_memcmp(const void *s1, const void *s2, unsigned int n);
char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2); //Please use GNL ver.
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
// t_list	*ft_lstnew(void *content);
// void	ft_lstadd_front(t_list **lst, t_list *new);
// int		ft_lstsize(t_list *lst);
// t_list	*ft_lstlast(t_list *lst);
// void	ft_lstadd_back(t_list **lst, t_list *new);
// void	ft_lstdelone(t_list *lst, void (*del)(void *));
// void	ft_lstclear(t_list **lst, void (*del)(void *));
// void	ft_lstiter(t_list *lst, void (*f)(void *));
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*get_next_line(int fd); //Bonus version
char	*gnl_strjoin(char *s1, char *s2, int mode, int init); //ft_strjoin v3.0
void	ft_memdel(void **ap); //Use ft_strdel for string arrays
char	*ft_strnew(size_t size); //For archive purpose. Use ft_calloc()
void	ft_strdel(char **as);
void	ft_strclr(char *s); //Just use free() for Crom's sake!
void	ft_striter(char *s, void (*f)(char*));
char	*ft_strmap(char const *s, char (*f)(char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_msg(char *str); // ft_putendl_fd but fd is always 1
void	ft_err_msg(char	*str); // ft_putendl_fd but fd is always 2
int		ft_fndchr(char *str, char c);
int		ft_linecounter(char *str);
int		ft_chrcnt(char *str, char c);
int		ft_str_islf(char *str);
void	*ft_realloc(void *ptr, size_t new_size);
int		ft_arrnum(char **array);
int		ft_arrlen(char **array);
int		ft_arr_islf(char **array);
char	*ft_merge(char **array, char c, int len);
ssize_t	ft_atoll(const char *str);
char	**ft_arrjoin(char **a1, char **a2, int mode);
char	**ft_arrdup(char **array);
int		ft_putmatrix(char **arr);
char	*ft_file_to_str(int fd);
char	**ft_file_to_arr(int fd);
int		ft_putfd(int fd);
char	*ft_ftoa(float n);
char	*ft_chrdel(char *str, char c, int del);
void	ft_tridel(char ***tri);
int		ft_put_triarr(char ***tri);

#endif