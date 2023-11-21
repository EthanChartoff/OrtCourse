package org.example.xo;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextField;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.URL;
import java.util.ResourceBundle;

public class CIntro implements Initializable {

    @FXML
    private TextField layers;

    @FXML
    private TextField n;

    private Server server;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        server = new Server();
    }
}
