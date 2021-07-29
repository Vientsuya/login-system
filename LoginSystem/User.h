#pragma once
#include <string>

class User {
	private:
		std::string nickname;
		std::string login;
		std::string password;
	public:
		User(std::string nn, std::string lg, std::string pwd);

		std::string getNickname() { return nickname; }
		std::string getLogin() { return login; }
		std::string getPassword() { return password; }
};

