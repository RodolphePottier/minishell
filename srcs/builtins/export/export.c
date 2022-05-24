/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:18:55 by bsavinel          #+#    #+#             */
/*   Updated: 2022/05/17 10:16:33 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_varr_env(char *name, char *variable, t_lst_env **envp)
{
	t_lst_env	*end;
	t_lst_env	*new;

	new = __ft_calloc_env(sizeof(t_lst_env) * 1);
	new->name = name;
	new->content = ft_strdup_env(variable);
	new->next = NULL;
	if (*envp == NULL)
	{
		*envp = new;
		return (0);
	}
	end = *envp;
	while (end && end->next)
		end = end->next;
	new->prev = end;
	end->next = new;
	return (0);
}

int	put_variable(char *arg, t_lst_env **envp)
{
	char	*name;
	int		i;
	int		len;

	if (!arg || !str_conctent_car(arg, '='))
		return (0);
	len = ft_strlen_stop_car(arg, '=');
	if (len == 0)
		return (1);
	name = __ft_calloc_env(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		name[i] = arg[i];
		i++;
	}
	name[i] = '\0';
	delete_variable(name, envp);
	add_varr_env(name, &arg[len + 1], envp);
	return (0);
}

int	ft_export(int ac, char **arg, t_lst_env **envp)
{
	int	i;
	int	retour;

	i = 1;
	retour = 0;
	while (i < ac)
	{
		if (check_arg_export(arg[i]))
			put_variable(arg[i], envp);
		else
			retour = 1;
		i++;
	}
	return (retour);
}
