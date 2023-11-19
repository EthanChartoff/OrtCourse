package org.example.fx;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.shape.Circle;

public class CircleController {

    @FXML
    private Button c_btn_delarge;

    @FXML
    private Button c_btn_enlarge;

    @FXML
    private Circle c_circle;

    @FXML
    private HBox c_hbox;

    @FXML
    private VBox c_vbox;

    @FXML
    void onDelargeClick(ActionEvent event) {
        c_circle.setRadius(c_circle.getRadius() - 1);
    }

    @FXML
    void onEnlargeClick(ActionEvent event) {
        c_circle.setRadius(c_circle.getRadius() + 1);
    }
}