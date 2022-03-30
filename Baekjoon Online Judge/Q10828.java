import java.io.*;
import java.util.Stack;

public class Q10828 {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

        Stack<Integer> s=new Stack<Integer>();

        int num=Integer.parseInt(br.readLine());

        for(int i=0;i<num;i++){
            String[] str=br.readLine().split(" ");

            if(str[0].equals("push")){
                s.push((Integer.parseInt(str[1])));
            }
            else if(str[0].equals("pop")){
                if(s.empty()){
                    bw.write("-1\n");
                }
                else{
                    bw.write(s.pop()+"\n");
                }
            }
            else if(str[0].equals("size")){
                bw.write(s.size()+"\n");
            }
            else if(str[0].equals("empty")){
                if(s.empty()){
                    bw.write("1"+"\n");
                }
                else{
                    bw.write("0"+"\n");
                }
            }
            else if(str[0].equals("top")){
                if(s.empty()){
                    bw.write("-1"+"\n");
                }
                else{
                    bw.write(s.peek()+"\n");
                }
            }
        }
        bw.flush();
        bw.close();
    }
}