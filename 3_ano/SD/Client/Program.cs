using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        // Connect to the server
        TcpClient client = new TcpClient();
        client.Connect(IPAddress.Parse("25.56.196.102"), 8888);

        // Send messages to the server
        while (true)
        {
            Console.Write("Enter a message to send to the server: ");
            string message = Console.ReadLine();

            if (string.IsNullOrWhiteSpace(message))
            {
                break;
            }

            byte[] data = Encoding.ASCII.GetBytes(message);
            NetworkStream stream = client.GetStream();
            stream.Write(data, 0, data.Length);

            // Receive response from the server
            data = new byte[1024];
            int bytesRead = stream.Read(data, 0, data.Length);
            string response = Encoding.ASCII.GetString(data, 0, bytesRead);
            Console.WriteLine("Server response: {0}", response);
        }

        // Close the connection
        client.Close();
    }
}
