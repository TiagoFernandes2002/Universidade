using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class TCPServer
{
    static void Main(string[] args)
    {
        try
        {
            // Set the IP address and port number to listen on
            IPAddress localIP = IPAddress.Parse("25.56.175.178"); // listen on all available network interfaces
            int port = 8888;

            // Create a TCP listener socket
            TcpListener listener = new TcpListener(localIP, port);

            // Start listening for incoming connections
            listener.Start();
            Console.WriteLine("Server listening on port " + port);

            while (true)
            {
                // Accept incoming client connections
                TcpClient client = listener.AcceptTcpClient();
                Console.WriteLine("Client connected: " + client.Client.RemoteEndPoint.ToString());

                // Create a network stream to send and receive data
                NetworkStream stream = client.GetStream();

                // Receive the first number from the client
                byte[] data = new byte[1024];
                int bytes = stream.Read(data, 0, data.Length);
                int num1 = int.Parse(Encoding.ASCII.GetString(data, 0, bytes));
                Console.WriteLine("Received first number: " + num1);

                // Send a response back to the client
                string response = "Number Receive Insert other pls";
                data = Encoding.ASCII.GetBytes(response);
                stream.Write(data, 0, data.Length);
                Console.WriteLine("Sent response: " + response);

                // Receive the second number from the client
                bytes = stream.Read(data, 0, data.Length);
                int num2 = int.Parse(Encoding.ASCII.GetString(data, 0, bytes));
                Console.WriteLine("Received second number: " + num2);

                // Calculate the sum of the two numbers
                int sum = num1 + num2;
                Console.WriteLine("Sum: " + sum);

                // Convert the sum to a byte array and send it back to the client
                data = Encoding.ASCII.GetBytes(sum.ToString());
                stream.Write(data, 0, data.Length);

                // Close the client socket and stream
                stream.Close();
                client.Close();
            }
        }
        catch (Exception e)
        {
            Console.WriteLine("Exception: " + e.Message);
        }
    }
}
