/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_specific_char_funct.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:34:27 by rpottier          #+#    #+#             */
/*   Updated: 2022/04/14 14:32:34 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_SPECIFIC_CHAR_FUNCT_H
# define FIND_SPECIFIC_CHAR_FUNCT_H

# include "minishell.h"

/*----- find_specific_char_funct.c -----*/

int	is_logical_op_char(char c);
int	is_and_symbol(char c);
int	is_or_symbol(char c);
int	is_open_parenthesis(char c);
int	is_close_parenthesis(char c);

#endif