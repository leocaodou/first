package domain;

public class Select {
	private int selectID;
	private String selectOrder;
	private int questionID;
	private String selectContent;
	public int getSelectID() {
		return selectID;
	}
	public void setSelectID(int selectID) {
		this.selectID = selectID;
	}
	public int getQuestionID() {
		return questionID;
	}
	public void setQuestionID(int questionID) {
		this.questionID = questionID;
	}
	public String getSelectOrder() {
		return selectOrder;
	}
	public void setSelectOrder(String selectOrder) {
		this.selectOrder = selectOrder;
	}
	public String getSelectContent() {
		return selectContent;
	}
	public void setSelectContent(String selectContent) {
		this.selectContent = selectContent;
	}
}
