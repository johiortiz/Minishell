/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 00:23:05 by johyorti          #+#    #+#             */
/*   Updated: 2025/09/28 00:29:24 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

// Recibe la lista, el valor y el tipo, y se encarga de todo.
void	create_and_add_token(t_list **tokens, char *value, t_tokentype type)
{
	t_token	*new_token;

	// 1. Reservamos memoria para la estructura del token
	new_token = malloc(sizeof(t_token));
	if (!new_token)
		return;		// en TEORÍA debería haber un manejo de error robusto
	//2. Asignamos el valor y el tipo
	// ft_strdup para hacer una copia del 'value' y evitar problemas con 
	// punteros, si se encuentra algo mejor la adaptamos.
	new_token->value = ft_strdup(value);
	new_token->type = type;
	// 3. Añadimos el nuevo token al final de la lista.
	ft_lstadd_back(tokens, ft_lstnew(new_token));
}