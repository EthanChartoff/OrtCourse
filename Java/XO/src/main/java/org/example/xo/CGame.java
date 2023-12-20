package org.example.xo;

import javafx.application.Platform;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CGame {

    @FXML
    private List<ImageView> tiles;

    @FXML
    private Stage root;

    private Game game;

    public CGame(Stage root) {
        this.root = root;
        this.tiles = new ArrayList<>();
    }

    public void waitForGame() {
        try {
            FXMLLoader fxmlLoader = new FXMLLoader(RunClient.class.getResource("looking.fxml"));
            Scene scene = new Scene(fxmlLoader.load());
            this.root.setScene(scene);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void initGame(Game g) {
        Platform.runLater(() -> {
            try {
                FXMLLoader fxmlLoader = new FXMLLoader(RunClient.class.getResource("grid.fxml"));
                Scene scene = new Scene(fxmlLoader.load());
                this.root.setScene(scene);
                this.game = g;
            } catch (IOException e) {
                e.printStackTrace();
                throw new RuntimeException(e);
            }
            // get all children of gridbox
            ((VBox) this.root.getScene().getRoot()).getChildren().filtered(node -> node instanceof HBox)
                    .forEach(hbox -> ((HBox) hbox)
                            .getChildren().filtered(node -> node instanceof BorderPane)
                            .forEach(bpane -> ((BorderPane) bpane)
                                    .getChildren().filtered(node -> node instanceof ImageView)
                                    .forEach(iview -> this.tiles.add((ImageView) iview))));
            this.tiles.forEach(tile -> tile.setOnMouseClicked(
                    mouseEvent ->  g.move(tile, this.tiles.indexOf(tile))));
        });
    }

    public Stage getRoot() {
        return root;
    }

    public void setRoot(Stage root) {
        this.root = root;
    }
}
