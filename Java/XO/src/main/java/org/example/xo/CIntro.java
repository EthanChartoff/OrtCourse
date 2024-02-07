package org.example.xo;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;
import java.net.Socket;
import java.net.URL;
import java.util.ResourceBundle;

public class CIntro implements Initializable {

    @FXML
    private TextField layers;

    @FXML
    private TextField n;

    @FXML
    private Button match_btn;

    @FXML
    private Stage root;

    private Client client;

    private CGame gameController;

    public CIntro(Stage root) {
        this.root = root;
    }

    // on match btn click
    // change view to looking for match view
    // set n and layers to their text area vals
    private void onMatchBtnClick() {
        // change screen to looking
        try {
            // send match request to server
            this.client.sendRequest(ServerRequest.searchingMatchRequest(
                    Integer.parseInt(this.n.textProperty().getValue()),
                    Integer.parseInt(this.layers.textProperty().getValue())
            ).toString());

            this.gameController.waitForGame();
        } catch (NumberFormatException e) {
            System.out.println("[SYSTEM] rows/columns and layers must be not empty to search for a match");
        }
    }

    public void setIntro() throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(RunClient.class.getResource("intro.fxml"));
        fxmlLoader.setController(this);

        Scene scene = new Scene(fxmlLoader.load(), 320, 240);
        this.root.setTitle("XO!");
        this.root.setScene(scene);
        this.root.setOnCloseRequest(windowEvent -> this.client.stop());
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        // make client and game controller, connect them to each other
        this.gameController = new CGame(this.root, null);
        this.client = new Client(this.gameController);
        this.gameController.setPlayer(client);

        new Thread(this.client).start();
        // init widgets
        match_btn.setOnAction(actionEvent -> onMatchBtnClick());
    }
}
