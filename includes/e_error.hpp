/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_error.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:00:37 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/06 19:44:34 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_ERROR_HPP
# define E_ERROR_HPP

enum e_error
{
	SUCCESS,
	ERROR_CONTINUE,
	ERROR_KILL,
	ERROR_BAD_PASSWD,
	ERROR_PING_REPLY,
	ERROR_PING_TIMEOUT,
	ERROR_REGISTRATION_TIMEOUT,
	ERROR_CLIENT_EXITED,
	ERROR_SERVER_EXITED,
	ERROR_BAD_PREFIX
};

#endif

