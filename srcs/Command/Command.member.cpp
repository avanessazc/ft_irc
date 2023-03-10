/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.member.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:39:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/06/21 11:18:44 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

void	Command::main	(void)
{
	(*this->_users_it) = (*this->_users_it);
	this->_is_user = this->_get_user_type();
	this->_parse();
	this->_check_cmd();
}

bool	Command::_get_user_type	(void)
{
	USERS_IT	it	= this->_users.begin(),
				ite	= this->_users.end();
	while (it != ite)
	{
		if (*it == (*this->_users_it))
			return (true);
		it++;
	}
	return (false);
}

void	Command::_parse	(void)
{
	static std::string const	delimiter(" ");
	String &			str = this->_msg;

	this->_cmd.clear();
	for (size_t pos = str.find(delimiter);
		 	pos != String::npos
			&& str[0] != ':';
		 pos = str.find(delimiter))
	{
		if (pos > 0)
			this->_cmd.push_back(str.substr(0, pos));
		this->_msg.erase(0, pos + delimiter.size());
	}
	if (!str.empty())
	{
		if (str[0] == ':')
			this->_cmd.push_back(str.substr(1, str.size()));
		else
			this->_cmd.push_back(str);
	}
	str.clear();
}

void	Command::_check_cmd	(void)
{
	if (!this->_check_prefix()
		|| (!(*this->_users_it)->co_is_complete()
			&& this->_cmd[0] != PASS
			&& this->_cmd[0] != NICK
			&& this->_cmd[0] != USER
			&& this->_cmd[0] != QUIT))
	{
		return ;
	}

	CmdsFct::iterator	it = this->_cmds_fct.find(this->_cmd[0]);

	for (size_t i = 0; i < this->_cmd.size(); i++)
	{
		std::cout	<< this->_cmd[i]
					<< std::endl;
	}

	if (it != this->_cmds_fct.end())
	{
		e_error	error = (this->*(it->second))();
		this->_cmd_error(error);
	}
	else
		this->_err_unknowncommand();
}

bool	Command::_check_prefix	(void)
{
	if (this->_cmd[0][0] == ':')
	{
		String &	first_word = this->_cmd[0];
		String		sub = first_word.substr(1, first_word.size());

		if((*this->_users_it)->get_nickname() != sub)
		{
			this->_cmd_error(ERROR_BAD_PREFIX);
			return (false);
		}
		this->_cmd.erase(this->_cmd.begin());
	}
	return (true);
}

bool	Command::_nick_already_used	(String & nickname) const
{
	USERS_LIST	users = this->_users;

	for (USERS_IT it = users.begin(), ite = users.end(); it != ite; it++)
	{
		if ((*it)->get_nickname() == nickname)
			return (true);
	}
	return (false);
}

bool 	Command::user_exist_in_chan(Channel &chan, String nickname) const
{
	Channel::CHAN_USER_LIST *chan_ulist = NULL;
	chan_ulist = &(chan.get_chan_user_list());
	
    if (chan_ulist && chan_ulist->find(nickname) == chan_ulist->end())
        return (false);
    return (true);
}

bool 	Command::is_operator(String nickname, Channel &chan)
{
	if (user_exist_in_chan(chan, nickname) == true)
	{
		if ((*_users_it)->get_chan_usermode().size() > 0 && ((*_users_it)->get_chan_usermode_vec(chan.get_chan_name()))[USERMODE_o] == true)
			return (true);
		return (false);
	}
	else
		return (false);
}

String	Command::concat_last_args(size_t start_index)
{
	String c_str;
	
	if (start_index < _cmd.size())
	{
		for (CMD::iterator it = _cmd.begin() + start_index; it != _cmd.end(); it++)
		{
			if (it != _cmd.begin() + start_index)
				c_str += " ";
			c_str += *it;
		}
	}
	return (c_str);
}

void Command::leave_all (void)
{
	User::CHAN_USERMODE & chan_usermode = (*_users_it)->get_chan_usermode();

	if (chan_usermode.size() == 0)
		_err_badchanmask();
	else if (chan_usermode.size() > 0)
	{
		size_t	chans_nb	= this->_chans.size() + 2;
		User::CHAN_USERMODE::iterator it = chan_usermode.begin();
		User::CHAN_USERMODE::iterator ite = chan_usermode.end();
		while (it != ite
				&& chans_nb > 0)
		{
			std::cout << "chan_name: " << (*it).first << std::endl;

			_cmd.clear();
			_cmd.push_back("part");
			_cmd.push_back((*it).first);
			_cmd.push_back(":Left");
			_cmd.push_back("all");
			_cmd.push_back("channels");
			_part();
			it = chan_usermode.begin();
			ite = chan_usermode.end();
			chans_nb--;
		}
		if (chans_nb == 0)
		{
			std::cout	<< std::endl
						<< BOLD
						<< "infinity loop in Command::leave_all function."
						<< RESET
						<< std::endl;
		}
	}
}

void Command::update_all_nickname_records(String former_nick, String new_nick)
{
	User* cur_user = _get_user(new_nick);
	for (CHANS_IT it = _chans.begin(), ite = _chans.end(); it != ite; it++)
	{
		Channel* cur_chan = (*it).second;
		Channel::CHAN_USER_LIST *chan_user_list = &(cur_chan->get_chan_user_list());
		Channel::CHAN_INVITE_LIST *chan_invite_list = &(cur_chan->get_chan_invite_list());
		
		Channel::CHAN_USER_LIST::iterator	tmp = chan_user_list->find(former_nick);
		if (tmp != chan_user_list->end())
		{
			chan_user_list->erase(former_nick);
			(*chan_user_list)[new_nick] = cur_user;
		}
		Channel::CHAN_INVITE_LIST::iterator	guest = chan_invite_list->find(former_nick);
		if (guest != chan_invite_list->end())
		{
			chan_invite_list->erase(former_nick);
			(*chan_invite_list)[new_nick] = cur_user;
		}
	}
}
