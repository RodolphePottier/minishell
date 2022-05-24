/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:02:21 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 10:06:50 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_command_is_ok(char *command_line)
{
	if (primary_checker(command_line) == TRUE
		&& check_all_pipe_sequence(command_line) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	give_next_character(char *str, int start, char c)
{
	while (str[start])
	{
		if (str[start] == c)
			return (start);
		start++;
	}
	if (!str[start])
		return (-1);
	return (start);
}

int	check_error(t_checker *check, char *str)
{
	check->error = TRUE;
	check->str = str;
	return (0);
}

void	init_struct_checker(t_checker *check)
{
	check->arg_of_redirect = FALSE;
	check->error = FALSE;
	check->index = 0;
	check->str = NULL;
	check->par_lvl = 0;
}

int	primary_checker(char *commande)
{
	t_checker	check;

	if (ft_strlen(commande) == 0)
		return (FALSE);
	init_struct_checker(&check);
	if (quote_parenthise_checker(commande, &check))
	{
		check.index = 0;
		and_or_pipe_checker(commande, &check);
	}
	if (check.error == TRUE)
	{
		printf("%s\n", check.str);
		g_exit_status = 2;
	}
	return (!check.error);
}
