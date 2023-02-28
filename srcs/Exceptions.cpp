/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.member.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayzapata <ayzapata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:31:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/07 19:34:43 by ayzapata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"

const char *	wrong_number_of_arguments::what() const throw()
{
	return (ERROR_NBR_OF_ARGS);
}

const char *	wrong_port_argument::what() const throw()
{
	return (ERROR_PORT_ARG);
};

const char *	wrong_password_argument::what() const throw()
{
	return (ERROR_PASSWD_ARG);
};

const char *	error_opening_socket::what() const throw()
{
	return (ERROR_OPEN_SOCKET);
};


const char *	error_accept_failed::what() const throw()
{
	return (ERROR_ACCEPT);
};

const char *	error_recv_failed::what() const throw()
{
	return (ERROR_RECV);
};

const char *	error_send_failed::what() const throw()
{
	return (ERROR_SEND);
};
