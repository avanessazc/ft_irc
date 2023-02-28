/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 17:08:30 by abesombe          #+#    #+#             */
/*   Updated: 2022/06/21 11:14:03 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

e_error	Command::_topic	(void)
{
//	check parameters
	if (this->_cmd.size() < 2)
		return (this->_err_needmoreparams(_cmd[0]));
	if (!has_begin_hashtag(this->_cmd[1]))
		return (this->_err_nosuchchannel(_cmd[1]));
	if (this->_chan_exist(_cmd[1]) == false)
		return (this->_err_nosuchchannel(_cmd[1]));

//	readability variable
				this->_chans_it	= (this->_chans.find(_cmd[1]));
	Channel *	cur_chan		= (*this->_chans_it).second;
	String		cur_chan_name	= cur_chan->get_chan_name();
	String		cur_nickname	= (*_users_it)->get_nickname();

//	check errors
	if (user_exist_in_chan(*cur_chan, cur_nickname) == false)
		return (_err_notonchannel());

//	print topic
	if (this->_cmd.size() == 2)
	{
		bool	is_secret_chan = cur_chan->get_specific_mode(CHANMODE_s);

		if (cur_chan->get_topic().empty())
			return (this->_rpl_notopic());
		else if (!is_secret_chan)
			return (this->_cmd_topic(2));
		return (_err_nosuchchannel(cur_chan->get_chan_name()));
	}

//	set new topic
	bool	is_topic_blocked = cur_chan->get_specific_mode(CHANMODE_t);

	if (!is_operator((*_users_it)->get_nickname(), *cur_chan)
			&& (is_topic_blocked == true))
	{
		return (this->_err_chanoprivsneeded());
	}

//	concatenates the topic as an argument to the command
	String	topic;

	for (std::vector<String>::iterator it = _cmd.begin() + 2, ite = _cmd.end(); it != ite; it++)
	{
		if (it != _cmd.begin() + 2)
			topic = topic + " ";
		topic = topic + *it;
	}
	std::cout	<< "topic: "
				<< topic
				<< std::endl;

//	set topic
	cur_chan->set_topic(topic);
	cur_chan->set_topic_creation_time(time(0));
	cur_chan->set_topic_creator(*_users_it);

	return (this->_cmd_topic(1));
}
