import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * ServerDemo
 */
public class ServerDemo {
        public static void main(String[] args) throws IOException {
                ServerSocket ss = new ServerSocket(12345);
                System.out.println("server is working!");

                Socket s = ss.accept();
                System.out.println("Client: " + s.getInetAddress().getHostAddress());
                BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
                char[] buf = new char[512];
                int len = br.read(buf);
                System.out.println("Client: " + String.valueOf(buf));

                BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
                bw.write("server receive your infomation\n");
                bw.flush();

                s.close();
                ss.close();
        }

}