/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_usersdontmatch.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:21:35 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/13 15:22:12 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Message.hpp"

e_error	Message::_err_usersdontmatch	(void) const
{
	String	msg	= this->_set_reply_base (ERR_USERSDONTMATCH)
				+ ":Can't view modes for other users\r\n";
	(*this->_users_it)->add_to_queue(msg);
	return (ERROR_CONTINUE);
}
