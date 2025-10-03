/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 06:26:24 by johyorti          #+#    #+#             */
/*   Updated: 2025/10/03 06:35:07 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

// Contamos cuántas strings hay en un array (terminado en NULL)

static int	count_args(char **args)
{
	int		i;
	
	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}

// Añadimos un nuevo arg a la lista de args de un cmd

void	add_arg_to_cmd(t_simple_cmd *cmd, char *arg)
{
	int			size;
	char	**new_args;
	int				i;

	size = count_args(cmd->args);
	// 1. Reservamos memoria para un nuevo arrary (tamaño anterior + el NULL)
	if (!new_args)
		return ;
	// 2. Copiamos los punteros del array antiguo al nuevo.
	i = 0;
	while (i < size)
	{
		new_args[i] = cmd->args[i];
		i++;
	}
	// 3. Añadimos el nuevo arg (duplicado para seguridad)
	new_args[i] = ft_strdup(arg);
	i++;
	// 4. Cerramos el array con NULL.
	new_args[i] = NULL;
	// 5. Liberamos el array antiguo si existía.
	if (cmd->args)
		free(cmd->args);
	// 6. Actualizamos el puntero para que apunte el nuevo array
	cmd->args = new_args;
}