package org.example.xo;

import java.net.Socket;

public class ClientRequest extends Request {

    public ClientRequest(Object request) {
        super(request);
    }

    public static ClientRequest matchFoundRequest(Game g, Socket px, Socket po) {
        return new ClientRequest("Match index="
                                + Server.getGames().indexOf(g)
                                + " found between: (player X) "
                                + px.toString()
                                + " and (player o) "
                                + po.toString());
    }

    public static boolean isFoundRequest(ClientRequest request){
        return request.getRequest().toString().contains("Match found between:");
    }
}
