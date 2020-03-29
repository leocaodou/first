package game;
public class Winningstrategy implements Tactics
{
	private GameObject last = null;
	public GameObject settlewhat()
	{
		return last;
	}
	public void setLast(GameObject x)
	{
		last = x;
	}
}
