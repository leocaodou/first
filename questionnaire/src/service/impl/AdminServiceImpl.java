package service.impl;

import domain.Admin;
import service.IAdminService;
import dao.impl.AdminDaoImpl;
import dao.IAdminDao;
public class AdminServiceImpl implements IAdminService {
	private IAdminDao adminDao = new AdminDaoImpl();
	@Override
	public Boolean registerAdmin(Admin admin) {
		if (adminDao.find(admin.getAdminName(),admin.getPassword())==null) {
			adminDao.add(admin);
			return true;
		}
		else
			return false;
	}

	@Override
	public Admin loginAdmin(String adminName, String adminPaw) {
		return adminDao.find(adminName, adminPaw);
	}

}
