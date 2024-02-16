package org.example.xo;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static org.example.xo.Players.PLAYER_O;
import static org.example.xo.Players.PLAYER_X;

public class CGame {

    static public Image x = new Image(new File("src/main/resources/org/example/xo/x.jpeg").toURI().toString());
    static public Image o = new Image(new File("src/main/resources/org/example/xo/o.jpeg").toURI().toString());

    private int move;

    @FXML
    private List<ImageView> tiles;

    @FXML
    private Stage root;

    private Client player;
    private Players type;
    private int currGameHash;

    public CGame(Stage root, Client player, Players type) {
        this.root = root;
        this.player = player;
        this.tiles = new ArrayList<>();
        this.move = 0;
        this.type = type;
    }

    public CGame(Stage root) {
        this(root, null, null);
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

    public void initGame(int hash) {
        this.currGameHash = hash;

        try {
            FXMLLoader fxmlLoader = new FXMLLoader(RunClient.class.getResource("grid.fxml"));
            Scene scene = new Scene(fxmlLoader.load());
            this.root.setScene(scene);
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
                mouseEvent ->  this.move(tile)));
    }

    private void move(ImageView tile) {
        // x turn
        if(type == PLAYER_X && move % 2 == 0) {
            tile.setImage(x);
            player.move(PLAYER_X, this.tiles.indexOf(tile), currGameHash);
            move++;
        }
        // o turn
        else if(type == PLAYER_O && move % 2 == 1) {
            tile.setImage(o);
            player.move(PLAYER_O, this.tiles.indexOf(tile), currGameHash);
            move++;
        }
    }

    public void opponentMove(MoveRequest request) {
        tiles.get(request.getIndex()).setImage(request.getType() == PLAYER_X ? x : o);
        move++;
    }

    public Stage getRoot() {
        return root;
    }

    public void setRoot(Stage root) {
        this.root = root;
    }

    public Client getPlayer() {
        return player;
    }

    public void setPlayer(Client player) {
        this.player = player;
    }

    public Players getType() {
        return type;
    }

    public void setType(Players type) {
        this.type = type;
    }
}
