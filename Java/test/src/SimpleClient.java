import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

public class SimpleClient {

    public static void main(String[] args) {
        String serverAddress = "localhost";
        int serverPort = 12345;

        try {
            // Create a socket and connect to the server
            Socket socket = new Socket(serverAddress, serverPort);
            System.out.println("Connected to server: " + serverAddress + ":" + serverPort);

            // Get the input and output streams from the socket
            InputStream inputStream = socket.getInputStream();
            OutputStream outputStream = socket.getOutputStream();

            // Send data to the server
            String sendData = "Hello from client!";
            outputStream.write(sendData.getBytes());

            // Read the response from the server
            byte[] buffer = new byte[1024];
            int bytesRead = inputStream.read(buffer);
            String serverResponse = new String(buffer, 0, bytesRead);
            System.out.println("Received from server: " + serverResponse);

            // Close the streams and socket
            inputStream.close();
            outputStream.close();
            socket.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
