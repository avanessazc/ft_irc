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

#include "Data.hpp"

User *	Data::_get_user	(String nickname) const
{
	size_t	n_user = this->_users.size();
	for (size_t i = 0; i < n_user; i++)
	{
		if (this->_users[i]->get_nickname() == nickname)
			return (this->_users[i]);
	}
	return (NULL);
}
