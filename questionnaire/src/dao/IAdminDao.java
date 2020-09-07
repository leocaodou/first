package dao;
import domain.Admin;
public interface IAdminDao {
	Admin find(String AdminName,String AdminPaw);
	void add(Admin admin);
}
