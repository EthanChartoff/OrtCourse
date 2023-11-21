package org.example.xo;

import java.io.*;
import java.net.Socket;

public class Client implements Runnable{

    private Socket socket;
    private Server server;

    public Client(Socket socket, Server server) {
        this.socket = socket;
        this.server = server;
    }

    @Override
    public void run() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
            BufferedWriter out = new BufferedWriter(new OutputStreamWriter(this.socket.getOutputStream()));
            String inLine;

            while((inLine = in.readLine()) != null) {
                this.server.broadcastMsg(inLine, this);
            }

            server.removeClient(this);
            in.close();
            out.close();
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String getClientAddress() {
        return this.socket.getInetAddress().toString();
    }

    public void sendMsg(String msg) {
        System.out.println(msg);
    }
}
