package org.example.xo;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.IOException;
import java.nio.Buffer;

public class CFinish {

    @FXML
    private Stage root;
    @FXML
    private Text finish_txt;

    @FXML
    private Button finish_btn;

    public CFinish(Stage root) {
        this.root = root;
    }

    public Text getFinish_txt() {
        return finish_txt;
    }

    public void setFinish_txt(Text finish_txt) {
        this.finish_txt = finish_txt;
    }

    public Button getFinish_btn() {
        return finish_btn;
    }

    public void setFinish_btn(Button finish_btn) {
        this.finish_btn = finish_btn;
    }

    public void initFinish(PlayerResult result) {
        FXMLLoader fxmlLoader = new FXMLLoader(RunClient.class.getResource("finish.fxml"));
        fxmlLoader.setController(this);

        Scene scene = null;
        try {
            scene = new Scene(fxmlLoader.load());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        this.root.setScene(scene);
        this.finish_txt.setText(result.toString());
        this.finish_btn.setOnAction(actionEvent -> {
            try {
                new CIntro(this.root).setIntro();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        });
    }
}
