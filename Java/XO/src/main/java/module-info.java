module org.example.xo {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.media;
    requires java.sql;


    opens org.example.xo to javafx.fxml;
    exports org.example.xo;
}