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

#include <csignal>

#include "ircserv.hpp"
#include "Socket.hpp"
#include "Server.hpp"
#include "User.hpp"

#include "String.hpp"

int	main	(__attribute((unused)) int argc
			,__attribute((unused)) char ** argv)
{
	try
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
		int	port;
		String	password;

		check_nbr_of_arguments(argc);
		check_port_argument(String(argv[1]));
		check_password_argument(String(argv[2]));
		print_server_name();
		port = atoi(argv[1]);
		password = argv[2];

		Server	serv (password, port);

		serv.main();
	}
	catch (std::exception const & err)
	{
		return (print_error(err.what()));
	}
	return (EXIT_SUCCESS);
}
