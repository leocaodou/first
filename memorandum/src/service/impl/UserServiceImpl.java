package service.impl;

import domain.User;
import service.IUserService;
import dao.impl.UserDaoImpl;
import dao.IUserDao;
public class UserServiceImpl implements IUserService {
	private IUserDao userDao = new UserDaoImpl();
	@Override
	public Boolean registerUser(User user) {
		if (userDao.find(user.getUserName(),user.getPassword())==null) {
			userDao.add(user);
			return true;
		}
		else
			return false;
	}

	@Override
	public User loginUser(String userName, String userPaw) {
		return userDao.find(userName, userPaw);
	}

}
