module org.example.fxdemo {
    requires javafx.controls;
    requires javafx.fxml;


    opens org.example.fxdemo to javafx.fxml;
    exports org.example.fxdemo;
}