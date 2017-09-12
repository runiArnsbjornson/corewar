/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yewen <yewen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:23:38 by yewen             #+#    #+#             */
/*   Updated: 2017/08/21 22:16:02 by abnaceur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*parse_prog_name(t_asm *a)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(NAME_CMD_STRING);
	if (ft_strncmp(a->lines[0], NAME_CMD_STRING, len))
		return ("Champion name syntax error");
	ptr = a->lines[0] + len;
	while (FT_ISSPACE(*ptr))
		++ptr;
	if (*ptr == '\0')
		return ("Cannot find champion name");
	len = ft_strlen(ptr);
	if (len - 2 > PROG_NAME_LENGTH)
		return ("Champion name is too long");
	if (ptr[0] != '"' || ptr[len - 1] != '"')
		return ("Champion name syntax error");
	ft_strncpy(a->header->prog_name, ptr + 1, len - 2);
	return (NULL);
}

static char	*parse_header_comment(t_asm *a)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(COMMENT_CMD_STRING);
	if (ft_strncmp(a->lines[1], COMMENT_CMD_STRING, len))
		return ("Champion comment syntax error");
	ptr = a->lines[1] + len;
	while (FT_ISSPACE(*ptr))
		++ptr;
	if (*ptr == '\0')
		return ("Cannot find champion comment");
	len = ft_strlen(ptr);
	if (len - 2 > COMMENT_LENGTH)
		return ("Champion comment is too long");
	if (ptr[0] != '"' || ptr[len - 1] != '"')
		return ("Champion comment syntax error");
	ft_strncpy(a->header->comment, ptr + 1, len - 2);
	return (NULL);
}

char		*parse_header(t_asm *a)
{
	char	*err_msg;

	if (!(a->header = ft_memalloc(sizeof(t_header))))
		return ("Malloc error");
	if ((err_msg = parse_prog_name(a)))
		return (err_msg);
	if ((err_msg = parse_header_comment(a)))
		return (err_msg);
	return (NULL);
}
