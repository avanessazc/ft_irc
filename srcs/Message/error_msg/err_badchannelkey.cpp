/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_badchannelkey.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:30:51 by abesombe          #+#    #+#             */
/*   Updated: 2022/05/12 14:07:37 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_badchannelkey	(void) const
{
	String	msg	= this->_set_reply_base (ERR_BADCHANNELKEY)
				+ _cmd[1] + " :Cannot join channel (incorrect channel key)\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}

