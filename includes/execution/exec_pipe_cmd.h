/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe_cmd.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:13:04 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 08:50:36 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_PIPE_CMD_H
# define EXEC_PIPE_CMD_H

# include "minishell.h"

void	exec_cmd(t_lst_token *token, t_lst_env **env_list);
int		exec_pipe_cmd(t_lst_token *token, t_lst_env **env_list, int nb_cmd);
void	end_pipe_execution(int pid, int pipe_stock[2]);
void	dup_std_fileno(int pipe_stock[2], int new_pipe[2], int nb_cmd, int i);

#endif