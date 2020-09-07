package service;
import domain.Admin;;
public interface IAdminService {
	Boolean registerAdmin(Admin admin);
	Admin loginAdmin(String adminName,String adminPaw);
}
