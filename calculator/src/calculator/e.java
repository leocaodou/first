package calculator;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.HBox;
public class e extends Application {
	private TextField Number1 = new TextField();
	private TextField Number2 = new TextField();
	private TextField Result = new TextField();
	private Button btAdd = new Button("Add");
	private Button btSubtract = new Button("Subtract");
	private Button btMultiply = new Button("Multiply");
	private Button btDivide = new Button("Divide");
	
	public void start(Stage ps){
		FlowPane fpane = new FlowPane();
		BorderPane bpane = new BorderPane();
		HBox hbox = new HBox();
		fpane.getChildren().add(new Label("Number1"));
		fpane.getChildren().add(Number1);
		fpane.getChildren().add(new Label("Number2"));
		fpane.getChildren().add(Number2);
		fpane.getChildren().add(new Label("Result"));
		fpane.getChildren().add(Result);
		hbox.getChildren().addAll(btAdd,btSubtract,btMultiply,btDivide);
		hbox.setAlignment(Pos.CENTER);
		hbox.setSpacing(10);
		bpane.setTop(fpane);
		bpane.setBottom(hbox);
		btAdd.setOnAction(e->calculateAdd());
		btSubtract.setOnAction(e->calculateSubtract());
		btMultiply.setOnAction(e->calculateMultiply());
		btDivide.setOnAction(e->calculateDivide());
		Scene scene = new Scene(bpane,650,50);
		ps.setTitle("Calcuator");
		ps.setScene(scene);
		ps.show();
	}
	private void calculateAdd()
	{
		double n1 = Double.parseDouble(Number1.getText());
		double n2 = Double.parseDouble(Number2.getText());
		Result.setText(String.format("%.2f", n1 + n2));
	}
	private void calculateSubtract()
	{
		double n1 = Double.parseDouble(Number1.getText());
		double n2 = Double.parseDouble(Number2.getText());
		Result.setText(String.format("%.2f", n1 - n2));
	}
	private void calculateMultiply()
	{
		double n1 = Double.parseDouble(Number1.getText());
		double n2 = Double.parseDouble(Number2.getText());
		Result.setText(String.format("%.2f", n1 * n2));
	}
	private void calculateDivide()
	{
		double n1 = Double.parseDouble(Number1.getText());
		double n2 = Double.parseDouble(Number2.getText());
		Result.setText(String.format("%.2f", n1 / n2));
	}
	public static void main(String[] args) {
		launch(args);
	}

}
