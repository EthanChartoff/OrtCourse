package org.example.DB;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class DBConnection {

    // constant params for db connection
    private static final String URL_PATH = "jdbc:postgresql://localhost/eeks-igol";
    private static final String USERNAME = "postgres";
    private static final String PASSWORD = "qdHscF74&";


    public static Connection newConnection() {
        Connection conn = null;
        try {
            conn = DriverManager.getConnection(URL_PATH, USERNAME, PASSWORD);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        System.out.println("[DB] new connection to DB");
        return conn;
    }

    public static void closeConnection(Connection conn) {
        try {
            conn.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        System.out.println("[DB] a connection to the DB has been closed");
    }
}
