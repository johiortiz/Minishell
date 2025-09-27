/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:06:58 by johyorti          #+#    #+#             */
/*   Updated: 2025/09/26 19:17:19 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

t_list	*lexer(char *line)
{
	t_list		*token;			// aqui se iran guardando cada token encontrado 
	t_state		state;			// memoria del estado del autómata. Guarda el "modo" actual para saber qué reglas aplicar.
	int			i;				// contador para recorrer el string
	int			token_start;	// marca de inicio, cuando empieza a leer una palabra guarda la posicion de i aqui para saber dónde empezó

	
}
