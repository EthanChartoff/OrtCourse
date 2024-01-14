package org.example.xo;

import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class ClientRequest extends Request {

    public ClientRequest(Object request) {
        super(request);
    }

    public static ClientRequest matchFoundRequest(Game g, Socket px, Socket po) {
        return new ClientRequest("Found Match[index="
                                + Server.games.indexOf(g)
                                + " playerX="
                                + px.toString()
                                + " playerO="
                                + po.toString()
                                + "]");


    }

    public static boolean isFoundRequest(ClientRequest request){
        return request.getRequest().toString().contains("Found Match");
    }

//    public static ArrayList<Game> readGame(ClientRequest request) {
//
//        return (ArrayList<Game>) o;
//    }
}
