using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        //A classe TCPListener implementa os métodos da classe Socket utilizando o protócolo TCP, permitindo uma maior abstração das etapas tipicamente associadas ao Socket.
        TcpListener ServerSocket = new TcpListener(IPAddress.Any, 8888);
        //A chamada ao método "Start" inicia o Socket para ficar à escuta de novas conexões por parte dos clientes
        ServerSocket.Start();

        while (true)
        {//Ciclo infinito para ficar à espera que um cliente Socket/TCP até quando pretender conectar-se

            TcpClient client = ServerSocket.AcceptTcpClient();

            //Só avança para esta parte do código, depois de um cliente ter se conectado ao servidor
            Console.WriteLine("A client has connected!");
            handle_client(client);
        }
    }
    public static void handle_client(TcpClient client)
    {// Neste método, é iniciada a gestão da comunicação do servidor com o cliente

        while (true)
        {   //ciclo infinito de receção de mensagens por parte do cliente, até o cliente ter enviado uma mensagem vazia (só clicou no 'Enter')
            NetworkStream stream = client.GetStream();
            byte[] buffer = new byte[1024];
            int byte_count = stream.Read(buffer, 0, buffer.Length);

            if (byte_count == 0)
            {
                break;
            }

            //Envio da mensagem de confirmação do servidor de volta para o cliente
            string data = Encoding.ASCII.GetString(buffer, 0, byte_count);
            broadcast(client, data);
            Console.WriteLine(data);
        }
        // código para desligar a conexão com o cliente
        client.Client.Shutdown(SocketShutdown.Both);
        client.Close();
    }
    public static void broadcast(TcpClient c, string data)
    {   // Método responsável por enviar uma mensagem de volta (baseado no parâmetro string 'data') para o cliente
        byte[] buffer = Encoding.ASCII.GetBytes(data + " - Server Acknowledgement" + Environment.NewLine);
        NetworkStream stream = c.GetStream();
        stream.Write(buffer, 0, buffer.Length);

    }

}