package A;
import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.animation.Animation;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Circle;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
public class TEST extends Application{
	public void start(Stage pr) {
		Pane pane=new Pane();
		Circle circle=new Circle(200,200,50);
		circle.setStroke(Color.RED);//圆形边框颜色
		circle.setFill(Color.WHITE);//圆形的填充
		pane.getChildren().add(circle);
		HBox hbox=new HBox();
		Button bt1=new Button("left");
		Button bt2=new Button("right");
		Button bt3=new Button("up");
		Button bt4=new Button("down");//上下左右移动的按钮
		hbox.getChildren().addAll(bt1,bt2,bt3,bt4);
		hbox.setAlignment(Pos.CENTER);
		hbox.setSpacing(10);//hbox中元素的间隔
		BorderPane bdpane=new BorderPane();
		bdpane.setLeft(pane);
		bdpane.setBottom(hbox);	
		Scene scene=new Scene(bdpane,400,400);//放入Scene中
		pr.setTitle("Circle");
		pr.setScene(scene);
		pr.show();
		bt1.setOnAction(e->{circle.setCenterX(circle.getCenterX() > 0 ? circle.getCenterX() - 10 : 0);});
		bt2.setOnAction(e->{circle.setCenterX(circle.getCenterX() < scene.getWidth() ? circle.getCenterX() + 10 : 0);});
		bt3.setOnAction(e->{circle.setCenterY(circle.getCenterY() > 0 ? circle.getCenterY() - 10 : 0);});
		bt4.setOnAction(e->{circle.setCenterY(circle.getCenterY() < scene.getHeight() ? circle.getCenterY() + 10 : 0);});
		//给四个按钮设计事件
	}
	public static void main(String[] args) {
		Application.launch(args);
	}
 
}
 
 
