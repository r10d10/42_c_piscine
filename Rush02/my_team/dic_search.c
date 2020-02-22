/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetrova <r11tsa@yahoo.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 21:29:21 by vpetrova          #+#    #+#             */
/*   Updated: 2020/02/22 22:17:58 by vpetrova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** WARRING
** Be careful of the type of the structure in the linked list!
** ...
** typedef struct					s_dic
** {
** 	char					*nb;
** 	char					*text;
** 	struct s_dic			*next;
** }							t_dic;
*/

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_print(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

/*
** This is a function that search through teh linked list for a particular
** string (number) and prints and return the words that corispond to it
** in case of not found it returns an NULL pointer.
*/

char		*dic_search(t_dic *current, char *numero)
{
	int			same;
	int			i;

	while (current != NULL)
	{
		same = 1;
		i = 0;
		while (current->nb[i] != '\0')
		{
			if (current->nb[i] != numero[i])
			{
				same = 0;
				break ;
			}
			i++;
		}
		if (same == 1)
		{
			ft_print(current->text);
			return (current->text);
		}
		current = current->next;
	}
	return (NULL);
}

/*
** int main()
** {
** 	t_dic a,b,c,d;
** 	t_dic *begin;
** 	begin= &a;
** 	a.nb = "100";
** 	a.text = "hundred";
** 	a.next = &b;
** 	b.nb = "2";
** 	b.text = "two";
** 	b.next = &c;
** 	c.nb = "33";
** 	c.text = "thirty-three";
** 	c.next = &d;
** 	d.nb = "1";
** 	d.text = "one";
** 	d.next = NULL;
** 	char *something =  dic_search(begin, "31");
** 	(void)something;
** }
*/
