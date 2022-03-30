import java.io.*;
import java.util.*;

public class Q10845 {
    public static void main(String[] args) throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        Queue<Integer> q=new LinkedList<Integer>();

        int n=Integer.parseInt(br.readLine());
        int back=0;

        for(int i=0;i<n;i++){
            String[] s=br.readLine().split(" ");
            /*
            String str=br.readLine();
            String[] s=str.split(" ");
            */

            if(s[0].equals("push")){
                q.add(Integer.parseInt(s[1]));
                back=Integer.parseInt(s[1]);
            }
            else if(s[0].equals("pop")){
                if(q.size()==0){
                    System.out.println("-1");
                }
                else{
                    System.out.println(q.peek());
                    q.remove();
                }
            }
            else if(s[0].equals("size")){
                System.out.println(q.size());
            }
            else if(s[0].equals("empty")){
                if(q.size()==0){
                    System.out.println("1");
                }
                else{
                    System.out.println("0");
                }
            }
            else if(s[0].equals("front")){
                if(q.size()==0){
                    System.out.println("-1");
                }
                else{
                    System.out.println(q.peek());
                }
            }
            else if(s[0].equals("back")){
                if(q.size()==0){
                    System.out.println("-1");
                }
                else{
                    System.out.println(back);       //
                }
            }
        }
    }
}
