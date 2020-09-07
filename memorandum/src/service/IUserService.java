package service;

import domain.User;

public interface IUserService {
	Boolean registerUser(User user);
	User loginUser(String userName,String userPaw);
}
