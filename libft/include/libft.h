/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:44:06 by plepercq          #+#    #+#             */
/*   Updated: 2026/03/17 15:31:37 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

int		ft_atoi(const char *s);
char	**ft_split(char *str, char *charset);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *str, int start, int len);

/*	FT_PRINTF	*/
int		ft_printf(const char *s, ...);
int		check_base(char *base);
int		w_char(char c);
int		w_str(char *str);
int		w_nbr_base(long nb, char *base);
int		w_unbr_base(unsigned long nb, char *base);
int		w_ptr_adress(unsigned long ptr);


#endif