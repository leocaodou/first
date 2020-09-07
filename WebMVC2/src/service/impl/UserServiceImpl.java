package service.impl;

import service.IUserService;
import domain.User;
import dao.IUserDao;
import dao.impl.UserDaoImpl;

public class UserServiceImpl implements IUserService{
	//private UserDaoImpl userDao = new UserDaoImpl();修改前
	private IUserDao userDao = new UserDaoImpl();//修改后

	@Override
	public Boolean registerUser(User user) {
		if (userDao.find(user.getName(),user.getPwd())==null) {
			userDao.add(user);
			return true;
		}
		else
			return false;
	}

	@Override
	public User loginUser(String userName, String userPwd) {
		return userDao.find(userName, userPwd);
	}
}
