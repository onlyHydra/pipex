/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:17:22 by schiper           #+#    #+#             */
/*   Updated: 2025/02/04 02:01:55 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define QUOTE_SINGLE '\''
# define QUOTE_DOUBLE '"'
# define BRACE_OPEN '{'
# define BRACE_CLOSE '}'

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *nptr);
void				ft_bzero(void *s, unsigned long n);
void				*ft_calloc(unsigned long nmemb, unsigned long size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, unsigned long n);
int					ft_memcmp(const void *s1, const void *s2, unsigned long n);
void				*ft_memcpy(void *dest, const void *src, unsigned long n);
void				*ft_memmove(void *dest, const void *src, unsigned long n);
void				*ft_memset(void *s, int c, unsigned long n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s);
unsigned long		ft_strlcat(char *dst, const char *src, unsigned long size);
unsigned long		ft_strlcpy(char *dst, const char *src, unsigned long n);
int					ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, unsigned long n);
char				*ft_strnstr(const char *big, const char *little,
						unsigned long len);
char				*ft_strrchr(const char *s, int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
char				**ft_split_strtok(const char *str);
char				*ft_strtok(char *str, const char *delim);
size_t				ft_strspn(const char *str, const char *delim);
char				*ft_strpbrk(const char *str, const char *delim);
char				*ft_strncpy(char *dest, const char *src, size_t n);
#endif
