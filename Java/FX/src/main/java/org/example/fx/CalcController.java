package org.example.fx;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.util.converter.NumberStringConverter;

import java.lang.reflect.Array;
import java.text.NumberFormat;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;

public class CalcController {

    private enum ops {
        ADD,
        SUB,
        MUL,
        DIV
    }

    private Calculator calc;

    @FXML
    private TextField number_field;

    @FXML
    private ComboBox<String> op_cbox;

    @FXML
    private Label result_label;

    @FXML
    private Button btn;

    @FXML
    public void initialize() {
        calc = new Calculator();

        this.result_label.textProperty().bindBidirectional(
                calc.resultProperty(), NumberFormat.getNumberInstance());
        this.number_field.textProperty().bindBidirectional(
                calc.numProperty(), new NumberStringConverter());

        this.op_cbox.setOnAction(actionEvent -> onCBoxSelect(actionEvent));
        this.op_cbox.getItems().addAll(
                ops.ADD.toString(),
                ops.SUB.toString(),
                ops.MUL.toString(),
                ops.DIV.toString()
        );

        this.btn.setOnAction(actionEvent -> onBtnSelect(actionEvent));
    }

    private void onBtnSelect(ActionEvent actionEvent) {
        switch (this.op_cbox.getValue()) {
            case "ADD" -> calc.addition();
            case "SUB" -> calc.subtraction();
            case "MUL" -> calc.multiplication();
            case "DIV" -> calc.division();
            default -> throw new IllegalStateException("Unexpected value: " + this.op_cbox.getValue());
        }
        System.out.println(this.calc.getNum());
    }

    private void onCBoxSelect(ActionEvent actionEvent) {
        String str = this.op_cbox.getValue().toString();
    }


}
