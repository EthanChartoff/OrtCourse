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
                                + " (player X) "
                                + px.toString()
                                + " (player o) "
                                + po.toString()
                                + "]");


    }

    public static boolean isFoundRequest(ClientRequest request){
        return request.getRequest().toString().contains("Found Match");
    }

    public static ArrayList<Game> readGames(ClientRequest request) {
        List games = new ArrayList<Game>();
        String reqStr = request.toString();

        for (String s : reqStr.substring(1, reqStr.length() - 2).split(",")) {
            String playerXStr = reqStr.substring(reqStr.indexOf("playerX=Connection"));
            Connection playerX = new Connection(new Socket(

            ));
            games.add(new Game(
                    reqStr.charAt(s.indexOf("n=") + "n=".length()) - '0',
                    reqStr.charAt(s.indexOf("layers=") + "layers=".length()) - '0',
                    new Connection(new Socket(
                            Integer.parseInt(reqStr.substring(s.indexOf("n=") + "n=".length()) - '0')
                    )),
                    reqStr.charAt(s.indexOf("n=") + "n=".length()) - '0',
            ))
        }
        return (ArrayList<Game>) o;
    }
}
