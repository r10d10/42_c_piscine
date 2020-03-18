#ifndef __SOLVER_H__
#define __SOLVER_H__

typedef struct      s_to_print{
    const char          *word;
    struct s_to_print   *next;
       
}           t_to_print;

struct s_to_print *begin;

void	ft_putchar(char c);

int		ft_putstr(const char *str);

int		solutlen(int row, int col);

int		ft_print_3d(char *number3d);

int		ft_print_all(char *number_all, int i, int all);

int solve(const char *path, char *number);

#endif
