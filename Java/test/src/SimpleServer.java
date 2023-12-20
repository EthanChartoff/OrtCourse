import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class SimpleServer {

    public static void main(String[] args) {
        int port = 12345;

        try {
            // Create a server socket
            ServerSocket serverSocket = new ServerSocket(port);
            System.out.println("Server is listening on port " + port);

            // Wait for a client to connect
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected from: " + clientSocket.getInetAddress());

            // Get the input and output streams from the socket
            InputStream inputStream = clientSocket.getInputStream();
            OutputStream outputStream = clientSocket.getOutputStream();

            // Read data from the client
            byte[] buffer = new byte[1024];
            int bytesRead = inputStream.read(buffer);
            String clientData = new String(buffer, 0, bytesRead);
            System.out.println("Received from client: " + clientData);

            // Send a response to the client
            String responseData = "Hello from server!";
            outputStream.write(responseData.getBytes());

            // Close the streams and sockets
            inputStream.close();
            outputStream.close();
            clientSocket.close();
            serverSocket.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
