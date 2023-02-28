/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HistoricalNode.member.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:33:14 by rgeny             #+#    #+#             */
/*   Updated: 2022/04/21 11:48:47 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HistoricalNode.hpp"

bool	HistoricalNode::nickname_is_available	(void) const
{
	time_t	cur_time	= time(NULL);
	time_t	diff_time	= cur_time - this->_timestamp;

	return (diff_time >= NICKNAME_DOWNTIME);
}
