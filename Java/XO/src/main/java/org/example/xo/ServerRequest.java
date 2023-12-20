package org.example.xo;

public class ServerRequest extends Request {
    public ServerRequest(Object request) {
        super(request);
    }

    public static ServerRequest searchingMatchRequest(int n, int layers) {
        return new ServerRequest("Searching for Match[n=" + n + ", " + "layers=" + layers + "]");
    }
    public static boolean isSearchingRequest(ServerRequest request) {
        return request.getRequest().toString().contains("Searching for Match");
    }
}
