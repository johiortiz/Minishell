/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:54:36 by johyorti          #+#    #+#             */
/*   Updated: 2025/09/28 11:31:04 by johyorti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*line;
	// 1. El bucle infinito que mantiene viva la shell.
	while(1)
	{
		// 2. Leemos la entrada del usuario y mostramos el prompt.
		line = readline("minishell> ");
		if (line == NULL)
		{
			// 3. Gestionamos el caso de Ctrl+D.
			printf("exit\n");	// Bash imprime "exit" en este caso.
			break ;			// Rompemos el bucle para salir.
		}
		// 4. Si la línea no está vacía, la añadimos al historial.
		if (line[0] != '\0')
			add_history(line);

		// -- ZONA DE TRABAJO FUTURA ---
		// 1. lexer(line);
		// 2. parser();
		// 3. expander();
		// 4. executor();
		// -------------------------------
		
		// 5. Liberamos la memoria de la línea leída en esta vuelta. ¡Muy importante!
		free(line);
	}
	return (0);
}