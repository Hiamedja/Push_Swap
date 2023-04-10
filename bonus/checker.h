/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiamedja <hiamedja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:00:39 by hiamedja          #+#    #+#             */
/*   Updated: 2023/04/10 15:14:06 by hiamedja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7

# endif

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/_types.h>
# include <unistd.h>

typedef struct s_stack_a
{
	int					count;
	struct s_stack_a	*next;
	int					index;
}						t_stack_a;

typedef struct s_list
{
	int					i;
	int					j;
	int					x;
	int					count;
	char				**str;
}						t_list;

char					*get_next_line(int fd);
char					*ft_strchr(const char *s, int c);
char					*ft_strjoin(char *s1, char *s2);
t_stack_a				*ft_newstack(int content);
int						ft_nbcmp(const char *s1, const char *s2);
int						ft_is_zero(char *av);
void					ft_freestack(t_stack_a **stack);
void					ft_sort(t_stack_a **stack_a, t_stack_a **stack_b,
							int *tab);
void					ft_sort3(t_stack_a **stack);
void					ft_sa(t_stack_a **a);
char					**filling_stack(int ac, char **av);
int						ft_check_double(t_stack_a *stack_a);
void					ft_sb(t_stack_a **b);
void					ft_ss(t_stack_a **a, t_stack_a **b);
char					**ft_split(char const *s, char c);
void					ft_lstadd_back(t_stack_a **lst, t_stack_a *new);
long long				ft_atoi(const char *str);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
int						check_sort(t_stack_a *stack);
int						ft_check_param(char **av);
void					ft_error(void);
int						ft_checksort(t_stack_a *stack);
int						ft_stack_size(t_stack_a *stack);
void					ft_sort2(t_stack_a *stack);
void					ft_rotate_ab(t_stack_a **stack);
void					ft_ra(t_stack_a **a);
void					ft_rb(t_stack_a **b);
void					ft_rr(t_stack_a **a, t_stack_a **b);
void					ft_rrotate_ab(t_stack_a **stack);
void					ft_rra(t_stack_a **a);
void					ft_rrb(t_stack_a **b);
void					ft_rrr(t_stack_a **a, t_stack_a **b);
void					ft_sort_middle(t_stack_a **stack_a,
							t_stack_a **stack_b);
void					sortlow_pa(t_stack_a **stack_a, t_stack_a **stack_b,
							int i);
int						ft_post_a(t_stack_a *stack, int count);
int						find_low_numb(t_stack_a *s);
void					ft_pa(t_stack_a **a, t_stack_a **b);
void					ft_pb(t_stack_a **a, t_stack_a **b);
void					ft_sort4_5(t_stack_a **stack_a, t_stack_a **stack_b);
int						ft_position(t_stack_a *stack_a, int index);
size_t					ft_strlen1(const char *str);
char					*ft_strchr(const char *s, int c);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_save(char *str_sttc);
char					*ft_get_line(char *str_sttc);
char					*ft_read_join(char *str, int fd);
size_t					ft_strlen(const char *str);
void					ft_checker(t_stack_a **stack_a, t_stack_a **stack_b);
int						ft_isnum(char *av);
int						ft_stack_size(t_stack_a *stack);
int						ft_check_double(t_stack_a *stack_a);
t_stack_a				*ft_newstack(int content);
int						ft_checksort(t_stack_a *stack);

#endif