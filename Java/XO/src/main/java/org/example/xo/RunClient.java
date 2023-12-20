package org.example.xo;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class RunClient extends Application {
    private CIntro c;

    @Override
    public void start(Stage stage) throws IOException {
        this.c = new CIntro(stage);
        c.setIntro();
        stage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}