/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:44:06 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/13 19:11:25 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *s);
char	**ft_split(char *str, char *charset);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *str, int start, int len);

#endif