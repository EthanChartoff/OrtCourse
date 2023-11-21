package org.example.xo;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class Main extends Application {
    private Server server;

    @Override
    public void start(Stage stage) throws IOException {
        this.server = new Server();
//        new Thread(server).start();
        FXMLLoader fxmlLoader = new FXMLLoader(Main.class.getResource("intro.fxml"));

        Scene scene = new Scene(fxmlLoader.load(), 320, 240);
        stage.setTitle("XO!");
        stage.setScene(scene);
        stage.setOnCloseRequest(e -> server.stop());
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}