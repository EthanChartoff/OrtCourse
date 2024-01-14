module org.example.xo {
    requires javafx.controls;
    requires javafx.fxml;


    opens org.example.xo to javafx.fxml;
    exports org.example.xo;
}