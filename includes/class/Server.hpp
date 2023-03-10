/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:53:38 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/21 14:23:23 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP
# define TIME_TO_CONNECT 60
# define TIME_FOR_PING 60
# define TIME_TO_PONG 60

# include <iostream>
# include <string>
# include <vector>
# include "Command.hpp"

class Server
	:virtual private Socket
	,virtual private Command
{
	public:
		Server	(String	password
				,SOCKET port = PORT);
		~Server	(void);

		Server &	operator=	(Server & src);

		void	main			(void);

	private:
		fd_set					_rfds;
		fd_set					_wfds;

		Server	(Server & src);

		void	_init_fds			(void);
		void	_check_fds			(void);
		void	_new_user			(void);
		void	_del_user			(void);
		bool	_check_tmp_user		(void);
		void	_read_user_msg		(void);
		void	_ping_user			(void);
};

std::ostream &	operator<<	(std::ostream & os
							,Server & src);
#endif

