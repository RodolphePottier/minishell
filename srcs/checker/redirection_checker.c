/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:35:16 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/15 12:44:48 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_out_checker(char *commande, t_checker *check)
{
	check->index++;
	if (commande[check->index] && commande[check->index] == '>')
	{
		check->index++;
		if (commande[check->index] == '>')
		{
			check->str = S_ERROR_MIS_ARG_REDIRECT_OUT;
			check->error = TRUE;
		}
	}
	while (commande[check->index] && ft_iswhitespace(commande[check->index])
		&& check->error == FALSE)
		check->index++;
	if (commande[check->index] && commande[check->index] != '>'
		&& commande[check->index] != '<' && commande[check->index] != '|')
		check->arg_of_redirect = TRUE;
	if (check->arg_of_redirect == FALSE)
	{
		check->str = S_ERROR_MIS_ARG_REDIRECT_OUT;
		check->error = TRUE;
	}
}

void	redirect_in_checker(char *commande, t_checker *check)
{
	check->index++;
	if (commande[check->index] && commande[check->index] == '<')
	{
		check->index++;
		if (commande[check->index] == '<')
		{
			check->str = S_ERROR_UNEX_TOK_REDIRECT_IN;
			check->error = TRUE;
		}
	}
	while (commande[check->index] && ft_iswhitespace(commande[check->index])
		&& check->error == FALSE)
		check->index++;
	if (commande[check->index] && commande[check->index] != '>'
		&& commande[check->index] != '<' && commande[check->index] != '|')
		check->arg_of_redirect = TRUE;
	if (check->arg_of_redirect == FALSE)
	{
		check->str = S_ERROR_MIS_ARG_REDIRECT_IN;
		check->error = TRUE;
	}
}

void	pipe_content_checker(char *commande, t_checker *check)
{
	int	i;
	int	len;

	check->index++;
	i = check->index;
	len = 0;
	while (commande[i] && commande[i] != '|')
	{
		if (!ft_iswhitespace(commande[i]))
			len++;
		i++;
	}
	if (len == 0)
	{
		check->str = S_ERROR_MIS_CMD_PIPE;
		check->error = TRUE;
	}
}

void	first_len_pipe_content(char *commande, t_checker *check)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (commande[i] && commande[i] != '|')
	{
		if (!ft_iswhitespace(commande[i]))
			len++;
		i++;
	}
	if (len == 0)
	{
		check->str = S_ERROR_MIS_CMD_PIPE;
		check->error = TRUE;
	}
}

int	redirection_checker(char *pipe_sequence, t_checker *check)
{
	first_len_pipe_content(pipe_sequence, check);
	while (check->index != -1 && pipe_sequence[check->index])
	{
		check->arg_of_redirect = FALSE;
		if (pipe_sequence[check->index] == '>')
			redirect_out_checker(pipe_sequence, check);
		else if (pipe_sequence[check->index] == '<')
			redirect_in_checker(pipe_sequence, check);
		else if (pipe_sequence[check->index] == '|' && check->error == FALSE)
			pipe_content_checker(pipe_sequence, check);
		if (check->error == TRUE)
			return (0);
		check->index = jump_caracters(pipe_sequence, "\"\'<>|", check->index, 1);
		if (check->index != -1)
			quote_jump(pipe_sequence, check);
	}
	return (1);
}
