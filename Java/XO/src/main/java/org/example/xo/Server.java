package org.example.xo;

import javafx.application.Platform;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Server implements Runnable {
    private ServerSocket serverSocket;
    private List<Client> clients;

    public Server() {
        try {
            this.serverSocket = new ServerSocket(8008);
        } catch (IOException e) {
            System.out.println("Error creating server");
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        while(true) {
            try {
                Socket clientSocket = this.serverSocket.accept();
                Client client = new Client(clientSocket, this);
                this.clients.add(client);

                new Thread(client).start();
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

    public void broadcastMsg(String msg, Client sender) {
        for(Client c : clients) {
            if(c != sender) {
                c.sendMsg(msg);
            }
        }
    }

    public void removeClient(Client client) {
        clients.remove(client);
    }
}
