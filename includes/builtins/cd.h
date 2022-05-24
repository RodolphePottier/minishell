/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:34:20 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 10:17:52 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

# include "minishell.h"

int	ft_cd_absolu_path(char *path_move, t_lst_env **envp);
/*int	no_dir(char *path_move);
int	ft_cd_relative_path(char *path_move, t_lst_env **envp);
int	ft_cd_movedir(char *path_move, t_lst_env **envp);*/
int	ft_cd(int ac, char **argv, t_lst_env **envp);

#endif