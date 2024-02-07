package org.example.xo;

public class ClientRequest extends Request {

    public ClientRequest(Object request) {
        super(request);
    }

    public static ClientRequest matchFoundRequest(Game g) {
        return new ClientRequest("Found Match[game="
                                + g.toString()
                                + "]");


    }

    public static boolean isFoundRequest(ClientRequest request) {
        return request.getRequest().toString().contains("Found Match");
    }

    public static ClientRequest moveRequest(Players player, int i) {
        return new ClientRequest(
                "Move[player="
                + player.toString()
                + ", index="
                + i
                + "]"
        );
    }
}
