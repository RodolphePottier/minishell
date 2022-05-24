/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_sigint.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:36:45 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/13 13:24:58 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_SIGINT_H
# define SIGNAL_SIGINT_H

# include "minishell.h"

void	handler_sigint_empty(int sig);
void	handler_sigint_prompt(int sig);
void	handler_sigint_heredoc(int sig);

#endif