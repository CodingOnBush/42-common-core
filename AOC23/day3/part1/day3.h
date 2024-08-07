#ifndef DAY2_H
# define DAY2_H

# define LINE 140

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 100
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

char    *get_next_line(int fd);
char	*ft_create_str(t_node *lst);
char	*ft_get_after_nl(char *str);
int		ft_createlst(int fd, t_node **lst);
int		ft_get_len(t_node *lst);
void	ft_update_lst(t_node **lst);
void	ft_freelst(t_node **lst);
void	ft_lstappend(t_node **lst, char *buff);
int		ft_lstchr(t_node *lst);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s, int len);

void	ft_fill_map(char **map);
int		ft_atoi(char **map, int i, int j);
int		ft_isdigit(int c);
int		ft_is_symbol(char c);
int		ft_get_nb_len(int nb);

int		ft_check_around(char **map, int i, int j);
int		ft_check_down_left(char **map, int i, int j);
int		ft_check_down_right(char **map, int i, int j);
int		ft_check_down(char **map, int i, int j);
int		ft_check_left(char **map, int i, int j);
int		ft_check_right(char **map, int i, int j);
int		ft_check_up_left(char **map, int i, int j);
int		ft_check_up_right(char **map, int i, int j);
int		ft_check_up(char **map, int i, int j);

#endif