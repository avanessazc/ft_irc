/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpl_welcome.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:37:10 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/06 11:11:07 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_rpl_welcome	(void) const
{
	User &	cur_user	= *(*this->_users_it);
	String	msg	= this->_set_reply_base(RPL_WELCOME)
				+ "Welcome to the Internet Relay Network "
				+ cur_user.get_nickname()
				+ "!"
				+ cur_user.get_username()
				+ "@"
				+ cur_user.get_host()
				+ "\r\n";
	cur_user.add_to_queue(msg);
	return (SUCCESS);
}
