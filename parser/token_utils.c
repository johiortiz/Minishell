/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 00:23:05 by johyorti          #+#    #+#             */
/*   Updated: 2025/09/28 11:26:38 by johyorti         ###   ########.fr       */
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

// Esta función recibe el input, un inicio y un fin.
void	add_word_token(t_list **tokens, const char *input, int start, int end)
{
	char		*value;
	t_token		*new_token;

	// 1, "Cortamos" el string del input para crear el valor del token.
	value = ft_substr(input, start, end - start);
	if (!value)
		return ;
	// 2. Creamos la estructura del token.
	new_token = malloc(sizeof(t_token));
	if (!new_token)
	{
		free(value);
		return ;
	}
	// 3. Asignamos el valor y, por ahora, el tipo por defecto WORD.
	new_token->value = value;
	new_token->type = TOKEN_WORD;
	// 4. Añadimos el nuevo token a la lista.
	ft_lstadd_back(tokens, ft_lstnew(new_token));
}