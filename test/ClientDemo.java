
/**
 * ClientDemo
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

public class ClientDemo {

        public static void main(String[] args) throws IOException {
                Socket s = new Socket("localhost", 12345);

                BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(s.getOutputStream()));
                bw.write("Hello server");
                bw.flush();

                BufferedReader br = new BufferedReader(new  InputStreamReader(s.getInputStream()));
                System.out.println("Server: "+ br.readLine());

                s.close();
        }
}