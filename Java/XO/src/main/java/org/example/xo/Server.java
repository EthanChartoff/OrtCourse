package org.example.xo;

import javafx.application.Platform;
import org.example.DB.GameDB;
import org.example.DB.GameModel;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

public class Server implements Runnable {
    public static final int PORT = 8008;
    public static final String HOST = "localhost";

    public static volatile Map<Integer, Request> requests = new ConcurrentHashMap<>();
    public static volatile Map<Integer, Game> games = new HashMap<>();

    private static Map<Integer, Connection> conns = new HashMap<>();

    static private final GameDB gameDB = new GameDB();

    private ServerSocket serverSocket;


    public Server() {
        try {
            this.serverSocket = new ServerSocket(Server.PORT);
        } catch (IOException e) {
            System.out.println("Error creating server:");
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        Socket clientSocket;
        Connection conn;
        while(true) {
            try {
                clientSocket = this.serverSocket.accept();
                conn = new Connection(clientSocket);
                System.out.println("[SERVER] new connection " + clientSocket.toString());
                conns.put(conn.hashCode(), conn);

                new Thread(conn).start();
            } catch (EOFException e) {
                System.out.println("[SERVER] client closed its conn");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void stop() {
        try {
            serverSocket.close();
            Platform.exit();
            System.exit(0);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    static public void addGameToDB(Game game) {
        gameDB.insert(new GameModel(game));
        gameDB.saveChanges();
        System.out.println(game);
    }

    public static void main(String[] args) {
        new Server().run();
    }
}
