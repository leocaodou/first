package calculator;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.geometry.HPos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;
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
		fpane.getChildren().add(new Label("Number1"));
		fpane.getChildren().add(Number1);
		fpane.getChildren().add(new Label("Number2"));
		fpane.getChildren().add(Number2);
		fpane.getChildren().add(new Label("Result"));
		fpane.getChildren().add(Result);
		fpane.getChildren().add(btAdd);
		fpane.getChildren().add(btSubtract);
		fpane.getChildren().add(btMultiply);
		fpane.getChildren().add(btDivide);
		btAdd.setAlignment(Pos.CENTER);
		Scene scene = new Scene(fpane,650,100);
		ps.setTitle("Calcuator");
		ps.setScene(scene);
		ps.show();
	}
	public static void main(String[] args) {
		launch(args);
	}

}
