/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:34:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/05/17 08:28:43 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include "cmd_exec_utils.h"
# include "find_token_cmd.h"
# include "token_utils.h"
# include "set_up_redirection.h"
# include "count_pipe.h"
# include "exec_builtins.h"
# include "exec_pipe_cmd.h"
# include "exec_pipe_cmd_utils.h"
# include "count_pipe.h"
# include "main_execution.h"
# include "create_argv_cmd.h"
# include "save_fd.h"

void	execute_command_tree(t_btree *root, t_lst_env **env_list);
int		execute_command(t_lst_token *token, t_lst_env **env_list);
int		exec_one_cmd(char **argv, t_lst_env **env_list);
void	print_token_list(t_lst_token *token);
void	exit_code_management(int status);

#endif
