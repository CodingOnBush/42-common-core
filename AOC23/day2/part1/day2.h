#ifndef DAY2_H
# define DAY2_H

# define RED 12
# define GREEN 13
# define BLUE 14

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}					t_node;

typedef struct s_set
{
	int	red;
	int	green;
	int	blue;
}		t_set;

// int	ft_atoi(const char *str);
char	*ft_create_str(t_node *lst);
char	*ft_get_after_nl(char *str);
int		ft_get_len(t_node *lst);
void	ft_lstappend(t_node **lst, char *buff);
int		ft_lstchr(t_node *lst);
t_node	*ft_lstnew(char *buff, int size);
char	*ft_strcat(char *dst, char *src);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s, int len);
int		ft_strlen(char *str);
void	ft_update_lst(t_node **lst);
char    *get_next_line(int fd);
int		ft_createlst(int fd, t_node **lst);
void	ft_freelst(t_node **lst);

int	ft_isdigit(int c);

int 	ft_isalpha(int c);
int		ft_strcmp(const char *s1, const char *s2);
char	ft_get_next_color(char **str);
int		ft_get_next_nb(char **str);
void	ft_update_set(t_set *set, char color, int nb);
int		ft_is_valid_set(t_set *set);
int	ft_is_game_valid(char *line);

#endif