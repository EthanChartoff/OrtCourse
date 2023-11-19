package org.example.fx;

import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class PushMeController {
    @FXML
    private Label welcomeText;

    private int counter;


    @FXML
    protected void onHelloButtonClick() {
        welcomeText.setText("counter: " + ++counter);
    }
}