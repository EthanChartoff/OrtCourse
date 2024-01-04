package org.example.xo;

import javafx.application.Platform;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;
import java.util.concurrent.ConcurrentHashMap;

public class Server implements Runnable {
    public static final int PORT = 8008;
    public static final String HOST = "localhost";

    public static volatile Map<Integer, Request> requests = new HashMap<>();
    public static volatile List<Game> games = new ArrayList<>();

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
        while(true) {
            try {
                clientSocket = this.serverSocket.accept();
                System.out.println("[SERVER] new connection " + clientSocket.toString());

                new Thread(new Connection(clientSocket)).start();
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

    public static void main(String[] args) {
        new Server().run();
    }
}
