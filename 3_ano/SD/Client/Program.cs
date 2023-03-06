using System;
using System.Net;
using System.Net.Sockets;

class TcpClientExample
{
    static void Main(string[] args)
    {
        // Set the server's IP address and port
        string serverIP = "25.57.70.173"; // localhost
        int serverPort = 8888;

        // Create a TCP client socket and connect to the server
        TcpClient client = new TcpClient();
        client.Connect(IPAddress.Parse(serverIP), serverPort);

        // Get a network stream object for reading and writing data
        NetworkStream stream = client.GetStream();

        // Send a message to the server
        string message = "Hello, server!";
        byte[] messageBytes = System.Text.Encoding.ASCII.GetBytes(message);
        stream.Write(messageBytes, 0, messageBytes.Length);

        // Receive a response from the server
        byte[] buffer = new byte[1024];
        int bytesRead = stream.Read(buffer, 0, buffer.Length);
        string response = System.Text.Encoding.ASCII.GetString(buffer, 0, bytesRead);

        Console.WriteLine("Server response: " + response);

        // Close the client socket and stream objects
        stream.Close();
        client.Close();
    }
}
