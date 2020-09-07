package dao;

import domain.User;

public interface IUserDao {
	User find(String UserName,String UserPaw);
	void add(User admin);
}
